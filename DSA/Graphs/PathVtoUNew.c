
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct Graph {
    int numVertices;
    int* visited;
    Node** adjLists;
} Graph;

// Function to create a node
Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph
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

// Function to add an edge
void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // For undirected graph
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

void path(Graph* g, int v, int u) {
    // Base case: if the current vertex is the target vertex, print and return
    if (v == u) {
        printf("%d ", v);
        return;
    }

    // Mark the current vertex as visited
    g->visited[v] = 1;
    printf("%d ", v);

    // Traverse the adjacency list of the current vertex
    Node* temp = g->adjLists[v];
    while (temp) {
        // If the neighbor has not been visited, recursively explore it
        if (g->visited[temp->vertex] == 0) {
            path(g, temp->vertex, u);

            // If the target has been found, stop further traversal
            if (g->visited[u]) {
                return;
            }
        }
        temp = temp->next;
    }
}


// Recursive DFS function to print path to the target
void DFSFindPath(Graph* graph, int vertex, int target) {
    // Mark the current node as visited and print it
    graph->visited[vertex] = 1;
    printf("%d ", vertex);

    // If we found the target, stop further recursion
    if (vertex == target) {
        return;
    }

    // Recur for all adjacent vertices
    Node* temp = graph->adjLists[vertex];
    while (temp != NULL) {
        int adjVertex = temp->vertex;
        if (graph->visited[adjVertex] == 0) {
            DFSFindPath(graph, adjVertex, target);
            // If we reached the target, stop further exploration
            if (graph->visited[target] == 1) {
                return;
            }
        }
        temp = temp->next;
    }
}

int main() {
    int vertices = 8;
    Graph* graph = createGraph(vertices);

    // Add edges to the graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 5);
    addEdge(graph, 2, 6);
    addEdge(graph, 3, 7);

    int startVertex = 0;
    int targetVertex = 7;

    printf("DFS Path from %d to %d: ", startVertex, targetVertex);
    DFSFindPath(graph, startVertex, targetVertex);

    // Check if the target was found
    if (graph->visited[targetVertex] == 0) {
        printf("\nNo path to %d exists.\n", targetVertex);
    } else {
        printf("\nPath to %d found.\n", targetVertex);
    }

    return 0;
}
