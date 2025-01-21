#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Date structure
typedef struct {
    int day, month, year;
} Date;

// Define the Employee structure
typedef struct {
    char name[20];
    int empCode;
    int age;
    Date* date;   // Pointer to a Date structure
    float salary;
} Employee;

// Function to calculate and display retirement details
void retire(Employee* emp) {
    int currentYear = 2024; // Assuming current year as 2024
    int retYear = currentYear + (60 - emp->age); // Retirement year
    printf("\nRetirement year for %s (EmpCode: %d) is %d", emp->name, emp->empCode, retYear);

    // Calculate salary at retirement
    float sal = emp->salary;
    for (int i = currentYear; i < retYear; i++) {
        sal += 0.2 * sal; // Increment salary by 20% per year
    }
    printf("\nSalary at the time of retirement: %.2f\n", sal);
}

int main() {
    int n;
    printf("Enter number of employees: ");
    scanf("%d", &n);

    // Allocate memory for 'n' employees
    Employee* employees = (Employee*)malloc(n * sizeof(Employee));
    if (!employees) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Input details for each employee
    for (int i = 0; i < n; i++) {
        employees[i].date = (Date*)malloc(sizeof(Date)); // Allocate memory for Date
        if (!employees[i].date) {
            printf("Memory allocation failed for date!\n");
            return 1;
        }
        printf("Enter details for employee %d\n", i + 1);
        printf("Name: ");
        scanf("%s", employees[i].name);
        printf("EmpCode: ");
        scanf("%d", &employees[i].empCode);
        printf("Age: ");
        scanf("%d", &employees[i].age);
        printf("Joining Date (DD MM YYYY): ");
        scanf("%d %d %d", &employees[i].date->day, &employees[i].date->month, &employees[i].date->year);
        printf("Salary: ");
        scanf("%f", &employees[i].salary);
    }

    // Display employee details and calculate retirement info
    printf("\nEmployee Details and Retirement Information:\n");
    for (int i = 0; i < n; i++) {
        printf("\nEmployee %d:\n", i + 1);
        printf("Name: %s\n", employees[i].name);
        printf("EmpCode: %d\n", employees[i].empCode);
        printf("Age: %d\n", employees[i].age);
        printf("Joining Date: %02d/%02d/%d\n", employees[i].date->day, employees[i].date->month, employees[i].date->year);
        printf("Salary: %.2f\n", employees[i].salary);

        // Call the retire function for each employee
        retire(&employees[i]);
    }

    // Free allocated memory
    for (int i = 0; i < n; i++) {
        free(employees[i].date); // Free Date memory
    }
    free(employees); // Free Employee memory

    return 0;
}
