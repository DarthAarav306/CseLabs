#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a student record
typedef struct Student {
    int roll_no;
    char name[50];
    char section[10];
    float cgpa;
    char phone[15];
    struct Student* left;
    struct Student* right;
} Student;

// Function to create a new student record node
Student* createStudent(int roll_no, char* name, char* section, float cgpa, char* phone) {
    Student* newStudent = (Student*)malloc(sizeof(Student));
    newStudent->roll_no = roll_no;
    strcpy(newStudent->name, name);
    strcpy(newStudent->section, section);
    newStudent->cgpa = cgpa;
    strcpy(newStudent->phone, phone);
    newStudent->left = newStudent->right = NULL;
    return newStudent;
}

// Function to insert a student record into the BST
Student* insertStudent(Student* root, int roll_no, char* name, char* section, float cgpa, char* phone) {
    if (root == NULL) {
        return createStudent(roll_no, name, section, cgpa, phone);
    }

    if (roll_no < root->roll_no) {
        root->left = insertStudent(root->left, roll_no, name, section, cgpa, phone);
    } else if (roll_no > root->roll_no) {
        root->right = insertStudent(root->right, roll_no, name, section, cgpa, phone);
    } else {
        printf("Duplicate roll number %d. Record not inserted.\n", roll_no);
    }

    return root;
}

// Function to search for a student record by roll number
Student* searchStudent(Student* root, int roll_no) {
    while (root != NULL) {
        if (roll_no < root->roll_no) {
            root = root->left;
        } else if (roll_no > root->roll_no) {
            root = root->right;
        } else {
            return root; // Record found
        }
    }
    return NULL; // Record not found
}

// Function to display a student record
void displayStudent(Student* student) {
    if (student == NULL) return;
    printf("Roll No: %d\n", student->roll_no);
    printf("Name: %s\n", student->name);
    printf("Section: %s\n", student->section);
    printf("CGPA: %.2f\n", student->cgpa);
    printf("Phone: %s\n", student->phone);
    printf("\n");
}

// In-order traversal to display all student records
void displayAllStudents(Student* root) {
    if (root == NULL) return;
    displayAllStudents(root->left);
    displayStudent(root);
    displayAllStudents(root->right);
}

// Main function
int main() {
    Student* root = NULL;
    int choice, roll_no;
    char name[50], section[10], phone[15];
    float cgpa;

    printf("Student Phone Book Application:\n");
    do {
        printf("\nMenu:\n");
        printf("1. Add Student Record\n");
        printf("2. Search Student Record by Roll No\n");
        printf("3. Display All Student Records\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter roll number: ");
                scanf("%d", &roll_no);
                printf("Enter name: ");
                scanf(" %[^\n]%*c", name);
                printf("Enter section: ");
                scanf(" %s", section);
                printf("Enter CGPA: ");
                scanf("%f", &cgpa);
                printf("Enter phone number: ");
                scanf(" %s", phone);
                root = insertStudent(root, roll_no, name, section, cgpa, phone);
                printf("Student record added.\n");
                break;

            case 2:
                printf("Enter roll number to search: ");
                scanf("%d", &roll_no);
                Student* student = searchStudent(root, roll_no);
                if (student) {
                    printf("Student record found:\n");
                    displayStudent(student);
                } else {
                    printf("Student record with roll number %d not found.\n", roll_no);
                }
                break;

            case 3:
                printf("Displaying all student records:\n");
                displayAllStudents(root);
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
