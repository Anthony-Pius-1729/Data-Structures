/**Given the head of a linked list, remove the nth node from the end of the list and return its head.
 * Definition for singly-linked list.
 * 
 * Input: head = [1,2,3,4,5], n = 2
    Output: [1,2,3,5]
 */

 #include <stdio.h>
#include <stdlib.h>

 struct ListNode {
         int val;
         struct ListNode *next;
     };
 struct ListNode* reverseLL (struct ListNode* LL) {
    struct ListNode* current = LL;
    struct ListNode* previous = NULL;

    while (current != NULL) {
        struct ListNode* nextNode = current->next;
        current->next = previous;
        previous = current;
        current = nextNode;
    }

    return previous;

 }

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {

    if (head == NULL) return NULL;

    struct ListNode* LL = reverseLL(head);
    int i = 1;
    struct ListNode* temp = LL;
    struct ListNode* prev = NULL;

    if (n == 1) {
    LL = LL->next;
    free(temp);
    struct ListNode* rLL = reverseLL(LL);
    return rLL;
}


    while (temp != NULL & i < n) {
        prev = temp;
        temp = temp->next;
        i++;
    }

    if (temp == NULL) {
    struct ListNode* rLL = reverseLL(LL);
    return rLL;
}

    prev->next = temp->next;
    free(temp);

    struct ListNode* rLL = reverseLL(LL);
    return rLL;
    
}