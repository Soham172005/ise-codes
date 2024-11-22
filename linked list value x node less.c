#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int val;
    struct ListNode *next;
} ListNode;

ListNode* createNode(int val) {
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

void appendNode(ListNode** head, int val) {
    ListNode* newNode = createNode(val);
    if (*head == NULL) {
        *head = newNode;
    } else {
        ListNode* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

ListNode* partition(ListNode* head, int x) {
    ListNode *lessHead = NULL, *greaterHead = NULL;
    ListNode *less = NULL, *greater = NULL;

    while (head != NULL) {
        if (head->val < x) {
            if (less == NULL) {
                lessHead = head;
                less = lessHead;
            } else {
                less->next = head;
                less = less->next;
            }
        } else {
            if (greater == NULL) {
                greaterHead = head;
                greater = greaterHead;
            } else {
                greater->next = head;
                greater = greater->next;
            }
        }
        head = head->next;
    }

    if (less != NULL) less->next = NULL;
    if (greater != NULL) greater->next = NULL;

    if (lessHead == NULL) {
        return greaterHead;  
    }

    less->next = greaterHead;

    return lessHead;
}

void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp != NULL) {
        printf("%d", temp->val);
        if (temp->next != NULL) {
            printf(" -> ");
        }
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    ListNode* head = NULL;
    int n, val, x;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &val);
        appendNode(&head, val);
    }

    printf("Enter the partition value x: ");
    scanf("%d", &x);

    printf("Original List: ");
    printList(head);

    ListNode* partitionedHead = partition(head, x);

    printf("Partitioned List: ");
    printList(partitionedHead);

    return 0;
}
