#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL)
        return newNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}

struct Node* findPredecessor(struct Node* root, struct Node* node) {
    if (node->left != NULL) {
        struct Node* temp = node->left;
        while (temp->right != NULL)
            temp = temp->right;
        return temp;
    }

    struct Node* predecessor = NULL;
    while (root != NULL) {
        if (node->data < root->data) {
            root = root->left;
        } else if (node->data > root->data) {
            predecessor = root;
            root = root->right;
        } else {
            break;
        }
    }

    return predecessor;
}

int main() {
    struct Node* root = NULL;
    int value, n;

    printf("Enter the number of nodes to insert: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter value %d: ", i + 1);
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("Enter a value to find its predecessor: ");
    scanf("%d", &value);
    
    struct Node* node = root;
    while (node != NULL && node->data != value) {
        if (value < node->data) {
            node = node->left;
        } else {
            node = node->right;
        }
    }

    if (node != NULL) {
        struct Node* predecessor = findPredecessor(root, node);
        if (predecessor != NULL)
            printf("Predecessor of %d is %d\n", node->data, predecessor->data);
        else
            printf("No predecessor found for %d\n", node->data);
    } else {
        printf("Value %d not found in the BST.\n", value);
    }

    return 0;
}