#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key;
    struct Node *left, *right;
};

struct Node* createNode(int key) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* node, int key) {
    if (node == NULL) return createNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);

    return node;
}

int findMin(struct Node* node) {
    struct Node* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current->key;
}

int findMax(struct Node* node) {
    struct Node* current = node;
    while (current && current->right != NULL) {
        current = current->right;
    }
    return current->key;
}

int main() {
    struct Node* root = NULL;
    int n, key;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the values for each node:\n");
    for (int i = 0; i < n; i++) {
        printf("Node %d: ", i + 1);
        scanf("%d", &key);
        root = insert(root, key);
    }

    if (root != NULL) {
        int min = findMin(root);
        int max = findMax(root);
        printf("Minimum key in the BST: %d\n", min);
        printf("Maximum key in the BST: %d\n", max);
    } else {
        printf("The tree is empty.\n");
    }

    return 0;
}