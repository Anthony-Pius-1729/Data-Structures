#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    char name[50];
    int start_year;
    int end_year;
    int income;
} VizierRecord;

typedef struct Node{
    VizierRecord data;
    struct Node* left;
    struct Node* right;
    struct Node* parent;
    int height;
} Node;

Node* createNode (VizierRecord record) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = record;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = NULL;
    newNode->height = 1;

    return newNode;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int nodeHeight (Node* root) {
    if (root == NULL) return 0;
    return root->height;
}

Node* LLRotation(Node* node) {

    Node* newRoot = node->left;
    Node* T2 = newRoot->left;

    newRoot->right = node;
    node->left = T2;

    newRoot->parent = node->parent;

    node->parent = newRoot;

    if ( T2 != NULL) T2->parent = node;

    newRoot->height = 1 + max(nodeHeight(newRoot->left), nodeHeight(newRoot->right));

    node->height = 1 + max(nodeHeight(node->left), nodeHeight(node->right));


    return newRoot;
}

Node* RRRotation (Node* p) {
    Node* newRoot = p->right;
    Node* T2 = newRoot->left;

    newRoot->left = p;
    p->right = T2;

    newRoot->parent = p->parent;
    p->parent = newRoot;

    if (T2 != NULL) {
        T2->parent = p;
    }

    p->height = 1 + max(nodeHeight(p->left), nodeHeight(p->right));
    newRoot->height = 1 + max(nodeHeight(newRoot->left), nodeHeight(newRoot->right));
    
    return newRoot;

}

Node* minValue (Node* node) {
    Node* current = node;
    while (current->left != NULL){
        current = current->left;
    }
    return current;
}

Node* maxValue( Node* node) {
    Node* current = node;
    while(current->right != NULL){
        current = current->right;
    }
    return current;
}

Node* getSucessor (Node* node) {
    Node* current  =  node;

    if (current->right) {
        current = minValue(current->right);
        return current;
    }
    Node* p = current->parent;

    while (p != NULL && node == p->right ){

        current = p;
        p = p->parent;

    }

    return p;
}
Node* InsertNode (Node* root, VizierRecord record) {
    if (root == NULL) return root = createNode(record);

    if (root->data.start_year > record.start_year){
        root->left = InsertNode(root->left, record);
        root->left->parent = root;
      
    }
    else if ( root->data.start_year < record.start_year) {
        root->right = InsertNode(root->right, record);
        root->right->parent = root;
    }

    root->height = 1 +  max(nodeHeight(root->left), nodeHeight(root->right));

    int bf = (nodeHeight(root->left) - nodeHeight(root->right));

    if (bf = 2) {
        root = LLRotation(root);
    }

    return root;
}

int main () {

    static VizierRecord const history[] = {
        {"Lutfi Pasa", 1539, 1541, 155000},
        {"Mahmud Pasa", 1456, 1468, 4000000}, // <--- The Rival
        {"Piri Mehmed", 1518, 1523, 145000},
        {"Candarli Ali", 1387, 1406, 82000},
        {"Sokollu Mehmed", 1565, 1579, 2000000},
        {"Pargali Ibrahim", 1523, 1536, 3000000}, // <--- The Protagonist
        {"Koca Sinan", 1580, 1582, 210000},
        {"Alaeddin Pasa", 1320, 1331, 50000},
        {"Kemankes Mustafa", 1638, 1644, 230000},
        {"Gedik Ahmed", 1474, 1477, 115000},
        {"Koprulu Mehmed", 1656, 1661, 260000},
        {"Ayas Mehmed", 1536, 1539, 160000},
        {"Kuyucu Murad", 1606, 1611, 220000},
        {"Candarli Halil", 1364, 1387, 75000},
        {"Rustem Pasa", 1544, 1553, 2800000},
        {"Merzifonlu Kara", 1676, 1683, 290000},
        {"Semiz Ali", 1561, 1565, 170000},
        {"Ferhad Pasa", 1591, 1592, 190000},
        {"Nevsehirli Damat", 1718, 1730, 240000},
        {"Koprulu Fazil", 1661, 1676, 275000}
    };

    Node* root = NULL;

    for (int i = 0; i<20; i++) {
        root = InsertNode(root, history[i]);
    }




    return 0;
}