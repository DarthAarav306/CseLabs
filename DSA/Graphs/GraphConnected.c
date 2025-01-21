#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct Graph {
    int numVertices;
    Node** adjLists;
    int* visited;
} Graph;

// Function to create a node
Node* createNode(int vertex) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with n vertices
Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;

    graph->adjLists = (Node**)malloc(vertices * sizeof(Node*));
    graph->visited = (int*)malloc(vertices * sizeof(int));

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }

    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int src, int dest) {
    // Add edge from src to dest
    Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Since it's an undirected graph, add edge from dest to src also
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// Depth-First Search to mark all reachable vertices
void DFS(Graph* graph, int vertex) {
    graph->visited[vertex] = 1;
    Node* temp = graph->adjLists[vertex];

    while (temp) {
        int adjVertex = temp->vertex;
        if (graph->visited[adjVertex] == 0) {
            DFS(graph, adjVertex);
        }
        temp = temp->next;
    }
}

// Function to check if the graph is connected
int isConnected(Graph* graph) {
    DFS(graph, 0);

    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->visited[i] == 0) {
            return 0; // Not connected
        }
    }
    return 1; // Connected
}

// Function to print connected components
void printConnectedComponents(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        graph->visited[i] = 0; // Reset visited for fresh DFS calls
    }

    printf("Connected Components:\n");
    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->visited[i] == 0) {
            printf("Component: ");
            DFS(graph, i);

            // Print all vertices in this component
            for (int j = 0; j < graph->numVertices; j++) {
                if (graph->visited[j] == 1) {
                    printf("%d ", j);
                    graph->visited[j] = 2; // Mark as fully visited for the component
                }
            }
            printf("\n");
        }
    }
}

// Function to print connected vertices of a given vertex
void printConnectedVertices(Graph* graph, int vertex) {
    for (int i = 0; i < graph->numVertices; i++) {
        graph->visited[i] = 0; // Reset visited for fresh DFS calls
    }

    printf("Connected vertices to vertex %d: ", vertex);
    DFS(graph, vertex);
    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->visited[i] == 1) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

// Main function to demonstrate the functionalities
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

    // Check if graph is connected
    if (isConnected(graph)) {
        printf("The graph is connected.\n");
    } else {
        printf("The graph is not connected.\n");
    }

    // Print connected components
    printConnectedComponents(graph);

    // Print connected vertices for a given vertex
    printf("Enter vertex to find its connected vertices: ");
    scanf("%d", &src);
    printConnectedVertices(graph, src);

    return 0;
}
