#include <stdio.h>
#include <stdlib.h>

#define MAX 50          
#define NUM_QUEUES 3   

typedef struct {
    int arr[MAX];            
    int front[NUM_QUEUES];   
    int rear[NUM_QUEUES];    
    int size;               
} MultiQueue;

void initializeMultiQueue(MultiQueue *mq, int numQueues, int size) {
    mq->size = size;
    for (int i = 0; i < numQueues; i++) {
        mq->front[i] = i * size;   
        mq->rear[i] = i * size - 1; 
    }
}

int isFull(MultiQueue *mq, int queueNum) {
    int end = (queueNum + 1) * mq->size;
    return mq->rear[queueNum] == end - 1;
}

int isEmpty(MultiQueue *mq, int queueNum) {
    return mq->rear[queueNum] < mq->front[queueNum];
}

void enqueue(MultiQueue *mq, int queueNum, int value) {
    if (isFull(mq, queueNum)) {
        printf("Queue %d is full. Cannot enqueue %d.\n", queueNum, value);
        return;
    }
    mq->rear[queueNum]++;
    mq->arr[mq->rear[queueNum]] = value;
    printf("Enqueued %d to Queue %d\n", value, queueNum);
}

int dequeue(MultiQueue *mq, int queueNum) {
    if (isEmpty(mq, queueNum)) {
        printf("Queue %d is empty. Cannot dequeue.\n", queueNum);
        return -1;
    }
    int value = mq->arr[mq->front[queueNum]];
    mq->front[queueNum]++;
    return value;
}

void display(MultiQueue *mq, int queueNum) {
    if (isEmpty(mq, queueNum)) {
        printf("Queue %d is empty.\n", queueNum);
        return;
    }
    printf("Queue %d: ", queueNum);
    for (int i = mq->front[queueNum]; i <= mq->rear[queueNum]; i++) {
        printf("%d ", mq->arr[i]);
    }
    printf("\n");
}

int main() {
    MultiQueue mq;
    initializeMultiQueue(&mq, NUM_QUEUES, MAX / NUM_QUEUES);

    int choice, queueNum, value;

    while (1) {
        printf("\nMulti-Queue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter queue number (0 to %d): ", NUM_QUEUES - 1);
                scanf("%d", &queueNum);
                if (queueNum < 0 || queueNum >= NUM_QUEUES) {
                    printf("Invalid queue number!\n");
                    break;
                }
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(&mq, queueNum, value);
                break;

            case 2:
                printf("Enter queue number (0 to %d): ", NUM_QUEUES - 1);
                scanf("%d", &queueNum);
                if (queueNum < 0 || queueNum >= NUM_QUEUES) {
                    printf("Invalid queue number!\n");
                    break;
                }
                value = dequeue(&mq, queueNum);
                if (value != -1) {
                    printf("Dequeued from Queue %d: %d\n", queueNum, value);
                }
                break;

            case 3:
                printf("Enter queue number (0 to %d): ", NUM_QUEUES - 1);
                scanf("%d", &queueNum);
                if (queueNum < 0 || queueNum >= NUM_QUEUES) {
                    printf("Invalid queue number!\n");
                    break;
                }
                display(&mq, queueNum);
                break;

            case 4:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}