#include <stdio.h>
#include "structCarRental.h"
#include "emptyCarGenerator.h"

// Define color codes
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"
#define CYAN "\033[1;36m"
#define RESET "\033[1;0m"

void printCarDetails(Car_Rental *car) {

    printf("\n\033[1;34m+------------------------+\033[0m\n");
    printf("\033[1;34m|     Car Rental Details |\033[0m\n");
    printf("\033[1;34m+------------------------+\033[0m\n");
    printf (GREEN"username: %s\n", car->username);
    printf (GREEN"id: %d\n", car->id);
    printf (GREEN"city: %s\n", car->city_name);
    printf("\n\033[1;32mTotal Cars: %u\n", car->n_total_cars);
    printf("Available Cars: %u\n", car->available_cars);
    printf("Booked Cars: %u\n", car->booked_cars);
    printf("\033[1;34m------------------------\033[0m\n");
    printf("\033[1;34m          SUV Cars        \033[0m\n");
    printf("\033[1;34m------------------------\033[0m\n");
    printf("\033[1;32mAvailable Cars: %u\n", car->n_suv);
    for (unsigned int i = 0; i < car->n_suv; ++i) {
        printf("Model: %u, Price: %u, Name: %s\n", car->suv[i].modal, car->suv[i].price, car->suv[i].name);
    }
    printf("\033[1;34m------------------------\033[0m\n");
    printf("\033[1;34m      Non-SUV Cars       \033[0m\n");
    printf("\033[1;34m------------------------\033[0m\n");
    printf("\033[1;32mAvailable Cars: %u\n", car->n_non_suv);
    for (unsigned int i = 0; i < car->n_non_suv; ++i) {
        printf("Model: %u, Price: %u, Name: %s\n", car->non_suv[i].modal, car->non_suv[i].price, car->non_suv[i].name);
    }
    printf("\033[1;34m------------------------\033[0m\n");
    printf("\033[1;34m      Premium Cars       \033[0m\n");
    printf("\033[1;34m------------------------\033[0m\n");
    printf("\033[1;32mAvailable Cars: %u\n", car->n_premium);
    for (unsigned int i = 0; i < car->n_premium; ++i) {
        printf("Model: %u, Price: %u, Name: %s\n", car->premium[i].modal, car->premium[i].price, car->premium[i].name);
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
        Car_Rental car = generate_empty_car();

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