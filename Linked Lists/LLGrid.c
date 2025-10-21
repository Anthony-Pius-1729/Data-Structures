#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* up;
    struct Node* down;
    struct Node* left;
    struct Node* right;
} Node;

typedef struct {
    Node*  head;
    size_t rows, cols;
} CellGrid;


CellGrid* gridcreate(int rows, int cols, int initvalue) {

    if (rows == 0 || cols == 0) return NULL;

    Node* temp_nodes[rows][cols];


    for (int i = 0 ; i < rows; i++) {
        for (int j = 0;  j < cols; j++) {
            temp_nodes[i][j] = malloc(sizeof(Node));
            temp_nodes[i][j]->value  = initvalue;
        }
    }

    for (int i = 0 ; i < rows; i++) {
        for (int j = 0;  j < cols; j++) {
            Node* currentNode = temp_nodes[i][j];

            currentNode->right = ( j == cols - 1) ? NULL : temp_nodes[i][j+1];
            currentNode->left = ( j == 0) ? NULL : temp_nodes[i][j-1];
            currentNode->up = ( i == 0) ? NULL : temp_nodes[i-1][j];
            currentNode->down = ( i == rows - 1) ? NULL : temp_nodes[i+1][j];

        }
    }

    CellGrid* grid = malloc(sizeof(CellGrid));

    int mid_row = rows/2;
    int mid_col = cols/2;

    grid->head = temp_nodes[mid_row][mid_col];

    return grid; 
}

void gridupdate(CellGrid* grid, int col, int row, int newvalue) {
    if (grid == NULL || grid->head == NULL) return;  
    
    Node* headptr = grid->head;
    
    if (row < 0) {
        int it = row * -1;
        for (int i = 0; i < it; i++) {
            if (headptr->up == NULL) return;  
            headptr = headptr->up;
        }
    } else if (row > 0) {
        for (int i = 0; i < row; i++) {
            if (headptr->down == NULL) return;  
            headptr = headptr->down;
        }
    }
    
    if (col < 0) {
        int it = col * -1;
        for (int i = 0; i < it; i++) {
            if (headptr->left == NULL) return;  
            headptr = headptr->left;
        }
    } else if (col > 0) {
        for (int i = 0; i < col; i++) {
            if (headptr->right == NULL) return;  
            headptr = headptr->right;
        }
    }
    
    headptr->value = newvalue;
}


int main () {


    return 0;
}