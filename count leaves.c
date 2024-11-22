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

int countLeaves(struct Node* root) {
    if (root == NULL)
        return 0;

    if (root->left == NULL && root->right == NULL)
        return 1;

    return countLeaves(root->left) + countLeaves(root->right);
}

void inOrder(struct Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->key);
        inOrder(root->right);
    }
}

int main() {
    struct Node* root = NULL;

    printf("Construct the binary tree:\n");
    root = constructTree();

    printf("\nIn-order traversal of the tree: ");
    inOrder(root);
    printf("\n");

    int leafCount = countLeaves(root);
    printf("Number of leaves in the tree: %d\n", leafCount);

    return 0;
}