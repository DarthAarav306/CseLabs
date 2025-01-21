#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int vertex;
    struct Node *next;
} Node;

typedef struct Graph
{
    int numVertices;
    Node *adjLists[1000]; // Fixed-size array
} Graph;

Node *createNode(int vertex)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

Graph *createGraph(int vertices)
{
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->numVertices = vertices;

    // Initialize all adjacency lists to NULL
    for (int i = 0; i < vertices; i++)
    {
        graph->adjLists[i] = NULL;
    }
    return graph;
}

void addEdge(Graph *graph, int src, int dest)
{
    // Add edge from src to dest
    Node *newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Add edge from dest to src (for undirected graph)
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

void displayAdjList(Graph *graph)
{
    printf("\nAdjacency List Representation:\n");
    for (int i = 0; i < graph->numVertices; i++)
    {
        Node *temp = graph->adjLists[i];
        printf("Vertex %d: ", i);
        while (temp)
        {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

void adjacencyMatrix(Graph *graph)
{
    int vertices = graph->numVertices;
    int matrix[vertices][vertices];

    // Initialize matrix to 0
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            matrix[i][j] = 0;
        }
    }

    // Fill the matrix based on the adjacency list
    for (int i = 0; i < vertices; i++)
    {
        Node *temp = graph->adjLists[i];
        while (temp)
        {
            matrix[i][temp->vertex] = 1;
            temp = temp->next;
        }
    }

    // Display the adjacency matrix
    printf("\nAdjacency Matrix Representation:\n");
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int vertices, edges;

    // Input number of vertices and edges
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    if (vertices > 1000)
    {
        printf("Error: Maximum number of vertices is 1000.\n");
        return -1;
    }

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    // Create the graph
    Graph *graph = createGraph(vertices);

    // Input edges and build the graph
    printf("Enter the edges (source and destination):\n");
    for (int i = 0; i < edges; i++)
    {
        int src, dest;
        scanf("%d %d", &src, &dest);

        // Validate input
        if (src >= vertices || dest >= vertices || src < 0 || dest < 0)
        {
            printf("Invalid edge (%d, %d). Please enter valid vertices (0 to %d).\n", src, dest, vertices - 1);
            i--; // Retry the current edge input
        }
        else
        {
            addEdge(graph, src, dest);
        }
    }

    // Display the graph representations
    displayAdjList(graph);
    adjacencyMatrix(graph);

    // Free memory
    for (int i = 0; i < vertices; i++)
    {
        Node *temp = graph->adjLists[i];
        while (temp)
        {
            Node *toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }

    free(graph);

    return 0;
}
