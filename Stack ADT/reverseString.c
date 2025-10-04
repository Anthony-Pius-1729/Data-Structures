#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct LLNode {
    char data;
    struct LLNode* next;
} Node;

Node* head = NULL;

void push(char c) {
    Node* charNode = (Node*)malloc(sizeof(Node));
    charNode->data = c;
    charNode->next = NULL;

    if (head == NULL){
        head = charNode;
        return;
    }

    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = charNode;
}

void pop() {
    if (head == NULL) return;

    Node* current = head;
    Node* previous = NULL;

    while (current->next != NULL){
        previous = current;
        current = current->next;
    }

    if (previous == NULL){
        printf("%c\n", head->data);
        free(head);
        head = NULL;
    } else {
        printf("%c\n", current->data);
        previous->next = NULL;
        free(current);
    }
}

void printStack() {
    Node* current = head;
    printf("Stack (top -> bottom):\n");
    while (current != NULL) {
        printf("%c\n", current->data);
        current = current->next;
    }
}

int main() {
    char name[] = "YO BRO THIS IS ANTHONY!!";
    int len = strlen(name);

    for (int i = 0; i < len; i++) {
        push(name[i]);
    }

    printStack();

    printf("NOW pop to reverse\n");

    for (int i = 0; i < len; i++) {
        pop();
    }

    return 0;
}
