#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

// Adjacency list representation
typedef struct Node
{
    int vertex;
    struct Node *next;
} Node;

Node *adjList[MAX_NODES];
int visited[MAX_NODES];

// Function to create a new node
Node *createNode(int v)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Function to add an edge to the tree
void addEdge(int u, int v)
{
    Node *newNode = createNode(v);
    newNode->next = adjList[u];
    adjList[u] = newNode;

    newNode = createNode(u);
    newNode->next = adjList[v];
    adjList[v] = newNode;
}

// Function to print the rooted tree
void printRootedTree(int n)
{
    printf("Rooted Tree:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d -> ", i);
        Node *temp = adjList[i];
        while (temp)
        {
            printf("%d ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

// DFS function to root the tree
void rootTreeDFS(int node, int parent)
{
    visited[node] = 1;

    Node *temp = adjList[node];
    while (temp)
    {
        int child = temp->vertex;

        // Remove the parent edge
        if (child == parent)
        {
            temp = temp->next;
            continue;
        }

        // Recursively root the subtree
        rootTreeDFS(child, node);

        temp = temp->next;
    }

    // After the DFS, remove the parent edge
    Node **ptr = &adjList[node];
    while (*ptr)
    {
        if ((*ptr)->vertex == parent)
        {
            Node *toDelete = *ptr;
            *ptr = (*ptr)->next;
            free(toDelete);
            break;
        }
        ptr = &(*ptr)->next;
    }
}

int main()
{
    int n, e, k;

    // Input number of nodes and edges
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &e);

    // Initialize adjacency list and visited array
    for (int i = 0; i < n; i++)
    {
        adjList[i] = NULL;
        visited[i] = 0;
    }

    // Input edges
    printf("Enter the edges (u v):\n");
    for (int i = 0; i < e; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    // Input the root node
    printf("Enter the root node: ");
    scanf("%d", &k);

    // Root the tree at node k
    rootTreeDFS(k, -1);

    // Print the rooted tree
    printRootedTree(n);

    return 0;
}
