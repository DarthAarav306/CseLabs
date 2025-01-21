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

Node* createNode(int vertex) {
    Node* newNode = malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

Graph* createGraph(int vertices) {
    Graph* graph = malloc(sizeof(Graph));
    graph->numVertices = vertices;
    graph->adjLists = malloc(vertices * sizeof(Node*));
    graph->visited = malloc(vertices * sizeof(int));
    
    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}

void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
    
    newNode = createNode(src);  // Since the graph is undirected
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

int DFS(Graph* graph, int startVertex, int targetVertex) {
    graph->visited[startVertex] = 1;
    if (startVertex == targetVertex) {
        printf("%d ", startVertex);
        return 1;
    }
    
    Node* temp = graph->adjLists[startVertex];
    while (temp) {
        int adjVertex = temp->vertex;
        if (!graph->visited[adjVertex]) {
            if (DFS(graph, adjVertex, targetVertex)) {
                printf("%d ", startVertex); // Print vertex if part of the path
                return 1;
            }
        }
        temp = temp->next;
    }
    return 0;
}

int main() {
    int vertices = 5;
    Graph* graph = createGraph(vertices);
    
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    
    int startVertex = 0;
    int targetVertex = 3;
    printf("Path from %d to %d: ", startVertex, targetVertex);
    if (!DFS(graph, startVertex, targetVertex)) {
        printf("No path found.\n");
    } else {
        printf("\n");
    }
    
    return 0;
}
