#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100 

typedef struct {
    int arr[MAX_SIZE];   
    int front[MAX_SIZE];
    int rear[MAX_SIZE];  
    int next[MAX_SIZE]; 
    int free;            
    int k;             
    int n;               
} kQueues;

void initKQueues(kQueues *qs, int k, int n) {
    qs->k = k;
    qs->n = n;
    qs->free = 0;

    for (int i = 0; i < k; i++) {
        qs->front[i] = -1;
        qs->rear[i] = -1;  
    }

    for (int i = 0; i < n - 1; i++) {
        qs->next[i] = i + 1; 
    }
    qs->next[n - 1] = -1; 
}

bool isEmpty(kQueues *qs, int qn) {
    return qs->front[qn] == -1;
}

void enqueue(kQueues *qs, int x, int qn) {
    if (qs->free == -1) {
        printf("Queue overflow\n");
        return;
    }

    int i = qs->free; 
    qs->free = qs->next[i]; 

    if (qs->front[qn] == -1) {
        qs->front[qn] = i; 
    } else {
        qs->next[qs->rear[qn]] = i;
    }

    qs->next[i] = -1; 
    qs->rear[qn] = i; 
    qs->arr[i] = x;   
}

int dequeue(kQueues *qs, int qn) {
    if (isEmpty(qs, qn)) {
        printf("Queue underflow\n");
        return -1;
    }

    int i = qs->front[qn]; 
    qs->front[qn] = qs->next[i]; 

    if (qs->front[qn] == -1) {
        qs->rear[qn] = -1; 
    }

    qs->next[i] = qs->free; 
    qs->free = i;

    return qs->arr[i];
}

void displayq(kQueues *qs, int qn) {
    if (isEmpty(qs, qn)) {
        printf("Queue %d is empty\n", qn);
        return;
    }

    int i = qs->front[qn];
    printf("Queue %d: ", qn);
    while (i != -1) {
        printf("%d ", qs->arr[i]);
        i = qs->next[i];
    }
    printf("\n");
}

void displayAll(kQueues *qs) {
    for (int i = 0; i < qs->k; i++) {
        displayq(qs, i);
    }
}

int main() {
    int k, n;
    printf("Enter the number of queues (k): ");
    scanf("%d", &k);
    printf("Enter the maximum number of elements (n): ");
    scanf("%d", &n);

    kQueues qs;
    initKQueues(&qs, k, n);

    int choice, value, queueNumber;

    while (1) {
        printf("1. Enqueue\n2. Dequeue\n3. Display All Queues\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the queue number (0 to %d): ", k - 1);
                scanf("%d", &queueNumber);
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                enqueue(&qs, value, queueNumber);
                break;
            case 2:
                printf("Enter the queue number (0 to %d): ", k - 1);
                scanf("%d", &queueNumber);
                printf("Dequeued from queue %d: %d\n", queueNumber, dequeue(&qs, queueNumber));
                break;
            case 3:
                displayAll(&qs);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}