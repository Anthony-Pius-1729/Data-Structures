#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int id;
    int data;
    int neighborCount;
    int capacity;
    struct Node** neighbors;
} Node;

typedef struct Graph {
    Node** Nodes;
    int nodesNum;
    int capacity;
} Graph;

typedef struct LLNode {
    int val;
    struct LLNode* next;
}LLNode;

typedef struct Queue {
    int cap;
    LLNode* front;
    LLNode* rear;
}Queue;

Queue* initQ() {
    Queue* q =(Queue*)malloc(sizeof(Queue));
    q->cap = 0;
    q->front = 0;
    q->rear = -1;
} 

void enqueue (Queue* q, int val) {
    if (q == NULL) return;

    LLNode* newnode = (LLNode*)malloc(sizeof(LLNode));

    if (q->rear == NULL) {
        q->front = newnode;
        q->rear = newnode;
    } else {
        q->rear->next = newnode;
        q->rear = newnode;
    }

    q->cap++;
    
}

int dequeue(Queue* q) {
    if (!q || q->front == NULL) return -1;

    LLNode* temp = q->front;
    int val = temp->val;

    q->front = temp->next;
    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
    q->cap--;

    return val;
}


Graph* initGraph() {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->nodesNum = 0;
    graph->capacity = 0;
    graph->Nodes = NULL;
    return graph;
}


Node* createNode(int id, int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->id = id;
    node->data = data;
    node->neighborCount = 0;
    node->capacity = 0;
    node->neighbors = NULL;
    return node;
}


void addNode(Graph* graph, int id, int data) {
    if (graph == NULL) return;

    if (graph->nodesNum == graph->capacity) {
        int newcap = graph->capacity == 0 ? 4 : graph->capacity * 2;
        graph->Nodes = (Node**)realloc(graph->Nodes, sizeof(Node*) * newcap);
        graph->capacity = newcap;
    }

    graph->Nodes[graph->nodesNum++] = createNode(id, data);
}



Node* findNode(Graph* graph, int id) {
    for (int i = 0; i < graph->nodesNum; i++) {
        if (graph->Nodes[i]->id == id)
            return graph->Nodes[i];
    }
    return NULL;
}



void addEdge(Node* node, Node* neighbor) {
    if (node == NULL || neighbor == NULL) return;

    if (node->neighborCount == node->capacity) {
        int newcap = node->capacity == 0 ? 2 : node->capacity * 2;
        node->neighbors = (Node**)realloc(
            node->neighbors,
            sizeof(Node*) * newcap
        );
        node->capacity = newcap;
    }

    node->neighbors[node->neighborCount++] = neighbor;
}



int main() {
    Graph* graph = initGraph();

    addNode(graph, 1, 10);
    addNode(graph, 2, 20);
    addNode(graph, 3, 30);

    Node* n1 = findNode(graph, 1);
    Node* n2 = findNode(graph, 2);
    Node* n3 = findNode(graph, 3);

    addEdge(n1, n2);
    addEdge(n1, n3);
    addEdge(n2, n3);

    for (int i = 0; i < graph->nodesNum; i++) {
        Node* n = graph->Nodes[i];
        printf("Node %d neighbors: ", n->id);
        for (int j = 0; j < n->neighborCount; j++) {
            printf("%d ", n->neighbors[j]->id);
        }
        printf("\n");
    }

    Queue* q = initQ();
    

    return 0;
}
