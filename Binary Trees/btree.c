#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int countNode (struct Node* root) {

    if (root == NULL) return 0;

    int x = countNode(root->left);
    int y =  countNode(root->right);

    return x+y+1;

}

int countLeave( struct Node* root) {

    if (root == NULL) return 0;

    if (root->left == NULL  && root->right == NULL){
        return 1;
    }
    
    return countLeave(root->left) +  countLeave(root->right);
}

int main() {
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    int count = countNode(root);

    int countLeaves = countLeave(root);

    printf("%d \n", count);
    printf("%d \n", countLeaves);

    return 0;
}
