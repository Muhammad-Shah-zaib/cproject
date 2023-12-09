#include <stdio.h>
#include "structHotel.h"


void room_details ( int id ) {

    FILE *fptr;

    if( (fptr = fopen ("hotels.dat", "rb+")) == NULL ) {
        puts ("File can not be opened.");
        return;
    }

    Hotel hotel = {0, "", "", 0, 0, 0, 0, 0, 0, 0, 0, 0};

    fseek (fptr, (id-1) * sizeof (Hotel), SEEK_SET);
    fread (&hotel, sizeof(Hotel), 1, fptr);

    printf ("%-25s : %-25s : %-25s : %-25s : %-25s : %-25s\n", 
    "Total rooms", "Available rooms", "Booked rooms", "num. of Standard rooms",
    "num of Delux rooms", "num of Luxury rooms");

    printf ("%25d : %25d : %25d : %25d  :%25d : %25d", 
        hotel.n_total_rooms, hotel.available_roams, hotel.booked_rooms,
        hotel.n_standard_rooms, hotel.n_delux_rooms, hotel.n_luxury_rooms);


}
