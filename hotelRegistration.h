#include <stdio.h>
#include <stdlib.h>
// #include "client_initial_prompt.h"
// #include "structHotel.h"


// Define color codes
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"
#define CYAN "\033[1;36m"
#define RESET "\033[1;0m"





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
    while (getchar()!= '\n'); // ! clearing the buffer

    printf ("%s", "Enter Hotel name: ");
    scanf ("%29[^\n]", hotel.hotel_name);
    while (getchar()!= '\n'); // ! clearing the buffer
    while (1){
    printf ("%s", "Enter the city name: ");
    scanf ("%24[^\n]", hotel.city_name);
    while (getchar()!= '\n'); // ! clearing the buffer

    if (check_name(hotel.city_name))
        break;
    // if the check_name returns false =>
    puts(RED"Invalid/Currently We Are Not In This Area!"RESET);
    puts("Please Re-Enter:");
    }
    // Pointing the correct place and reserving bytes accordingly
    fseek (fptr, (hotel.id - 1) * sizeof (Hotel), SEEK_SET);
    fwrite (&hotel, sizeof (Hotel), 1, fptr); // writing the data
    fflush (fptr);

    printf("Hotel Name: %s\n"RESET, hotel.hotel_name);
    puts (BLUE"----------------------------------------------------------------");
    printf (CYAN"Rememebr your fllowing credentials, you will login using this id!\n"RESET);
    puts (BLUE"----------------------------------------------------------------");

    printf(GREEN"\nHotel ID: %d\n", hotel.id);
    printf("Username: %s\n"RESET, hotel.username);

    press_enter_to_continue();
    fclose (fptr);
}