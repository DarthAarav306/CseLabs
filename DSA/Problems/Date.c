#include <stdio.h>
#include <stdlib.h>

// Define the Date structure
typedef struct {
    int day;
    int month;
    int year;
} Date;

// Function to check if a year is a leap year
int isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        return 1; // Leap year
    }
    return 0; // Not a leap year
}

// Function to get the number of days in a month
int getDaysInMonth(int month, int year) {
    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31; // Months with 31 days
        case 4: case 6: case 9: case 11:
            return 30; // Months with 30 days
        case 2:
            return isLeapYear(year) ? 29 : 28; // February
        default:
            return 0; // Invalid month
    }
}

// Function to increment the date by 1 day
void increment(Date* date) {
    int daysInMonth = getDaysInMonth(date->month, date->year);

    if (date->day < daysInMonth)
    {
        date->day++; // Increment the day
    }
    else 
    {
        date->day = 1; // Reset day to 1
        if (date->month == 12) {
            date->month = 1; // Reset month to January
            date->year++;    // Increment the year
        } else {
            date->month++; // Move to the next month
        }
    }
}

// Function to display the date
void displayDate(const Date* date) {
    printf("%02d/%02d/%04d\n", date->day, date->month, date->year);
}

int main() {
    // Dynamically allocate memory for the Date structure
    Date* date = (Date*)malloc(sizeof(Date));
    if (!date) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Input the date
    printf("Enter date (DD MM YYYY): ");
    scanf("%d %d %d", &date->day, &date->month, &date->year);

    printf("Original Date: ");
    displayDate(date);

    // Increment the date by 1 day
    increment(date);

    printf("Incremented Date: ");
    displayDate(date);

    // Free allocated memory
    free(date);

    return 0;
}
