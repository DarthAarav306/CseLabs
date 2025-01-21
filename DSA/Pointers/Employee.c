#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for Date of Birth
typedef struct {
    int day;
    int month;
    int year;
} DateOfBirth;

// Define the structure for Address
typedef struct {
    int houseNumber;
    int zipCode;
    char state[50];
} Address;

// Define the structure for Employee
typedef struct {
    char name[100];
    DateOfBirth dob;   // Nested structure for date of birth
    Address address;   // Nested structure for address
} Employee;

// Function to input employee data
void inputEmployeeData(Employee* emp, int n) {
    for (int i = 0; i < n; i++) {
        printf("\nEnter details of employee %d:\n", i + 1);

        // Input name
        printf("Enter Name: ");
        scanf(" %[^\n]", emp[i].name);  // Read string with spaces

        // Input Date of Birth
        printf("Enter Date of Birth (dd mm yyyy): ");
        scanf("%d %d %d", &emp[i].dob.day, &emp[i].dob.month, &emp[i].dob.year);

        // Input Address
        printf("Enter House Number: ");
        scanf("%d", &emp[i].address.houseNumber);
        printf("Enter Zip Code: ");
        scanf("%d", &emp[i].address.zipCode);
        printf("Enter State: ");
        scanf(" %[^\n]", emp[i].address.state);  // Read string with spaces
    }
}

// Function to display employee data
void displayEmployeeData(Employee* emp, int n) {
    printf("\nEmployee Data:\n");
    for (int i = 0; i < n; i++) {
        printf("\nEmployee %d\n", i + 1);
        printf("Name: %s\n", emp[i].name);
        printf("Date of Birth: %02d/%02d/%d\n", emp[i].dob.day, emp[i].dob.month, emp[i].dob.year);
        printf("Address: House Number: %d, Zip Code: %d, State: %s\n",
               emp[i].address.houseNumber, emp[i].address.zipCode, emp[i].address.state);
    }
}

int main() {
    int n;

    // Input number of employees
    printf("Enter the number of employees: ");
    scanf("%d", &n);

    // Allocate memory dynamically for n employees using pointers
    Employee* employees = (Employee*)malloc(n * sizeof(Employee));

    // Input data for employees
    inputEmployeeData(employees, n);

    // Display data of employees
    displayEmployeeData(employees, n);

    // Free the allocated memory
    free(employees);

    return 0;
}
