#include <stdio.h>
#include <stdlib.h>

// Node structure for adjacency list
typedef struct Node
{
    int vertex;
    struct Node *next;
} Node;

// Graph structure for adjacency list
typedef struct Graph
{
    int numVertices;
    Node **adjLists; // Array of pointers to adjacency lists
} Graph;

// Function to create a new node
Node *createNode(int vertex)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph for adjacency list
Graph *createGraph(int vertices)
{
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->numVertices = vertices;

    // Allocate memory for adjacency lists
    graph->adjLists = (Node **)malloc(vertices * sizeof(Node *));

    // Initialize all adjacency lists to NULL
    for (int i = 0; i < vertices; i++)
    {
        graph->adjLists[i] = NULL;
    }

    return graph;
}

// Function to add an edge to the adjacency list
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

// Function to display adjacency list
void displayAdjList(Graph *graph)
{
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

// Function to create and display adjacency matrix
void adjacencyMatrix(int vertices, int edges)
{
    int matrix[vertices][vertices];

    // Initialize the matrix to 0
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            matrix[i][j] = 0;
        }
    }

    // Input edges and update the matrix
    printf("Enter the edges (source and destination):\n");
    for (int i = 0; i < edges; i++)
    {
        int src, dest;
        scanf("%d %d", &src, &dest);

        // Set the corresponding cells to 1
        matrix[src][dest] = 1;
        matrix[dest][src] = 1; // For undirected graph
    }

    // Display the adjacency matrix
    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Main function
int main()
{
    int vertices, edges;

    // Input number of vertices and edges
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    // Adjacency List Representation
    Graph *graph = createGraph(vertices);
    printf("Enter the edges (source and destination):\n");
    for (int i = 0; i < edges; i++)
    {
        int src, dest;
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    // Display Adjacency List
    printf("\nAdjacency List Representation:\n");
    displayAdjList(graph);

    // Adjacency Matrix Representation
    adjacencyMatrix(vertices, edges);

    return 0;
}
