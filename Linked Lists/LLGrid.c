#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *up, *down, *left, *right;
} Node;

typedef struct {
    Node *head; 
    size_t rows, cols;
} CellGrid;

// Helper to create a single node
Node* createNode(int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->value = value;
    node->up = node->down = node->left = node->right = NULL;
    return node;
}

// Create a CellGrid and fill with initvalue
CellGrid* gridcreate(int rows, int cols, int initvalue) {
    if (rows <= 0 || cols <= 0) return NULL;

    // Allocate a 2D array of nodes
    Node*** nodes = (Node***)malloc(rows * sizeof(Node**));
    for (int i = 0; i < rows; i++) {
        nodes[i] = (Node**)malloc(cols * sizeof(Node*));
        for (int j = 0; j < cols; j++) {
            nodes[i][j] = createNode(initvalue);
        }
    }

    // Link nodes (up, down, left, right)
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i > 0) nodes[i][j]->up = nodes[i - 1][j];
            if (i < rows - 1) nodes[i][j]->down = nodes[i + 1][j];
            if (j > 0) nodes[i][j]->left = nodes[i][j - 1];
            if (j < cols - 1) nodes[i][j]->right = nodes[i][j + 1];
        }
    }

    // Create the CellGrid
    CellGrid* grid = (CellGrid*)malloc(sizeof(CellGrid));
    grid->rows = rows;
    grid->cols = cols;
    grid->head = nodes[rows / 2][cols / 2];  // center node

    // Free temporary node pointer array (not the nodes themselves)
    for (int i = 0; i < rows; i++) free(nodes[i]);
    free(nodes);

    return grid;
}

// Update the value at a position (0,0) is head)
void gridupdate(CellGrid* grid, int col, int row, int newvalue) {
    if (!grid || !grid->head) return;

    Node* current = grid->head;

    // Move vertically
    for (int i = 0; i < abs(row); i++) {
        if (row > 0 && current->down) current = current->down;
        else if (row < 0 && current->up) current = current->up;
    }

    // Move horizontally
    for (int j = 0; j < abs(col); j++) {
        if (col > 0 && current->right) current = current->right;
        else if (col < 0 && current->left) current = current->left;
    }

    current->value = newvalue;
}

// Delete a row from the grid
void deleterow(CellGrid* g, int rowindex) {
    if (!g || !g->head || rowindex < -(int)(g->rows / 2) || rowindex >= (int)((g->rows + 1) / 2))
        return;

    Node* current = g->head;

    // Move to target row
    if (rowindex > 0) for (int i = 0; i < rowindex; i++) current = current->down;
    else for (int i = 0; i < -rowindex; i++) current = current->up;

    // Move to the leftmost node
    while (current->left) current = current->left;

    // Delete the entire row
    for (int j = 0; j < g->cols; j++) {
        Node* temp = current;
        if (temp->up) temp->up->down = temp->down;
        if (temp->down) temp->down->up = temp->up;
        current = current->right;
        free(temp);
    }

    g->rows--;
}

// Compute the sum of all elements
int sumgrid(CellGrid* g) {
    if (!g || !g->head) return 0;

    // Move to top-left
    Node* rowPtr = g->head;
    while (rowPtr->up) rowPtr = rowPtr->up;
    while (rowPtr->left) rowPtr = rowPtr->left;

    int sum = 0;

    // Traverse all nodes row by row
    for (int i = 0; i < g->rows; i++) {
        Node* colPtr = rowPtr;
        for (int j = 0; j < g->cols; j++) {
            sum += colPtr->value;
            colPtr = colPtr->right;
        }
        rowPtr = rowPtr->down;
    }

    return sum;
}


int main() {
    CellGrid* g = gridcreate(3, 3, 1);
    printf("Sum before update: %d\n", sumgrid(g));
    gridupdate(g, 1, -1, 10);  
    printf("Sum after update: %d\n", sumgrid(g));
    deleterow(g, 0);
    printf("Sum after deleting middle row: %d\n", sumgrid(g));
    return 0;
}
