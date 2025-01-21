void printChars() {
    char arr[26];          // Array to hold the alphabets
    char* ptr = arr;       // Pointer to traverse the array

    // Populate the array with alphabets 'A' to 'Z'
    for (int i = 0; i < 26; i++) {
        *ptr = i + 'A';    // Assign each alphabet
        ptr++;             // Move the pointer to the next array element
    }

    ptr = arr;             // Reset pointer back to the start of the array

    // Print the alphabets
    for (int i = 0; i < 26; i++) {
        printf("%c ", *(ptr + i));  // Access each element using pointer arithmetic
    }
    printf("\n");
}
