#include <stdio.h>

typedef struct node {
    node* par;
    node* childe[2000];
    int child_n;
    int visited;
} node;

int man[2000];
int child[2000][2000];
int child_n[2000];
int visited[2000];
int max = -1;

void dfs(int cur, int depth) {
    visited[cur] = 1;

    if(depth > max)
        max = depth;

    if(child_n[cur] == 0)
        return;

    for(int i = 0; i < child_n[cur]; i++) {
        dfs(child[cur][i], depth + 1);
    }
}

int main() {
    int n;
    
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &man[i]);

        if(man[i] == -1)
            continue;

        child[man[i]][child_n[man[i]]] = i + 1;

        child_n[man[i]]++;
    }

    printf("man: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", man[i]);
    }

    printf("\nchild:\n");
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < child_n[i]; j++)
            printf("%d ", child[i][j]);
        printf("\n");
    }
    
    
    printf("\nchild_n: ");
    for(int i = 1; i <= n; i++) {
        printf("%d ", child_n[i]);
    }
    printf("\n");
    
    for(int i = 1; i <= n; i++)
        if(!visited[i])
            dfs(i, 1);

    printf("%d", max);

    return 0;
}