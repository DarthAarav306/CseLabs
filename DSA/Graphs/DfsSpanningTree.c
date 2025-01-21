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

typedef struct Edge {
    int src, dest;
} Edge;

Edge dfsSpanningTree[MAX];  // To store edges of the DFS spanning tree
int dfsEdgeIndex = 0;

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

void DFS(Graph* graph, int vertex) {
    graph->visited[vertex] = 1;

    Node* temp = graph->adjLists[vertex];
    while (temp) {
        int connectedVertex = temp->vertex;
        if (!graph->visited[connectedVertex]) {
            // Add the edge to the DFS spanning tree
            dfsSpanningTree[dfsEdgeIndex].src = vertex;
            dfsSpanningTree[dfsEdgeIndex].dest = connectedVertex;
            dfsEdgeIndex++;
            
            DFS(graph, connectedVertex);
        }
        temp = temp->next;
    }
}

void printDFSSpanningTree() {
    printf("DFS Spanning Tree Edges:\n");
    for (int i = 0; i < dfsEdgeIndex; i++) {
        printf("(%d, %d)\n", dfsSpanningTree[i].src, dfsSpanningTree[i].dest);
    }
}

int main() {
    int vertices = 5;
    Graph* graph = createGraph(vertices);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 3, 4);

    DFS(graph, 0);
    printDFSSpanningTree();

    return 0;
}
