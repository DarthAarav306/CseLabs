#include<stdio.h>

void rstrcopy(char* destination, char* source) {
    if (*source == '\0') {
        *destination = '\0';  // Ensure the null terminator is copied
        return;
    } else {
        *destination = *source;
        rstrcopy(destination + 1, source + 1);
    }
}

int main() {
    char source[100], destination[100];
    printf("Enter a string: ");
    scanf("%s", source);
    
    printf("\nSource: %s", source);
    
    rstrcopy(destination, source);
    
    printf("\nCopied string: %s\n", destination);
    
    return 0;
}
