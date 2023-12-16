#include <stdio.h>
#include "structCarRental.h"
#include "emptyCarGenerator.h"

// Define color codes
#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"
#define RESET "\x1b[0m"

void printCarDetails( const Car_Rental *car ) {
    printf(BLUE "Car Rental Details:\n" RESET);
    printf("ID: %u\n", car->id);
    printf("Username: %s\n", car->username);
    printf("Company Name: %s\n", car->company_name);
    printf("City Name: %s\n", car->city_name);
    printf("Total Cars: %u\n", car->n_total_cars);
    printf("Booked Cars: %u\n", car->booked_cars);
    printf("Available Cars: %u\n", car->available_cars);

    // Display SUV details
    printf("\n" GREEN "SUV Cars:\n" RESET);
    for (unsigned int i = 0; i < (car->n_suv); ++i) {
        printf("Modal: %u, Price: %u, Name: %s\n", car->suv[i].modal, car->suv[i].price, car->suv[i].name);
    }

    // Display Non-SUV details
    printf("\n" YELLOW "Non-SUV Cars:\n" RESET);
    for (unsigned int i = 0; i < (car->n_non_suv); ++i) {
        printf("Modal: %u, Price: %u, Name: %s\n", car->non_suv[i].modal, car->non_suv[i].price, car->non_suv[i].name);
    }

    // Display Premium details
    printf("\n" RED "Premium Cars:\n" RESET);
    for (unsigned int i = 0; i < (car->n_premium); ++i) {
        printf("Modal: %u, Price: %u, Name: %s\n", car->premium[i].modal, car->premium[i].price, car->premium[i].name);
    }
}

void car_read( void ) {
    // making a file pointer for hotels.dat
    FILE *cfptr;

    if ((cfptr = fopen("cars.dat", "rb")) == NULL) { // checking for opening file
        puts("File can not be opened.");
        return;
    }

    while (!feof(cfptr)) {
        // reading the data
        Car_Rental car = generate_empty_car();;

        int result = fread( &car, sizeof(Car_Rental), 1, cfptr );
        // displaying the data
        if (result != 0 && car.id != 0) {
            printCarDetails( &car );
        }
    }

    fclose(cfptr);
}

int main ( void ) {

    car_read ();
    return 0;
}