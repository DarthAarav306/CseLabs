#include <stdio.h>
#include <string.h>

// Function to perform brute-force string matching
void bruteForceStringMatch(char text[], char pattern[])
{
    int n = strlen(text);
    int m = strlen(pattern);
    int comparisons = 0; // Count comparisons

    printf("Pattern found at indices: ");
    int found = 0;

    // Try every possible alignment of pattern in text
    for (int i = 0; i <= n - m; i++)
    {
        int j;
        // Compare pattern with text at current alignment
        for (j = 0; j < m; j++)
        {
            comparisons++; // Increment comparison count
            if (text[i + j] != pattern[j])
                break; // Stop if a mismatch occurs
        }
        // If full pattern matched
        if (j == m)
        {
            printf("%d ", i); // Print the first match index
            found = 1;
            break; // Stop after the first match
        }
    }

    if (!found)
        printf("Not found");

    printf("\nTotal Comparisons: %d\n", comparisons);
}

int main()
{
    char text[100], pattern[50];

    // Input text and pattern
    printf("Enter the text: ");
    scanf("%s", text);
    printf("Enter the pattern to search: ");
    scanf("%s", pattern);

    // Perform brute-force string matching
    bruteForceStringMatch(text, pattern);

    return 0;
}
