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

ListNode* reverseList(ListNode* head) {
    ListNode* prev = NULL;
    ListNode* curr = head;
    ListNode* next = NULL;
    
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    l1 = reverseList(l1); 
    l2 = reverseList(l2);
    
    ListNode* result = NULL; 
    ListNode* temp = NULL;
    int carry = 0;
    
    while (l1 != NULL || l2 != NULL || carry != 0) {
        int sum = carry;
        
        if (l1 != NULL) {
            sum += l1->val;
            l1 = l1->next;
        }
        
        if (l2 != NULL) {
            sum += l2->val;
            l2 = l2->next;
        }
        
        carry = sum / 10;
        
        if (result == NULL) {
            result = createNode(sum % 10);
            temp = result;
        } else {
            temp->next = createNode(sum % 10);
            temp = temp->next;
        }
    }
    
    return reverseList(result);
}

void printList(ListNode* head) {
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

ListNode* addNumberToList() {
    ListNode* head = NULL;
    ListNode* temp = NULL;
    int num;

    printf("Enter the digits of the number one by one (enter -1 to stop):\n");
    while (1) {
        scanf("%d", &num);
        if (num == -1) {
            break;
        }
        ListNode* newNode = createNode(num);
        if (head == NULL) {
            head = newNode;
        } else {
            temp->next = newNode;
        }
        temp = newNode;
    }
    return head;
}

int main() {
    printf("Input for the first operand:\n");
    ListNode* operand_1 = addNumberToList(); 
    
    printf("Input for the second operand:\n");
    ListNode* operand_2 = addNumberToList();
    
    ListNode* result = addTwoNumbers(operand_1, operand_2);
    
    printf("Result: ");
    printList(result);
    
    return 0;
}