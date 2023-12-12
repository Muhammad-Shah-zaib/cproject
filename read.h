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
            printf ("%d, %s, %s, %u, %u, %u, %u, %u, %u\n",
                hotel.id, hotel.username, hotel.hotel_name,
                hotel.n_standard_rooms, hotel.p_standard_room,
                hotel.n_delux_rooms, hotel.p_delux_room,
                hotel.n_luxury_rooms,hotel.p_luxury_room);
        }
    }

    fclose ( fptr );

    return;
}