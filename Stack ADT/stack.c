#include <stdio.h>
#include <stdlib.h>

const int size = 5;
int Stack[size] = {};
int top = -1;

void push(int n) {
    top++;
    Stack[top] = n;
}

void pop() {
    top--;
    Stack[top];
}

void printStack(int* Stack, int top) {
    for (int i = top; i >= 0; i--){
        printf("%d \n", Stack[i]);
    }
}

int main () {

    push(5);
    push(6);
    push(8);
    push(-1);


    printStack(Stack, top);

    pop();

    printf("After popped stack \n");

    printStack(Stack, top);

    return 0;
}