#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int m, n; 
int i  = 0;
int j = 0;

bool inbound(int m, int n, int i, int j) {
    return (i >= 0 && i < m && j >= 0 && j < n);
}

void spiralPrinter (int** grid, int** boolgrid, int m, int n, int i, int j) {
    
    printf("inbound %d \n", inbound(m, n, i, j));

    for (int j = 0; j < n; j ++) {
        printf("%d -> ", grid[0][j]);
    }

    printf("\n");
    
    for (int i = 0; i < n; i++) {
        printf("%d -> ", grid[i][n]);
    }

    
    printf("\nspiral printing ended\n");
    

}
int main() {
    
    
    printf("Enter number of rows (m): ");
    scanf("%d", &m);
    printf("Enter number of columns (n): ");
    scanf("%d", &n);

    // Seed the random number generator
    srand(time(NULL));

    // Dynamically allocate a 2D array
    int** grid = (int **)malloc(m * sizeof(int *));
    int** boolgrid = (int **)malloc(m * sizeof(int *));

    for (int i = 0; i < m; i++) {
        grid[i] = (int *)malloc(n * sizeof(int));
        boolgrid[i] = (int *)malloc(n * sizeof(int));
    }

    // Fill the grid with random numbers (0 to 99)
    // Fill boolean grid with all false
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            grid[i][j] = rand() % 100;
            boolgrid[i][j] = 0;
        }
    }


    printf("Generated %dx%d grid:\n", m, n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%3d ", grid[i][j]);
        }
        printf("\n");
    }
    printf("Spiral printed array \n");

    spiralPrinter(grid, boolgrid, m, n, i = 0, j = 0);
    
    // Free allocated memory
    for (int i = 0; i < m; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}
