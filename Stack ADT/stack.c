#include <stdio.h>
#include <stdlib.h>

#define SIZE 5
int Stack[SIZE] = {};
int top = -1;

void push(int n) {
    if (top >= SIZE - 1) {
        printf("Error: Stack overflow. Cannot push %d\n", n);
        return;
    }
    top++;
    Stack[top] = n;
}


int pop() {
    if (top < 0) {
        printf("Error: Stack underflow. Cannot pop\n");
        return -1;  
    }
    int value = Stack[top];
    top--;
    return value;
}


void printStack() {
    if (top < 0) {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack (top -> bottom):\n");
    for (int i = top; i >= 0; i--) {
        printf("%d\n", Stack[i]);
    }
}

int main() {
    push(5);
    push(6);
    push(8);
    push(-1);
    push(10);
    push(20); 

    printStack();

    int popped = pop();
    if (popped != -1) printf("Popped: %d\n", popped);

    printf("After pop:\n");
    printStack();


    while (top >= 0) pop();
    pop(); 

    return 0;
}
