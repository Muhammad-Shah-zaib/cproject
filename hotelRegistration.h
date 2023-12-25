#include <stdio.h>
#include <stdlib.h>
// #include "client_initial_prompt.h"
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
    Hotel hotel = {0};


    // ! EXTRACT ID AND THEN UPDATE IT FROM Id.txt
    int id = extract_id ();
    // ? ASSIGNING ID TO HOTEL
    hotel.id = id;
    id++;
    update_id( id );


    while (getchar()!= '\n');
    // ? GETTING THE username and hotel name from user
    printf ("Enter userName: ");
    scanf ("%29[^\n]", hotel.username);
    while (getchar()!= '\n');
    printf ("%s", "Enter Hotel name: ");
    scanf ("%29[^\n]", hotel.hotel_name);
    while (getchar()!= '\n');
    while (1){
    printf ("%s", "Enter the city name: ");
    scanf ("%24[^\n]", hotel.city_name);
    if (check_name(hotel.city_name))
        break;
        clearScreen();
    puts("Invalid/Currently We Are Not In This Area!");
    puts("Please Re-Enter:");
    while(getchar()!= '\n');
    }
    // Pointing the correct place and reserving bytes accordingly
    fseek (fptr, (hotel.id - 1) * sizeof (Hotel), SEEK_SET);
    fwrite (&hotel, sizeof (Hotel), 1, fptr); // writing the data
    fflush (fptr);

    printf("Hotel ID: %d\n", hotel.id);
    printf("Username: %s\n", hotel.username);
    printf("Hotel Name: %s\n", hotel.hotel_name);

    printf ("Rememebr your id (%d), you will login using this id!\n", hotel.id);
    fclose (fptr);
}