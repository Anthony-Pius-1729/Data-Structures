#include <stdio.h>

int main () {

    char input[] = "()[]";

    char parentheses[6] = {'(', ')', '{', '}' , '[', ']'};
    int top = -1;
    char stack[100] = {};

    for (int i = 0; input[i] != '\0'; i++) {
        
        char c = input[i];

        if ((c == '(') || (c == '{') || (c == '[') ) {
            top++;
            stack[top] = c;
            

        }

        else if (c == ')' || c == '}' || c == ']') {
            if (top == -1) {  
                printf("Not balanced\n");
                return 0;
            }

            char topChar = stack[top--];  

            if ((c == ')' && topChar != '(') ||
                (c == '}' && topChar != '{') ||
                (c == ']' && topChar != '[')) {

                printf("Not balanced\n");
                return 0;
            }
        }
    }

    if (top == -1)
        printf("Balanced\n");
    else
        printf("Not balanced\n");


    return 0;
}