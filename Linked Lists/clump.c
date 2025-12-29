#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int data;
    struct ListNode* next;
};

struct ListNode* build(int* a, int n) {
    struct ListNode *f = NULL, *t = NULL;
    for (int i = 0; i < n; i++) {
        struct ListNode* x = malloc(sizeof(struct ListNode));
        x->data = a[i];
        x->next = NULL;
        if (!f) f = t = x;
        else { t->next = x; t = x; }
    }
    return f;
}

void print(struct ListNode* f) {
    printf("{ ");
    while (f) {
        printf("%d", f->data);
        if (f->next) printf(", ");
        f = f->next;
    }
    printf(" }\n");
}

void freeList(struct ListNode* f) {
    while (f) {
        struct ListNode* t = f;
        f = f->next;
        free(t);
    }
}

void swap(struct ListNode** a, struct ListNode** b) {
    struct ListNode* temp = *a;
    *a = *b ;
    *b = temp;
}

struct ListNode*  sortList (struct Node** front, int size) {

    if (front == NULL) return NULL;

    struct ListNode* curr = front;

    for (int i = 0; i < size; i++) {

        for (int j = i+1; j < size; j++) {

            if (curr->next != NULL && curr->next->data < curr->data){
                swap(&curr->next, &curr);
            }
        }
        curr = curr->next;
    }

}

void clump(struct ListNode** front, int max) {
    if (max <= 0) exit(1);
}

int main() {
    int a[] = {1,6,5,2,6,4,5,3,5,8,5,2,8,4,5,6,8,6};
    int n = sizeof(a) / sizeof(a[0]);

    struct ListNode* front = build(a, n);
    print(front);

    clump(&front, 99);
    print(front);

    freeList(front);

    front = build(a, n);
    clump(&front, 2);
    print(front);

    freeList(front);
    return 0;
}
