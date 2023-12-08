#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "structHotel.h"

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
void main ( void ) {
    // declairing the variables
    unsigned int id;
    char username[30];
    
    // getting the id and username
    prompt ( &id , username);



    FILE *fptr;

    if (( fptr = fopen ("hotels.dat", "rb")) == NULL) {
        puts ("FIle can not be opened.");
        exit (EXIT_SUCCESS);
    }

    Hotel hotel = {0, "", "", 0, 0, 0, 0, 0, 0, 0, 0, 0};

    fseek (fptr, (id-1) * sizeof (Hotel), SEEK_SET);
    fread (&hotel, sizeof(Hotel), 1, fptr);
    if ( check_credentials(id, username, hotel.id, hotel.username)) {
        printf ("Correct credentials.\n");
    }else 
        puts ("Invalid credentials\n");
    // printf ("%d: %s: %s: %d\n", hotel.id, hotel.username, username,  strcmp(hotel.username,username));

    
    fclose (fptr);
}