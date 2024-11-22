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

int height(struct Node* node) {
    if (node == NULL) return 0;
    int leftHeight = height(node->left);
    int rightHeight = height(node->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

int balanceFactor(struct Node* node) {
    if (node == NULL) return 0;
    return height(node->left) - height(node->right);
}

struct Node* findNode(struct Node* root, int key) {
    if (root == NULL || root->key == key)
        return root;
    if (key < root->key)
        return findNode(root->left, key);
    else
        return findNode(root->right, key);
}

int main() {
    struct Node* root = NULL;
    int n, key, targetKey;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the values for each node:\n");
    for (int i = 0; i < n; i++) {
        printf("Node %d: ", i + 1);
        scanf("%d", &key);
        root = insert(root, key);
    }

    printf("Enter the key of the node to find its balance factor: ");
    scanf("%d", &targetKey);

    struct Node* targetNode = findNode(root, targetKey);
    if (targetNode == NULL) {
        printf("Node with key %d not found in the BST.\n", targetKey);
        return 1;
    }

    int bf = balanceFactor(targetNode);
    printf("The balance factor of node with key %d is: %d\n", targetKey, bf);

    return 0;
}