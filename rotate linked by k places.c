#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int val;
    struct ListNode* next;
} ListNode;

ListNode* createNode(int value) {
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->val = value;
    newNode->next = NULL;
    return newNode;
}

void printList(ListNode* head) {
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

int getListLength(ListNode* head) {
    int length = 0;
    ListNode* temp = head;
    while (temp != NULL) {
        length++;
        temp = temp->next;
    }
    return length;
}

ListNode* rotateList(ListNode* head, int k) {
    if (head == NULL || head->next == NULL || k == 0) {
        return head;
    }

    int length = getListLength(head);
    k = k % length; 

    if (k == 0) {
        return head;
    }

    ListNode* temp = head;
    
    for (int i = 1; i < length - k; i++) {
        temp = temp->next;
    }

    ListNode* newHead = temp->next; 
    temp->next = NULL; 

    ListNode* lastNode = newHead;
    while (lastNode->next != NULL) {
        lastNode = lastNode->next;
    }
    lastNode->next = head;

    return newHead;
}

ListNode* addNumberToList(int num) {
    ListNode* head = NULL;
    ListNode* temp = NULL;

    if (num == 0) {
        return createNode(0);
    }

    while (num > 0) {
        ListNode* newNode = createNode(num % 10);
        if (head == NULL) {
            head = newNode;
        } else {
            temp->next = newNode;
        }
        temp = newNode;
        num /= 10;
    }
    return head;
}

int main() {
    ListNode* head = addNumberToList(12345); 
    
    int k = 2;
    printf("Original List: ");
    printList(head);
    
    head = rotateList(head, k);
    
    printf("Rotated List by %d places: ", k);
    printList(head);
    
    return 0;
}