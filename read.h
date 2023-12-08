#include <stdio.h>

void hotel_read ( void ) {

    FILE *fptr;

    if ( ( fptr = fopen("hotels.dat", "rb")) == NULL ){
        puts ("File can not be opened.");
        return;
    }
    // printf ("i am chaling\n");
    while ( !feof(fptr) ) {
        Hotel hotel = {0, "", "", 0, 0, 0, 0, 0, 0, 0, 0, 0};
        int result = fread ( &hotel, sizeof (Hotel), 1, fptr );

        if ( result != 0 && hotel.id != 0) {
            printf ("%d, %s, %s\n", hotel.id, hotel.username, hotel.hotel_name);
        }
    }

    fclose ( fptr );

    return;
}