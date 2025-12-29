#include <stdio.h>


int memo[10];

int fib (int n) {
    if (memo[n] != -1) return memo[n];

    if (n <=1 ) {
        memo[n] = n;
        return n;
    } else {

        

        if (memo[n-2] == -1) memo[n-2] = fib(n-2);

        if (memo[n-1] == -1) memo[n-1] = fib(n-1);

    }

    memo[n] = memo[n-2] + memo[n-1];

    

    return memo[n];
}



int main () {
   

    for (int i = 0; i < 10; i++) {
        memo[i] = -1;
    }
    int result = fib(9);
    printf("%d \n", result);
    return 0;
}