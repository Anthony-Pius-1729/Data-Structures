//Problem Statement
// You are given two non-empty linked lists representing two non-negative integers.
// The digits are stored in reverse order, and each of their nodes contains a single digit. 
// Add the two numbers and return the sum as a linked list.
// You may assume the two numbers do not contain any leading zero, except the number 0 itself.

// Input: l1 = [2,4,3], l2 = [5,6,4]
// Output: [7,0,8] 
// Explanation: 342 + 465 = 807.
// Final result 7->0->8



struct ListNode {
      int val;
      struct ListNode *next;
  };


 #include <stdio.h>
 #include <stdlib.h>
 

 int* getArray(struct ListNode* ll, int* size) {
    struct ListNode* current = ll;
    int i = 0;
    int* arr = (int*)malloc(10000 * sizeof(int));
    while (current != NULL) {
        arr[i++] = current->val;
        current = current->next;
    }
    *size = i;
    return arr;
}

int* sumArray(int* array1, int* array2, int size1, int size2, int* resultSize) {
    int maxLen = (size1 > size2) ? size1 : size2;
    int* result = (int*)malloc((maxLen + 1) * sizeof(int));
    if (!result) return NULL;
    
    int carry = 0;
    int i = 0;
    int j = 0;
    int k = 0;
    

    while (i < size1 || j < size2 || carry != 0) {
        int x = (i < size1) ? array1[i] : 0;
        int y = (j < size2) ? array2[j] : 0;
        int sum = x + y + carry;
        result[k] = sum % 10;
        carry = sum / 10;
        i++; 
        j++; 
        k++;
    }
    
    *resultSize = k;
    return result;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {

    int size1, size2, resultSize;
    int* array1 = getArray(l1, &size1);
    int* array2 = getArray(l2, &size2);
    int* resultArray = sumArray(array1, array2, size1, size2, &resultSize);
    
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->val = resultArray[0];
    head->next = NULL;
    struct ListNode* current = head;
    
    for (int i = 1; i < resultSize; i++) {
        struct ListNode* nextNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        nextNode->val = resultArray[i];
        nextNode->next = NULL;
        current->next = nextNode;
        current = nextNode;
    }
    
    free(array1);
    free(array2);
    free(resultArray);
    
    return head;
}
