#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Edge {
    struct  Node* dst;
    int num_link; //there could be more than one link between two webpages
} Edge;

typedef struct Node {
    int webpage_id;
    struct Edge** adjacents;
    int num_adj;
    int capacity;
} Node;

typedef struct Graph {
    Node** nodes;
    int num_nodes;
    int capacity;
} Graph;

typedef struct QNode {
    int val;
    struct Node* next;
}QNode;

typedef struct Queue {
    QNode* front;
    QNode* rear;
    int count;
}Queue;

Queue* initQ () {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->count = 0;
    q->front = NULL;
    q->rear = NULL;

    return q;
}

void enqueue (Queue* q, int val) {
    QNode* node = (QNode*)malloc(sizeof(QNode));
    node->val = val;
    node->next =  NULL;

    if (q->count == 0) {
        q->front = node;
        q->rear = node;
    } else {
    q->rear->next = node;
    q->rear = node;
    }

    q->count++;
}

QNode* dequeue (Queue* q) {

    if (q->front == NULL) {
        printf("Empty Queue");
        return NULL;
    }

    QNode* front = q->front;
    q->front  = front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    q->count--;

    return front;

}

Graph* initGraph () {
    Graph* g = (Graph*)malloc(sizeof(Graph));
    g->capacity = 0;
    g->nodes = (Node**)malloc(sizeof(Node*) * g->capacity);
    g->num_nodes = 0;

    return g;
}

Node* createNode (int web_id) {
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->adjacents = NULL;
    newnode->capacity = 0;
    newnode->num_adj = 0;
    newnode->webpage_id = web_id;

    return newnode;
}

void addNode(Graph* g, int web_id) {

    if (g->capacity == g->num_nodes) {

    int newCapacity = g->capacity == 0 ? 4 : (g->capacity)*2 ;

    //if graph is full/empty i.e the capacity is same as number of nodes or zero
    Node** newnodes = (Node**)malloc(sizeof(Node*) * newCapacity); 

    for (int i = 0 ; i < g->num_nodes; i++) {
            newnodes[i] = (g->nodes[i]);
    }

    g->nodes = newnodes;
    g->capacity = newCapacity;

    }

    //this should create a node and add it to the max number of nodes position
   g->nodes[g->num_nodes] = createNode(web_id);
   g->num_nodes++; 
}

void addEdge(Node* source, Node* destination, int num_link) {

    if (source->capacity == source->num_adj ) {
        int newcap = source->capacity == 0 ? 4 : (source->capacity)*2;
        Edge** adjs = (Edge**)malloc(sizeof(Edge*) * newcap);

        for (int i = 0; i < source->num_adj; i++) {
            adjs[i] = source->adjacents[i];
        }

        if (source->adjacents != NULL) {
            free(source->adjacents);
        }

        source->adjacents = adjs;
        source->capacity = newcap;
    }

    
    Edge* newEdge = (Edge*)malloc(sizeof(Edge));
    newEdge->dst = destination;
    newEdge->num_link = num_link;

    source->adjacents[source->num_adj] = newEdge;
    source->num_adj++;

}

Node* findNode(Graph* g, int web_id) {

    if (g == NULL) {
        printf("Memory not allocated for graph");
        return NULL;
    }

    for (int i = 0 ; i < g->num_nodes; i++) {
        if (g->nodes[i]->webpage_id == web_id) {
            return g->nodes[i];
        }
    }

    return NULL;
}

void removeEdge (Node* a, Node* b) {

    int found = 0;
    int found_at = -1;
    for (int i = 0; i < a->num_adj; i++) {
        if (a->adjacents[i]->dst == b) {
            found = 1;
            found_at = i;
            break;
        }
    }
    if (!found || found_at == -1) {
        printf("Node %d is not adjacent to node %d \n", b->webpage_id, a->webpage_id);
        return;
    }

    int i = found_at;
    int j = found_at + 1;

    free(a->adjacents[i]);

    while ( j && j < a->num_adj) {
        a->adjacents[i++] = a->adjacents[j++];
    }

    a->num_adj--;
    printf("Removed Edge between %d and %d \n", a->webpage_id, b->webpage_id);
}

// Source - https://stackoverflow.com/a/6219061
// Posted by John Bode
// Retrieved 2025-12-27, License - CC BY-SA 3.0




void printGraph (Graph* g) {
    for (int i = 0; i < g->num_nodes; i++) {
        for (int j = 0; j < g->nodes[i]->num_adj; j++) {
            printf("%d ", g->nodes[i]->adjacents[j]->num_link);
        }
    }
    printf("\n");
}

void freeGraph (Graph* g) {
    for (int i = 0; i < g->num_nodes; i++) {
        for (int j = 0; j < g->nodes[i]->num_adj; j++) {
            free(g->nodes[i]->adjacents[j]->dst);
        }
        free(g->nodes[i]->adjacents[i]);
    }

    for (int i = 0; i < g->num_nodes; i++) {
        free(g->nodes[i]);
    }
}


// Source - https://stackoverflow.com/a/45598170
// Posted by Hiesso
// Retrieved 2025-12-27, License - CC BY-SA 3.0

double random_0_1(void) {
    return (double) rand() / (double) RAND_MAX;
}

//Actual PageRank Algorithm Implementation 
double* pagerank_random_walk(Graph* g, double damping_factor, int num_steps) {

    int sum = 0;

    double* visits = (double*)malloc(sizeof(double) * g->num_nodes);

    for (int i = 0; i < g->num_nodes; i++) {
        visits[i] = 0.0;
    }

    int rand_index = rand() % g->num_nodes;
    Node* surfer = g->nodes[rand_index];
    visits[rand_index] += 1;

    for (int i = 0; i < num_steps; i++) {

            double decision_factor = random_0_1();

            if (decision_factor <= damping_factor && surfer->num_adj > 0) {

                int rand_adj = rand() % surfer->num_adj;
                surfer = surfer->adjacents[rand_adj]->dst;
                
            } else {

                surfer = g->nodes[rand() % g->num_nodes];

            }

            visits[surfer->webpage_id ] += 1;
        
    }

    //normalize 
    for (int i = 0; i < g->num_nodes; i++) {
        sum += visits[i];
    }

    for (int i = 0; i < g->num_nodes; i++) {
        visits[i] = (double) visits[i] / (double) sum;
    }

    return visits;
}

int** upper_triangular_matrix(int n, int (*graph)[n]) {

    int **upper_triangle = malloc(sizeof(int*) * n);

    for (int i = 0; i < n; i++) {
        upper_triangle[i] = malloc(sizeof(int) * n);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            upper_triangle[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j < i)  {
                upper_triangle[i][j] = 0;
            } else {
                upper_triangle[i][j] = graph[i][j];
            }
        }
    }

    return upper_triangle;
}



int main () {

    srand(time(NULL));

    printf("%lf \n", random_0_1());

    printf("Up and Running! \n");

    Graph* graph = initGraph();

    int g[12][12] = {
        {1, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0},
        {2, 1, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 0, 0},
        {0, 6, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 2, 6, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 2, 5, 0, 2, 4},
        {0, 0, 0, 0, 0, 1, 0, 0, 6, 0, 0, 7},
        {0, 0, 0, 0, 0, 0, 0, 1, 2, 0, 0, 0}
    };
    

    for (int i = 0; i < 12; i++) {
        addNode(graph, i);
    }

    for (int i = 0; i < 12; i++) {

        for (int j = 0; j < 12; j++) {
            if (g[i][j] != 0 ) {
                addEdge(graph->nodes[i], graph->nodes[j], g[i][j]);
                printf("Created edge from Node %d to Node %d\n", graph->nodes[i]->webpage_id + 1, graph->nodes[j]->webpage_id + 1);
                }
            }

    }
    graph->num_nodes = 12;

    Node* node = findNode(graph, 7);
    printf("Found Node %d \n", node->webpage_id);
    removeEdge(graph->nodes[10], graph->nodes[0]);
    printGraph(graph);
    double* res =  pagerank_random_walk(graph, 0.85, 1000000);

    for (int i = 0; i < graph->num_nodes; i++) {
        printf("%lf ", res[i]);
    }
    // freeGraph(graph);

    printf("Upper Triangular Matrix \n");

    int** half_mat = upper_triangular_matrix(12, g);
    Graph* upper_g = initGraph();

    for (int i = 0; i < graph->num_nodes; i++) {
        for (int j = 0; j < graph->num_nodes; j++) {
            printf("%d ", half_mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for (int i = 0; i < 12; i++) {
        addNode(upper_g, i);
    }

    for (int i = 0; i < 12; i++) {

        for (int j = 0; j < 12; j++) {
            if (half_mat[i][j] != 0 ) {
                addEdge(upper_g->nodes[i], upper_g->nodes[j], half_mat[i][j]);
                addEdge(upper_g->nodes[j], upper_g->nodes[i], half_mat[i][j]);
                printf("Created edge from Node %d to Node %d\n", upper_g->nodes[i]->webpage_id + 1, upper_g->nodes[j]->webpage_id + 1);
                }
            }

    }
    return 0;
}