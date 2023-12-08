#include <stdio.h>
// #include "structHotel.h"

void hotel_init ( int max_hotels) {
    
    // ?creating file pointer for hotels.dat
    FILE *fptr;

    if ( (fptr = fopen ("hotels.dat", "wb")) == NULL) {
        puts ("File can not be opened.");
        return;
    }

    Hotel empty_hotel = {0, "", "", 0, 0, 0, 0, 0, 0, 0, 0, 0};

    for ( unsigned int i = 0 ; i < max_hotels; i++) {
        fwrite (&empty_hotel, sizeof (Hotel), 1, fptr);
    }

    fclose ( fptr );


    
}