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

int getHeight(struct Node* root, int key) {
    if (root == NULL)
        return -1;

    if (root->key == key) {
        return height(root);
    }

    int leftHeight = getHeight(root->left, key);
    if (leftHeight != -1)
        return leftHeight;

    return getHeight(root->right, key);
}

int height(struct Node* node) {
    if (node == NULL)
        return -1;

    int leftHeight = height(node->left);
    int rightHeight = height(node->right);

    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
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
    int key;

    printf("Construct the binary tree:\n");
    root = constructTree();

    printf("\nIn-order traversal of the tree: ");
    inOrder(root);
    printf("\n");

    printf("Enter the key of the node to find its height: ");
    scanf("%d", &key);

    int nodeHeight = getHeight(root, key);
    if (nodeHeight == -1)
        printf("Node with key %d not found in the tree.\n", key);
    else
        printf("The height of the node with key %d is: %d\n", key, nodeHeight);

    return 0;
}