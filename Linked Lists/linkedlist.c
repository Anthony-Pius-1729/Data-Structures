#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* next;
} Node;

//traverse Linked List
void traverseLinkedList (Node* head) {

    Node* currentNode = head;

    while(currentNode != NULL){
        printf("%d->", currentNode->value);
        currentNode = currentNode->next;
    }
    printf("NULL");

}

//Insert Node at a position
void insertNode (Node* refHead, int val, int position) {

    Node* newNode = (Node*)malloc(sizeof(Node*));
    newNode->value = val;
    int count = 0;
    Node* current = refHead;

    while (current !=NULL) {
        count++;

        if (count == position) {
            newNode->next = current->next;
            current->next = newNode;
        }
        current = current->next;
    }

}

//Delete a Node
void deleteNode (Node* head, int position) {


}

//reverse linked list 
Node* reverseLinkedList (Node* head) {
    Node* previous = NULL;
    Node* current = head;

    while ( current != NULL ) {
        
        Node* nextNode = current->next;
        current->next = previous;
        previous = current;
        current = nextNode;

    }

    return previous;
}
int  main () {

    //create nodes
    Node* node1 = (Node*)malloc(sizeof(Node));
    Node* node2 = (Node*)malloc(sizeof(Node));
    Node* node3 = (Node*)malloc(sizeof(Node));
    Node* node4 = (Node*)malloc(sizeof(Node));
    Node* node5 = (Node*)malloc(sizeof(Node));

    //give each node a value    
    node1->value = 1;
    node2->value = 2;
    node3->value = 3;
    node4->value = 4;
    node5->value = 5;


    Node* head = node1;

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = NULL;

    traverseLinkedList(head);
    printf("\n");
    insertNode(head, 9, 2);
    printf("\n");
    traverseLinkedList(head);
    printf("\n");
    Node* reversed = reverseLinkedList(head);
    printf("\n");
    traverseLinkedList(reversed);

    free(head);
    free(node1);
    free(node2);
    free(node3);
    free(node4);
    free(node5);


    return 0;
}