#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 50

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct Graph {
    int numVertices;
    Node* adjLists[MAX_VERTICES];
    int visited[MAX_VERTICES];
} Graph;

typedef struct Stack {
    int items[MAX_VERTICES];
    int top;
} Stack;

// Function to create a new node
Node* createNode(int vertex) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize the graph
Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Add edge in the opposite direction for undirected graph
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// Stack operations
void initStack(Stack* stack) {
    stack->top = -1;
}

int isStackEmpty(Stack* stack) {
    return stack->top == -1;
}

void push(Stack* stack, int value) {
    stack->items[++stack->top] = value;
}

int pop(Stack* stack) {
    if (!isStackEmpty(stack)) {
        return stack->items[stack->top--];
    }
    return -1;
}

// Iterative DFS function
void DFSIterative(Graph* graph, int startVertex) {
    Stack stack;
    initStack(&stack);

    graph->visited[startVertex] = 1;
    push(&stack, startVertex);

    printf("Iterative DFS starting from vertex %d:\n", startVertex);

    while (!isStackEmpty(&stack)) {
        int currentVertex = pop(&stack);
        printf("%d ", currentVertex);

        Node* temp = graph->adjLists[currentVertex];
        while (temp) {
            int adjVertex = temp->vertex;
            if (graph->visited[adjVertex] == 0) {
                graph->visited[adjVertex] = 1;
                push(&stack, adjVertex);
            }
            temp = temp->next;
        }
    }
    printf("\n");
}

// Recursive DFS function
void DFSRecursive(Graph* graph, int vertex) {
    graph->visited[vertex] = 1;
    printf("%d ", vertex);

    Node* temp = graph->adjLists[vertex];
    while (temp) {
        int adjVertex = temp->vertex;
        if (graph->visited[adjVertex] == 0) {
            DFSRecursive(graph, adjVertex);
        }
        temp = temp->next;
    }
}

// Function to reset the visited array
void resetVisited(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        graph->visited[i] = 0;
    }
}

// Main function to test the program
int main() {
    Graph* graph = NULL;
    int vertices, edges;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    graph = createGraph(vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (source destination):\n");
    for (int i = 0; i < edges; i++) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    int startVertex;
    printf("Enter the starting vertex for DFS: ");
    scanf("%d", &startVertex);

    // Iterative DFS
    resetVisited(graph);
    DFSIterative(graph, startVertex);

    // Recursive DFS
    resetVisited(graph);
    printf("Recursive DFS starting from vertex %d:\n", startVertex);
    DFSRecursive(graph, startVertex);
    printf("\n");

    return 0;
}
