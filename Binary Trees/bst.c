#include <stdio.h>
#include <stdlib.h>

typedef struct BSTNode {
    int data;
    struct BSTNode* left;
    struct BSTNode* right;
} BSTNode;

//create a binary searct tree node
BSTNode* createNode (int data){
    BSTNode* newNode = (BSTNode*)malloc(sizeof(BSTNode));

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}
BSTNode* insertNode (BSTNode* root, BSTNode* newNode) {
    if (root == NULL) {
        root = newNode;
        return root;
    }
    
    if (newNode->data < root->data ){
        root->left = insertNode(root->left, newNode);
    }else if (newNode->data > root->data) {
        root->right = insertNode(root->right, newNode);
    }

    return root;

}
 
int main () {
    //initialize a root pointer
    BSTNode* root = NULL;
    
    BSTNode* n1 = createNode(5);
    BSTNode* n2 = createNode(3);
    BSTNode* n3 = createNode(7);
    BSTNode* n4 = createNode(4);
    BSTNode* n5 = createNode(9);
    root = insertNode(root, n1);
    root = insertNode(root, n2);
    root = insertNode(root, n3);
    root = insertNode(root, n4);
    root = insertNode(root, n5);



    return 0;
}