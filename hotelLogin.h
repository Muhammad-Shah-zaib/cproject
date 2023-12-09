#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
// #include "structHotel.h"

void prompt (int *id, char *username) {
    
    printf ("%s", "Enter your id: ");
    scanf ("%d", id);

    printf ("%s", "Enter your username: ");
    scanf ("%s", username);

}


bool check_credentials (unsigned int id, char *username, unsigned int hotel_id, char*hotel_username){

    if( (strcmp (username, hotel_username)) == 0 ) {
        // printf ("Logged in!\n");
        return true;
    }
    return false;
}




bool hotel_login ( void ) {
    // declairing the variables
    unsigned int id;
    char username[30];
    
    // getting the id and username
    prompt ( &id , username);


    // making a file pointer for our hotels.dat
    FILE *fptr;

    if (( fptr = fopen ("hotels.dat", "rb")) == NULL) { // checking either the file is opened or not
        puts ("FIle can not be opened.");
        exit (EXIT_SUCCESS);
    }

    // creating an empty hotel
    Hotel hotel = {0, "", "", 0, 0, 0, 0, 0, 0, 0, 0, 0};

    fseek (fptr, (id-1) * sizeof (Hotel), SEEK_SET); // offsetting the pointer
    fread (&hotel, sizeof(Hotel), 1, fptr); // reading the values

    // checking whether the credentials are correct or not
    if ( check_credentials(id, username, hotel.id, hotel.username)) {

        printf ("Logged in\n");
        fclose (fptr);
        return true;
    } 

    // IF THE CREDENTIALS ARE NOT CORRECT THEN RETURNING FLASE
    puts ("Invalid credentials\n");
    fclose (fptr);
    return false;
}