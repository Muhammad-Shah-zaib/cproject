#include <stdio.h>
#include <stdlib.h>
// #include "structHotel.h"





// ! EXTRACTING ID FROM OUR ID FILE

int extract_id ( void ) {
    FILE *idfptr;

    if ( (idfptr = fopen ("id.txt", "r")) == NULL) {
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


void update_id ( int id ) {
    FILE *idfptr;

    if ( (idfptr = fopen ("id.txt", "w")) == NULL) {
        puts ("File can not be opened");
        exit(EXIT_SUCCESS);
    }

    fprintf (idfptr, "%d", id);

    fclose (idfptr);
}








void hotel_registration( void ) {
    // ? making a file poitner to open  hotels.dat
    FILE *fptr;

    if ( (fptr = fopen ("hotels.dat", "rb+")) == NULL ) {
        puts ("FIle can not be opened.");
        return;
    } 

    // ? Creating a hotel object
    Hotel hotel = {0, "", "", 0, 0, 0, 0, 0, 0, 0, 0, 0, ""};


    // ! EXTRACT ID AND THEN UPDATE IT FROM Id.txt
    int id = extract_id ();
    // ? ASSIGNING ID TO HOTEL
    hotel.id = id;
    id++;
    update_id( id );



    // ? GETTING THE username and hotel name from user
    printf ("Enter userName (dont put white-space): ");
    scanf ("%s", hotel.username);

    printf ("%s", "Enter Hotel name (dont put white-space): ");
    scanf ("%s", hotel.hotel_name);

    printf ("%s", "Enter the city name(dont push white-space): ");
    scanf ("%s", hotel.city_name);
    // Pointing the correct place and reserving bytes accordingly
    fseek (fptr, (hotel.id-1) * sizeof (Hotel), SEEK_SET);
    fwrite (&hotel, sizeof (Hotel), 1, fptr); // writing the data
    fflush (fptr);

    printf ("%d %s %s\n",hotel.id, hotel.username, hotel.hotel_name);
    printf ("Rememebr your id (id : %d), you will login using thiss id!\n", hotel.id);
    fclose (fptr);
}