#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedListNode {
    int value;
    struct LinkedListNode* next;
} Node;

Node* head = NULL;

void push(int n) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = n;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

void pop() {
    if (head == NULL) return;

    Node* current = head;
    Node* previous = NULL;

    while (current->next != NULL) {
        previous = current;
        current = current->next;
    }

    if (previous == NULL) {
        free(head);
        head = NULL;
    } else {
        previous->next = NULL;
        free(current);
    }
}

void printStack() {
    Node* current = head;
    printf("Stack (top -> bottom):\n");
    while (current != NULL) {
        printf("%d\n", current->value);
        current = current->next;
    }
}

int main() {
    push(5);
    push(10);
    push(7);

    printStack();

    pop();
    printf("After pop:\n");
    printStack();

    return 0;
}
