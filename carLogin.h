#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>




bool car_check_credentials (unsigned int id, char *username, unsigned const int hotel_id, const char *hotel_username){

    if( (strcmp (username, hotel_username)) == 0 ) {
        return true;
    }
    
    return false;
}




bool car_login ( unsigned int id, char *username ) {    

    // making a file pointer for our hotels.dat
    FILE *cfptr;

    if (( cfptr = fopen ("cars.dat", "rb")) == NULL) { // checking either the file is opened or not
        puts ("FIle can not be opened.");
        exit (EXIT_SUCCESS);
    }

    // creating an empty hotel
    Car_Rental car = generate_empty_car();

    fseek (cfptr, (id-1) * sizeof (Car_Rental), SEEK_SET); // offsetting the pointer
    fread (&car, sizeof(Car_Rental), 1, cfptr); // reading the values

    // checking whether the credentials are correct or not
    if ( car_check_credentials(id, username, car.id, car.username)) {

        printf ("Logged in\n");
        fclose (cfptr);
        return true;
    } 

    // IF THE CREDENTIALS ARE NOT CORRECT THEN RETURNING FLASE
    puts ("Invalid credentials\n");
    fclose (cfptr);
    return false;
}