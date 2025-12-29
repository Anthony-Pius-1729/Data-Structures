#include <stdio.h>
#include <stdlib.h>
#ifndef NUM
#define NUM 5
#define K 4
#endif
typedef struct Node {
    struct Node* prev;
    int value;
    struct Node* next;
} Node;



void swap(Node** a, Node** b) {
    Node* temp = *a;
    *a = *b;
    *b = temp;
}

Node* reverse(Node* head) {
    Node* curr =  head;

    while (curr != NULL ) {
        // printf("%p --- %p --- %p \n", curr->prev, curr, curr->next );
        swap(&curr->next, &curr->prev);
        // printf("AFTER ");
        // printf("%p --- %p --- %p \n\n", curr->prev, curr, curr->next );
        if (curr->prev == NULL){
            return curr;
        } else{
            curr = curr->prev;
        }
    }
    return NULL;
}

Node* createNode (int n) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = n;
    newNode->prev = NULL;
    newNode->next =  NULL;

    return newNode;
}

Node* insert_back(Node* head, Node* newNode) {
    if (head == NULL) return head = newNode;

    Node* curr = head;

    while (curr->next != NULL) {
        curr = curr->next;
    }

    newNode->prev = curr;
    curr->next = newNode;
    
    return head;

}

void printN(Node* head) {
    if (head == NULL) {
        printf("Empty DLL");
        return;
    }

    Node* curr = head;
    printf("NULL");
    while (curr != NULL) {
        printf("<---%d--->", curr->value);
        curr = curr->next;
    } 
    printf("NULL"); 

}

int main () {
    Node* head = NULL;

    for (int i = 0; i < NUM; i++) {
        head = insert_back(head, createNode(i));
    }


   
    printN(head);

    for (int i = K-1; i < NUM; i++) {

    }

    printf("\n");
    printf("Reversed \n");
    head = reverse(head);
    printN(head);

    
    

    return 0;
}