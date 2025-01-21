#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct Graph {
    int numVertices;
    int visited[MAX];
    Node* adjLists[MAX];
} Graph;

typedef struct Queue {
    int items[MAX];
    int front;
    int rear;
} Queue;

typedef struct Edge {
    int src, dest;
} Edge;

Edge bfsSpanningTree[MAX];  // To store edges of the BFS spanning tree
int bfsEdgeIndex = 0;

Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;

    for (int i = 0; i < vertices; i++) {
        graph->visited[i] = 0;
        graph->adjLists[i] = NULL;
    }
    return graph;
}

void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

void enqueue(Queue* queue, int value) {
    if (queue->rear == MAX - 1) return;
    if (queue->front == -1) queue->front = 0;
    queue->rear++;
    queue->items[queue->rear] = value;
}

int dequeue(Queue* queue) {
    int item;
    if (queue->front == -1) return -1;
    item = queue->items[queue->front];
    queue->front++;
    if (queue->front > queue->rear) queue->front = queue->rear = -1;
    return item;
}

void BFS(Graph* graph, int startVertex) {
    Queue* queue = createQueue();

    graph->visited[startVertex] = 1;
    enqueue(queue, startVertex);

    while (queue->front != -1) {
        int currentVertex = dequeue(queue);

        Node* temp = graph->adjLists[currentVertex];
        while (temp) {
            int adjVertex = temp->vertex;

            if (graph->visited[adjVertex] == 0) {
                graph->visited[adjVertex] = 1;
                enqueue(queue, adjVertex);
                
                // Add the edge to the BFS spanning tree
                bfsSpanningTree[bfsEdgeIndex].src = currentVertex;
                bfsSpanningTree[bfsEdgeIndex].dest = adjVertex;
                bfsEdgeIndex++;
            }
            temp = temp->next;
        }
    }
}

void printBFSSpanningTree() {
    printf("BFS Spanning Tree Edges:\n");
    for (int i = 0; i < bfsEdgeIndex; i++) {
        printf("(%d, %d)\n", bfsSpanningTree[i].src, bfsSpanningTree[i].dest);
    }
}

int main() {
    int vertices = 5;
    Graph* graph = createGraph(vertices);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 3, 4);

    BFS(graph, 0);
    printBFSSpanningTree();

    return 0;
}
