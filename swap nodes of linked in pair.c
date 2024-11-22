#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void append(struct Node** head_ref, int new_data) {
    struct Node* newNode = createNode(new_data);
    if (*head_ref == NULL) {
        *head_ref = newNode;
        return;
    }
    struct Node* last = *head_ref;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = newNode;
}

struct Node* swapPairs(struct Node* head) {
    if (head == NULL || head->next == NULL)
        return head;

    struct Node* current = head;
    struct Node* newHead = head->next; 

    while (current != NULL && current->next != NULL) {
        struct Node* temp = current->next->next; 
        current->next->next = current;            
        if (temp == NULL || temp->next == NULL) {
            current->next = temp;
            break;
        }
        current->next = temp->next; 
        current = temp;           
    }

    return newHead;
}

void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int n, data;

    printf("Enter the number of elements in the linked list: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        append(&head, data);
    }

    printf("Original linked list:\n");
    printList(head);

    head = swapPairs(head);

    printf("Linked list after swapping nodes in pairs:\n");
    printList(head);

    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}