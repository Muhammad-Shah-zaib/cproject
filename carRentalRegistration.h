#include <stdio.h>
#include <stdlib.h>
#include "structCarRental.h"




int extract_car_id ( void ) {
    FILE *idfptr;

    if ( (idfptr = fopen ("carid.txt", "r")) == NULL) {
        puts ("File can not be opened");
        exit(EXIT_SUCCESS);
    }
    int id;
    fscanf (idfptr, "%d", &id);

    fclose (idfptr);
    // printf ("%d", id);
    return id;
}






// ! UPDATING OUR ID FILE


void update_car_id ( int id ) {
    FILE *idfptr;

    if ( (idfptr = fopen ("carid.txt", "w")) == NULL) {
        puts ("File can not be opened");
        exit(EXIT_SUCCESS);
    }

    fprintf (idfptr, "%d", id);

    fclose (idfptr);
}





void car_rental_registration ( void ){

    FILE *cfptr; // car file pointer

    if ( (cfptr = fopen("cars.dat", "rb+")) == NULL ) {
        puts ("FIle can not be opened!");
        return;
    }

    Car_Rental car = {0, "", "", "", 0, 0, 0, 0, 0, 0, "", 0, 0, 0, "" ,0 ,0 ,0, ""};
    

    // Providing th eunique id
    unsigned short int id = extract_car_id ();

    car.id = id;
    ++id;

    update_car_id( id );


    printf ("Enter your user name: ");
    scanf("%s", car.username);

    printf ("Enter your company name: ");
    scanf("%s", car.company_name);

    printf ("Enter your city name: ");
    scanf("%s", car.city_name);

    fseek ( cfptr, (id - 1) * sizeof (Car_Rental), SEEK_SET );
    fwrite( &car, sizeof (Car_Rental), 1, cfptr );
    fflush (cfptr);

    printf ("Remember your following credentials, you need them while logging in.\n");
    printf ("=>id: %d", car.id);
    printf ("=>username: %s", car.username);
    fclose ( cfptr );
}