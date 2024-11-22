#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

struct Node* concatenateLists(struct Node* head1, struct Node* head2) {
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;

    struct Node* temp = head1;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = head2;
    head2->prev = temp;

    return head1;
}

void displayList(struct Node* head) {
    struct Node* temp = head;
    printf("Doubly Linked List: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;
    int choice, data;

    while (1) {
        printf("\nDoubly Linked List Menu:\n");
        printf("1. Insert at end (List 1)\n");
        printf("2. Insert at end (List 2)\n");
        printf("3. Concatenate lists\n");
        printf("4. Display List 1\n");
        printf("5. Display List 2\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at end of List 1: ");
                scanf("%d", &data);
                insertAtEnd(&head1, data);
                break;
            case 2:
                printf("Enter data to insert at end of List 2: ");
                scanf("%d", &data);
                insertAtEnd(&head2, data);
                break;
            case 3:
                head1 = concatenateLists(head1, head2);
                head2 = NULL;
                printf("Lists concatenated.\n");
                break;
            case 4:
                printf("List 1: ");
                displayList(head1);
                break;
            case 5:
                printf("List 2: ");
                displayList(head2);
                break;
            case 6:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}