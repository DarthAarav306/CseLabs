#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Node structure for adjacency list
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

// Queue structure for BFS
typedef struct Queue {
    int items[MAX];
    int front, rear;
} Queue;

// Function to create a node
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

// Queue functions
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = -1;
    return q;
}

int isEmpty(Queue* q) {
    return q->rear == -1;
}

void enqueue(Queue* q, int value) {
    if (q->rear == MAX - 1)
        printf("Queue is full\n");
    else {
        if (q->front == -1)
            q->front = 0;
        q->rear++;
        q->items[q->rear] = value;
    }
}

int dequeue(Queue* q) {
    int item;
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        item = -1;
    } else {
        item = q->items[q->front];
        q->front++;
        if (q->front > q->rear) {
            q->front = q->rear = -1;
        }
    }
    return item;
}

// BFS function
void BFS(Graph* graph, int startVertex) {
    Queue* q = createQueue();

    graph->visited[startVertex] = 1;
    enqueue(q, startVertex);

    printf("BFS starting from vertex %d:\n", startVertex);

    while (!isEmpty(q)) {
        int currentVertex = dequeue(q);
        printf("%d ", currentVertex);

        Node* temp = graph->adjLists[currentVertex];
        while (temp) {
            int adjVertex = temp->vertex;

            if (graph->visited[adjVertex] == 0) {
                graph->visited[adjVertex] = 1;
                enqueue(q, adjVertex);
            }
            temp = temp->next;
        }
    }
    printf("\n");
}
void bfs(Graph* g, int vertex) {
    int queue[100];
    int front = -1;
    int rear = -1;

    // Mark the starting vertex as visited and enqueue it
    g->visited[vertex] = 1;
    front++;
    rear++;
    queue[rear] = vertex;

    printf("Starting BFS:- ");
    while (front != -1 && front <= rear) {
        // Dequeue
        int currentVertex = queue[front];
        front++;
        if (front > rear) {
            front = rear = -1; // Reset the queue when empty
        }

        // Process the current vertex
        printf("%d ", currentVertex);

        // Enqueue all unvisited neighbors
        Node* temp = g->adjLists[currentVertex];
        while (temp) {
            if (g->visited[temp->vertex] == 0) {
                g->visited[temp->vertex] = 1;
                rear++;
                queue[rear] = temp->vertex; // Add the neighbor to the queue
            }
            temp = temp->next;
        }
    }
}


int main() {
    int vertices, edges, src, dest, startVertex;

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

    printf("Enter the starting vertex for BFS: ");
    scanf("%d", &startVertex);

    BFS(graph, startVertex);

    return 0;
}


void bfs(Graph* g, int vertex)
{
    Queue q;
    init(&q);
    g->visited[vertex] = 1;
    printf("Starting BFS:- ");
    while(!isEmpty(&q))
    {
        int currentVertex = dequeue(&q);
        printf("%d",currentVertex);
        Node* temp = g->adjLists[currentVertex];
        while(temp)
        {
            if(g->visited[temp->vertex]==0)
            {
                g->visited[temp->vertex]=1;
                enqueue(&q,temp->vertex);
            }
            temp = temp->next;
        }
    }
}