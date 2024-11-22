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

struct Node* constructTree() {
    int key;
    printf("Enter node value (-1 for no node): ");
    scanf("%d", &key);

    if (key == -1)
        return NULL;

    struct Node* newNode = createNode(key);

    printf("Enter left child of %d:\n", key);
    newNode->left = constructTree();

    printf("Enter right child of %d:\n", key);
    newNode->right = constructTree();

    return newNode;
}

void inOrder(struct Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->key);
        inOrder(root->right);
    }
}

void preOrder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(struct Node* root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->key);
    }
}

int main() {
    struct Node* root = NULL;

    printf("Construct the binary tree:\n");
    root = constructTree();
    
    printf("\nIn-order traversal: ");
    inOrder(root);
    printf("\n");

    printf("Pre-order traversal: ");
    preOrder(root);
    printf("\n");

    printf("Post-order traversal: ");
    postOrder(root);
    printf("\n");

    return 0;
}