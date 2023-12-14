#include <stdio.h>
#include "structCarRental.h"

void printCarDetails( const Car_Rental *car ) {
    printf("\n\033[1;34m+----------------------------------+\033[0m\n"); // Blue box
    printf("\033[1;34m|             Car Details          |\033[0m\n"); // Blue box
    printf("\033[1;34m+----------------------------------+\033[0m\n"); // Blue box
    printf("\033[1;32mHotel ID: %u\n", car->id);
    printf("Username: %s\n", car->username);
    printf("Company name: %s\n", car->company_name);
    printf("City Name: %s\n", car->city_name);
    printf("\033[1;34m+----------------------------------+\033[0m\n");
}

void hotel_read( void ) {
    // making a file pointer for hotels.dat
    FILE *cfptr;

    if ((cfptr = fopen("cars.dat", "rb")) == NULL) { // checking for opening file
        puts("File can not be opened.");
        return;
    }

    while (!feof(cfptr)) {
        // reading the data
        Car_Rental car = {0, "", "", "", 0, 0, 0, 0, 0, 0, "", 0, 0, 0, "" ,0 ,0 ,0, ""};

        int result = fread( &car, sizeof(Car_Rental), 1, cfptr );
        // displaying the data
        if (result != 0 && car.id != 0) {
            printCarDetails( &car );
        }
    }

    fclose(cfptr);
}

int main ( void ) {

    hotel_read ();
    return 0;
}