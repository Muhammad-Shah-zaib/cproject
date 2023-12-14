#include <stdio.h>
#include "structCarRental.h"

void car_init ( int max_cars ) {
    
    // ?creating file pointer for hotels.dat
    FILE *cfptr;

    if ( (cfptr = fopen ("cars.dat", "wb")) == NULL) {
        puts ("File can not be opened.");
        return;
    }

    Car_Rental empty_car = {0, "", "", "", 0, 0, 0, 0, 0, 0, "", 0, 0, 0, "" ,0 ,0 ,0, ""};

    for ( unsigned int i = 0 ; i < max_cars; i++) {
        fwrite (&empty_car, sizeof (Car_Rental), 1, cfptr);
    }

    fclose ( cfptr );


    
}

int main ( void ) {

    car_init( MAX_CAR_RENTAL );


    return 0;
}