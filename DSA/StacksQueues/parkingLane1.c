#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 10

// Structure to represent a car
typedef struct {
    char carname[10];
    char license_plate[8];
    int times_moved;  // How many times the car was moved
} Car;

// Stack structure for the garage
typedef struct {
    Car lane[MAX];  // Array to hold cars
    int top;        // Index of the top of the stack
} Garage;

// Function to initialize the garage
void initialize(Garage* g) {
    g->top = -1;  // Set top to -1 (garage is empty)
}

// Function to check if the garage is full
int isFull(Garage* g) {
    return g->top == MAX - 1;
}

// Function to check if the garage is empty
int isEmpty(Garage* g) {
    return g->top == -1;
}

// Function to park a car in the garage (push operation)
void parkCar(Garage* g, Car car) {
    if (isFull(g)) {
        printf("Cannot park car with license plate %s: garage is full.\n", car.license_plate);
    } else {
        printf("Parking car with license plate %s.\n", car.license_plate);
        g->top++;  // Increment the top index
        g->lane[g->top] = car;  // Directly assign the car to the top of the garage
    }
}

// Function to remove a car from the garage and shift remaining cars
void retrieveCar(Garage* g, char* license_plate) {
    int car_index = -1;

    // Find the car in the garage by license plate
    for (int i = 0; i <= g->top; i++) {
        if (strcmp(g->lane[i].license_plate, license_plate) == 0) {
            car_index = i;
            break;
        }
    }

    if (car_index == -1) {
        printf("Cannot find car with license plate %s: not found in garage.\n", license_plate);
    } else {
        // Retrieve the car
        printf("Retrieving car with license plate %s (moved %d times).\n", g->lane[car_index].license_plate, g->lane[car_index].times_moved);

        // Shift the remaining cars after the departing car
        for (int i = car_index; i < g->top; i++) {
            g->lane[i] = g->lane[i + 1];  // Move the next car forward
            g->lane[i].times_moved++;  // Increment the number of times the car was moved
        }

        g->top--;  // Decrement the top index after the car is removed
    }
}

// Function to display the cars in the garage
void display(Garage* g) {
    if (isEmpty(g)) {
        printf("\nGarage is empty.\n");
    } else {
        printf("\nCars currently in the garage:\n");
        for (int i = 0; i <= g->top; i++) {
            printf("%s (Plate: %s, Moved: %d times)\n", g->lane[i].carname, g->lane[i].license_plate, g->lane[i].times_moved);
        }
    }
}

int main() {
    Garage garage;
    initialize(&garage);

    char action;
    Car car;

    do {
        printf("\nWhat would you like to do? (A for Arrival, D for Departure, Q to Quit): ");
        scanf(" %c", &action);  // Note the space before %c to ignore newline characters

        if (action == 'A') {
            // A car is arriving
            printf("Enter car name: ");
            scanf("%s", car.carname);
            printf("Enter license plate: ");
            scanf("%s", car.license_plate);
            car.times_moved = 0;  // Initialize times_moved for the new car

            parkCar(&garage, car);  // Park the car

        } else if (action == 'D') {
            // A car is departing
            printf("Enter the license plate of the car to retrieve: ");
            scanf("%s", car.license_plate);

            retrieveCar(&garage, car.license_plate);  // Retrieve the car

        } else if (action == 'Q') {
            printf("Exiting the program.\n");
        } else {
            printf("Invalid action. Please enter A, D, or Q.\n");
        }

        display(&garage);  // Display the current state of the garage

    } while (action != 'Q');

    return 0;
}
