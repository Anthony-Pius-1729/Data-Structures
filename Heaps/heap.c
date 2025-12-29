#include <stdio.h>
#include <stdlib.h>

void Insert (int array[], int n) {

    int temp = array[n];
    int i = n;
    
    while (i > 1 && temp > array[i/2]) {
        array[i] = array[i/2];
        i = i/2;
    }
    array[i] = temp;

}

void Delete (int A[], int n) {

    int t = A[n];
    int A[1] = t;
    int i = 1, j = 2*i;

    while ( j < n ) {

        if (A[j+1] > A[j]) {
            j = j+1;
        }
    }

}

int main () {

    int H[] = {0,10,20,30,25,5,40,35};

    for (int i = 2; i < 8; i++) {
        Insert(H, i);
    }

    for (int i = 0; i < 8; i++) {
        printf("%d ", H[i]);
    }

    return 0;
}