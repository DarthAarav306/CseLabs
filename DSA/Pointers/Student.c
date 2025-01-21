#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
    int reg_no;
    char* name;
    char address[100];
} STU_INFO;

typedef struct
{
    char* college_name;
    char university_name[100];
} COLLEGE;

typedef struct
{
    DOB* dob;
    STU_INFO stuinfo;
    COLLEGE college;
} STUDENT;

int main()
{
    STUDENT* student;
    
    // Creating student structure
    student = (STUDENT*)malloc(sizeof(STUDENT));
    
    // Creating Dob structure in student
    student->dob = (DOB*)malloc(sizeof(DOB));
    
    // Allocating memory for month
    student->dob->month = (int*)malloc(sizeof(int));
    
    // Allocating memory for name and college_name
    student->stuinfo.name = (char*)malloc(100 * sizeof(char));
    student->college.college_name = (char*)malloc(100 * sizeof(char));
    
    // Reading DOB
    printf("Enter DOB:\n");
    printf("Enter day: ");
    scanf("%d", &(student->dob->day));
    printf("Enter month: ");
    scanf("%d", student->dob->month);
    printf("Enter year: ");
    scanf("%d", &(student->dob->year));
    
    // Reading Student Information
    printf("\nEnter Student Information:\n");
    printf("Enter registration number: ");
    scanf("%d", &(student->stuinfo.reg_no));
    printf("Enter name: ");
    scanf("%s", student->stuinfo.name);
    printf("Enter address: ");
    scanf(" %[^\n]%*c", student->stuinfo.address);  // To read the full line
    
    // Reading College Information
    printf("\nEnter College Information:\n");
    printf("Enter college name: ");
    scanf("%s", student->college.college_name);
    printf("Enter university name: ");
    scanf("%s", student->college.university_name);
    
    // Displaying DOB
    printf("\nDisplaying DOB:\n");
    printf("Day: %d\n", student->dob->day);
    printf("Month: %d\n", *(student->dob->month));
    printf("Year: %d\n", student->dob->year);
    
    // Displaying Student Information
    printf("\nDisplaying Student Information:\n");
    printf("Registration Number: %d\n", student->stuinfo.reg_no);
    printf("Name: %s\n", student->stuinfo.name);
    printf("Address: %s\n", student->stuinfo.address);
    
    // Displaying College Information
    printf("\nDisplaying College Information:\n");
    printf("College Name: %s\n", student->college.college_name);
    printf("University Name: %s\n", student->college.university_name);
    
    // Freeing allocated memory
    free(student->dob->month);
    free(student->dob);
    free(student->stuinfo.name);
    free(student->college.college_name);
    free(student);

    return 0;
}
