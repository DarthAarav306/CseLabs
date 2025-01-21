#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Structure for a doubly linked list node
typedef struct Node {
    char expression[50];   // Store the tag or expression
    int result;            // Store the result for expression nodes
    struct Node* prev;     // Pointer to the previous node
    struct Node* next;     // Pointer to the next node
} Node;

// Function to create a new node (either for tag or expression)
Node* createNode(char* expression, int result) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->expression, expression);
    newNode->result = result;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a tag node followed by its expression node at the beginning of the list
void Insert(Node** head, char* tag, char* expression) {
    // Create the expression node with result initialized to -1
    Node* expressionNode = createNode(expression, -1);

    // Create the tag node
    Node* tagNode = createNode(tag, -1);

    // Link the nodes together (tag -> expression)
    tagNode->next = expressionNode;
    expressionNode->prev = tagNode;

    // Insert the new nodes at the head of the list
    tagNode->next->next = *head;  // Set the next of the expression node to current head
    if (*head != NULL) {
        (*head)->prev = tagNode->next;  // Adjust the previous link of the old head
    }
    *head = tagNode;  // Update the head to the tag node
}

// Function to display the doubly linked list
void Display(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->result == -1) {
            printf("%s -> ", temp->expression);  // Display the tag node
        } else {
            printf("%s = %d -> ", temp->expression, temp->result);  // Display expression and result
        }
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to check if an expression has balanced parentheses
int CheckExpression(char* expression) {
    int stack[50];  // Simple stack to store parentheses
    int top = -1;
    
    for (int i = 0; i < strlen(expression); i++) {
        if (expression[i] == '(') {
            stack[++top] = '(';
        } else if (expression[i] == ')') {
            if (top == -1) return 0;  // Unmatched closing parenthesis
            top--;
        }
    }
    
    return top == -1;  // If stack is empty, parentheses are balanced
}

// Function to compute both postfix and prefix expressions
int Compute(char* expression, int isPrefix) {
    int stack[50];  // Stack to evaluate the expression
    int top = -1;
    int length = strlen(expression);
    
    if (isPrefix) {
        // Evaluate from right to left for prefix
        for (int i = length - 1; i >= 0; i--) {
            if (isdigit(expression[i])) {
                stack[++top] = expression[i] - '0';  // Push operand to stack
            } else {
                int operand1 = stack[top--];
                int operand2 = stack[top--];
                switch (expression[i]) {
                    case '+': stack[++top] = operand1 + operand2; break;
                    case '-': stack[++top] = operand1 - operand2; break;
                    case '*': stack[++top] = operand1 * operand2; break;
                    case '/': stack[++top] = operand1 / operand2; break;
                }
            }
        }
    } else {
        // Evaluate from left to right for postfix
        for (int i = 0; i < length; i++) {
            if (isdigit(expression[i])) {
                stack[++top] = expression[i] - '0';  // Push operand to stack
            } else {
                int operand2 = stack[top--];
                int operand1 = stack[top--];
                switch (expression[i]) {
                    case '+': stack[++top] = operand1 + operand2; break;
                    case '-': stack[++top] = operand1 - operand2; break;
                    case '*': stack[++top] = operand1 * operand2; break;
                    case '/': stack[++top] = operand1 / operand2; break;
                }
            }
        }
    }
    
    return stack[top];  // Final result
}

// Function to process the list and compute expression results
void ProcessList(Node* head) {
    Node* temp = head;
    
    while (temp != NULL && temp->next != NULL) {
        // Process the <TEST> tag and check for balanced parentheses
        if (strcmp(temp->expression, "<TEST>") == 0) {
            if (CheckExpression(temp->next->expression)) {
                temp->next->result = 1;  // Balanced parentheses
            } else {
                temp->next->result = 0;  // Unbalanced parentheses
            }
        }
        // Process the <POSTFIX> and <PREFIX> tags and compute the expression result
        else if (strcmp(temp->expression, "<POSTFIX>") == 0) {
            temp->next->result = Compute(temp->next->expression, 0);  // Pass 0 for postfix
        } else if (strcmp(temp->expression, "<PREFIX>") == 0) {
            temp->next->result = Compute(temp->next->expression, 1);  // Pass 1 for prefix
        }

        // Move to the next pair of tag and expression nodes
        temp = temp->next->next;
    }
}

// Main function
int main() {
    Node* head = NULL;  // Initialize the doubly linked list
    int choice;
    char tag[20], expression[50];
    
    do {
        printf("\nMenu:\n1. Insert expression\n2. Display list\n3. Process expressions\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter tag (<TEST>, <POSTFIX>, <PREFIX>): ");
                scanf("%s", tag);  // Read tag

                printf("Enter expression: ");
                scanf("%s", expression);  // Read expression

                Insert(&head, tag, expression);  // Insert tag and expression as separate nodes
                break;
            case 2:
                Display(head);
                break;
            case 3:
                ProcessList(head);  // Process and update the list
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 4);
    
    return 0;
}
