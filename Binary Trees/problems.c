#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int value;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int val) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->value = val;

    return newNode;
}

Node* insertNode( Node* root, int value) {

    if ( root == NULL) return createNode(value);

    if (value < root->value) {
        root->left = insertNode(root->left, value);
    }
    else if (value > root->value) {
        root->right = insertNode(root->right, value);
    }

    return root;
}

int main () {

    Node* root = NULL;
    int values[7] = {1, 2, 3, 4, 5, 2, 7};

    for (int i = 0; i < 7; i++) {
        root = insertNode(root, values[i]);
    }



    return 0;
}