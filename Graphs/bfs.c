#include <stdio.h>
#include <stdlib.h>

#define N 6

int rear = 0;
int front = 0;

void enqueue(int q[N], int n) {
    if (rear == N) {
        printf("Queue is FULL.\n");
        return;
    }
    q[rear] = n;
    rear++;
}

int dequeue(int q[N]) {
    if (front == rear) {
        return -1; // empty
    }
    int v = q[front];
    front++;
    return v;
}

void bfs(int adj[N][N], int start, int visited[N]) {
    int queue[N];
    rear = front = 0;

    enqueue(queue, start);
    visited[start] = 1;

    while ( front != rear ) {
        int popped  = dequeue(queue);
        printf("%d ", popped);
    
        for (int i = 0; i < N; i++) {
            if (adj[popped][i] == 1 && !visited[i]) {
                enqueue(queue, i);
                visited[i] = 1;
            }
        }
    }
 }

int main() {

    int adj[N][N] = {
        {0, 1, 0, 0, 1, 0},
        {1, 0, 1, 0, 0, 0},
        {0, 1, 0, 1, 0, 0},
        {0, 0, 1, 0, 1, 1},
        {1, 0, 0, 1, 0, 0},
        {0, 0, 0, 1, 0, 0}
    };

    int visited[N] = {0};

    printf("BFS starting from node 0:\n");
    bfs(adj, 0, visited);

    return 0;
}
