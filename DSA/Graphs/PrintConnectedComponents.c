#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Node structure for the adjacency list
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// Graph structure containing an array of adjacency lists and a visited array
typedef struct Graph {
    Node* adjLists[MAX];
    int visited[MAX];
    int numVertices;
} Graph;

// Function to create a new node
Node* createNode(int vertex) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize a graph
Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}

// Function to add an edge
void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Adding reverse edge for undirected graph
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// Recursive DFS function to visit all nodes in a component
void DFS(Graph* graph, int vertex) {
    graph->visited[vertex] = 1;
    printf("%d ", vertex);

    Node* temp = graph->adjLists[vertex];
    while (temp) {
        int adjVertex = temp->vertex;
        if (graph->visited[adjVertex] == 0) {
            DFS(graph, adjVertex);
        }
        temp = temp->next;
    }
}

// Function to find and print all connected components
void printConnectedComponents(Graph* graph) {
    printf("Connected components:\n");
    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->visited[i] == 0) {
            printf("Component: ");
            DFS(graph, i);
            printf("\n");
        }
    }
}

int main() {
    int vertices, edges, src, dest;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    Graph* graph = createGraph(vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);
    printf("Enter edges (source destination):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    printConnectedComponents(graph);

    return 0;
}
