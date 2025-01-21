#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct Graph {
    Node* adjList[MAX_VERTICES];
    int visited[MAX_VERTICES];
} Graph;

int count = 0; // Global count variable

// Function to create a new node
Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize the graph
void initGraph(Graph* graph) {
    for (int i = 0; i < MAX_VERTICES; i++) {
        graph->adjList[i] = NULL;
        graph->visited[i] = 0;
    }
}

// Function to add an edge
void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    // For undirected graph, add an edge from dest to src as well
    newNode = createNode(src);
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

// Recursive DFS function
void dfs(Graph* graph, int v) {
    count++; // Increment count for each visit
    graph->visited[v] = count; // Mark the vertex with the current count
    printf("Visited vertex %d with label %d\n", v, graph->visited[v]);

    Node* adjList = graph->adjList[v];
    while (adjList != NULL) {
        int connectedVertex = adjList->vertex;
        if (graph->visited[connectedVertex] == 0) { // If not visited
            dfs(graph, connectedVertex);
        }
        adjList = adjList->next;
    }
}

// Main DFS function that initializes DFS traversal
void DFS(Graph* graph) {
    for (int i = 0; i < MAX_VERTICES; i++) {
        if (graph->visited[i] == 0) { // If the vertex is unvisited
            dfs(graph, i);
        }
    }
}

int main() {
    Graph graph;
    initGraph(&graph);

    // Add edges to the graph
    addEdge(&graph, 0, 1);
    addEdge(&graph, 0, 2);
    addEdge(&graph, 1, 3);
    addEdge(&graph, 1, 4);
    addEdge(&graph, 2, 5);
    addEdge(&graph, 2, 6);
    addEdge(&graph, 3, 7);
    addEdge(&graph, 4, 8);
    addEdge(&graph, 5, 9);

    printf("DFS Traversal:\n");
    DFS(&graph);

    return 0;
}
