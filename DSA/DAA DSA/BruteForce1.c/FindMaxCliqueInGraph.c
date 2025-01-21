#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MAX_NODES 20 // Limiting to small graphs due to brute-force complexity

int graph[MAX_NODES][MAX_NODES]; // Adjacency matrix
int maxClique[MAX_NODES];        // Stores the maximal clique
int maxCliqueSize = 0;           // Stores size of the maximal clique

// Function to check if a given subset forms a clique
bool isClique(int n, int subset[], int subsetSize)
{
    for (int i = 0; i < subsetSize; i++)
    {
        for (int j = i + 1; j < subsetSize; j++)
        {
            if (graph[subset[i]][subset[j]] == 0)
            {
                return false; // If any pair is not connected, not a clique
            }
        }
    }
    return true;
}

// Function to find maximal clique using brute-force
void findMaximalClique(int n)
{
    int totalSubsets = (1 << n); // 2^n subsets
    int subset[MAX_NODES];

    for (int mask = 0; mask < totalSubsets; mask++)
    {
        int subsetSize = 0;

        // Generate subset from bitmask
        for (int i = 0; i < n; i++)
        {
            if (mask & (1 << i))
            {
                subset[subsetSize++] = i;
            }
        }

        // Check if the subset forms a clique
        if (isClique(n, subset, subsetSize))
        {
            // Update maximal clique if the current one is larger
            if (subsetSize > maxCliqueSize)
            {
                maxCliqueSize = subsetSize;
                for (int i = 0; i < subsetSize; i++)
                {
                    maxClique[i] = subset[i];
                }
            }
        }
    }

    // Print the maximal clique
    printf("Maximal Clique Size: %d\n", maxCliqueSize);
    printf("Nodes in Maximal Clique: ");
    for (int i = 0; i < maxCliqueSize; i++)
    {
        printf("%d ", maxClique[i] + 1); // Convert 0-based index to 1-based
    }
    printf("\n");
}

// Function to read adjacency matrix input
void readGraph(int n)
{
    printf("Enter the adjacency matrix (%dx%d):\n", n, n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }
}

// Main function
int main()
{
    int n;
    printf("Enter the number of vertices (<= %d): ", MAX_NODES);
    scanf("%d", &n);

    if (n > MAX_NODES)
    {
        printf("Number of vertices too large for brute-force approach!\n");
        return 1;
    }

    readGraph(n);
    findMaximalClique(n);

    return 0;
}
