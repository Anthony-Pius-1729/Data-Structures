#include <stdio.h>

int sum(int n) {

    if (n == 0) return 0;

    return sum(n-1) + n;
}

int main () {
    printf("Hello \n");
    int answer  = sum(5);

    printf("%d \n", answer);
    return 0;
}