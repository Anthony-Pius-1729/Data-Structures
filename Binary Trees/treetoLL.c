#include <stdio.h>
#include <stdlib.h>

// ------------------- BST NODE -------------------
typedef struct Node {
    int value;
    struct Node* left;
    struct Node* right;
} Node;

// Create a BST node
Node* createNode(int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Insert into BST
Node* insertNode(Node* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->value)
        root->left = insertNode(root->left, value);

    else if (value > root->value)
        root->right = insertNode(root->right, value);

    return root;
}

// ------------------- LINKED LIST NODE -------------------
typedef struct ListNode {
    int value;
    struct ListNode* next;
} ListNode;

// Create linked list node
ListNode* createListNode(int val) {
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->value = val;
    node->next = NULL;
    return node;
}


int countNodes (Node* root) {

    if (root == NULL) return 0;
    int leftcount = 0;
    int rightcount = 0;

    if (root->left) {
        leftcount = countNodes(root->left);
    }

   if (root->right) {
       rightcount = countNodes(root->right);
    }

    return leftcount + rightcount + 1;
}

int nodeValues[100] = {-1};
ListNode* head = NULL;
ListNode* cur = NULL;
void traverse (Node* root) {
    if (root == NULL) return;
    // static int i = 0;
    traverse(root->left);
    // nodeValues[++i] = root->value;
    cur->next = createListNode(root->value);
    cur = cur->next;
    traverse(root->right);
    return ;
}

ListNode* connect(int* nodeValues) {
    int i = 0;

    if (head == NULL) head = createListNode(nodeValues[i]);
    ListNode* current = head;
    while (nodeValues[i] != -1) {
        ListNode* newNode = createListNode(nodeValues[i]);
        current->next = newNode;
        current = current->next;
        i++;
    }
    
    return head;
}


// ------------------- PRINT LINKED LIST -------------------
void printList(ListNode* head) {
    while (head != NULL) {
        printf("%d -> ", head->value);
        head = head->next;
    }
    printf("NULL\n");
}

// ------------------- MAIN -------------------
int main() {
    for(int i = 0; i < 100; i++)
        nodeValues[i] = -1;

    Node* root;

    int arr[] = {8, 3, 10, 1, 6, 14, 4, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++)
        root = insertNode(root, arr[i]);

    int num = countNodes(root);
    // Convert BST to sorted linked list
    ListNode* head = connect(nodeValues);

    
   
    cur = head;
    traverse(root);

    // Print the linked list
    printList(head->next);
    return 0;
}
