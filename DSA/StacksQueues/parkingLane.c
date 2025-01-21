#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 10

// Structure to represent a car
typedef struct {
    char carname[10];
    char numplate[8];
    int timesmoved;  // How many times the car was moved out of the garage
} Car;

// Stack structure for the garage
typedef struct {
    Car lane[MAX];  // Array to hold cars
    int top;        // Index of the top of the stack
} Garage;

// Function to initialize the garage
void initialize(Garage* g) {
    g->top = -1;
}

// Function to check if the garage is empty
int isEmpty(Garage* g) {
    return g->top == -1;
}

// Function to check if the garage is full
int isFull(Garage* g) {
    return g->top == MAX - 1;
}

// Function to push a car into the garage
void push(Garage* g, Car car) {
    if (isFull(g)) {
        printf("\nGarage Full. %s with plate %s can't enter.\n", car.carname, car.numplate);
    } else {
        g->top++;
        g->lane[g->top] = car;  // Add car to the garage
        printf("%s with plate %s has entered the garage.\n", car.carname, car.numplate);
    }
}

// Function to pop a car from the garage
Car pop(Garage* g) {
    Car invalidCar = {"INVALID", "0000", -1};  // Sentinel value for invalid car

    if (isEmpty(g)) {
        printf("\nGarage is empty.\n");
        return invalidCar;
    } else {
        Car car = g->lane[g->top];  // Get the car at the top of the stack
        g->top--;
        return car;
    }
}

// Function to display the current cars in the garage
void display(Garage* g) {
    if (isEmpty(g)) {
        printf("\nGarage is empty.\n");
    } else {
        printf("\nCars in the garage:\n");
        for (int i = g->top; i >= 0; i--) {
            printf("%s (%s)\n", g->lane[i].carname, g->lane[i].numplate);
        }
    }
}

// Function to handle car departure
void depart(Garage* g, char* numplate) {
    Garage tempGarage;  // Temporary stack to hold cars while we remove one
    initialize(&tempGarage);

    int found = 0;
    int moves = 0;

    // While the garage is not empty, look for the car to remove
    while (!isEmpty(g)) {
        Car currentCar = pop(g);  // Remove cars one by one

        if (strcmp(currentCar.numplate, numplate) == 0) {
            // Found the car to remove
            found = 1;
            printf("\n%s with plate %s has left the garage. It was moved %d times to allow others to depart.\n", currentCar.carname, currentCar.numplate, currentCar.timesmoved);
            break;
        } else {
            // Move other cars to the temporary garage
            currentCar.timesmoved++;  // Increase the times this car was moved
            push(&tempGarage, currentCar);
            moves++;
        }
    }

    // If the car was not found
    if (!found) {
        printf("\nCar with plate %s not found in the garage.\n", numplate);
    }

    // Restore the cars back to the main garage in the original order
    while (!isEmpty(&tempGarage)) {
        Car tempCar = pop(&tempGarage);
        push(g, tempCar);
    }
}

int main() {
    Garage garage;
    initialize(&garage);  // Initialize the garage

    char ch;
    do {
        printf("\nWhat would you like to do? (A for Arrival, D for Departure, Q to Quit): ");
        scanf(" %c", &ch);  // Note the space before %c to ignore any newline characters

        if (ch == 'A') {
            // Handle arrival
            char name[10], numplate[8];
            printf("Enter car name: ");
            scanf("%s", name);
            printf("Enter plate number: ");
            scanf("%s", numplate);

            Car car = {name, numplate, 0};  // New car with 0 times moved initially
            push(&garage, car);  // Push the car into the garage

        } else if (ch == 'D') {
            // Handle departure
            char numplate[8];
            printf("Enter the plate number of the car to depart: ");
            scanf("%s", numplate);

            depart(&garage, numplate);  // Remove the car from the garage

        } else if (ch == 'Q') {
            // Quit the program
            printf("Exiting...\n");
        } else {
            printf("Invalid input. Please enter A, D, or Q.\n");
        }

        display(&garage);  // Display the current state of the garage

    } while (ch != 'Q');

    return 0;
}
