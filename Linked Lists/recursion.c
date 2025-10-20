#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node* right;
    struct node* left;

} node;

int recur(node* current) {

    if (current == NULL) return 0;

    return current->value + recur(current->right) + recur(current->left);
}
int main () {
    node root = {0};
    node* cur = &root;
    for(int i = 0; i < 10; i++) {
        node* next = (node*)malloc(sizeof(node));

        next->value = i;
        cur->right = next;
        cur = next;
    }

    printf("%d", recur(&root));

    return 0;
}