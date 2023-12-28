#include <stdio.h>
#include "structHotel.h"


void printHotelDetails(const Hotel *hotel) {
    printf("\n\033[1;34m+----------------------------------+\033[0m\n"); // Blue box
    printf("\033[1;34m|            %s                      |\033[0m\n", hotel->username); // Blue box
    printf("\033[1;34m+----------------------------------+\033[0m\n"); // Blue box
    printf("\033[1;32mHotel ID: %u\n", hotel->id);
    printf("Username: %s\n", hotel->username);
    printf("Hotel Name: %s\n", hotel->hotel_name);
    printf("Total Rooms: %u\n", hotel->n_total_rooms);
    printf("Standard Rooms: %u (Price: %u)\n", hotel->n_standard_rooms, hotel->p_standard_room);
    printf("Delux Rooms: %u (Price: %u)\n", hotel->n_delux_rooms, hotel->p_delux_room);
    printf("Luxury Rooms: %u (Price: %u)\n", hotel->n_luxury_rooms, hotel->p_luxury_room);
    printf("Booked Rooms: %u\n", hotel->booked_rooms);
    printf("Available Rooms: %u\n", hotel->available_roams);
    printf("City Name: %s\n", hotel->city_name);
    printf("\033[1;34m+----------------------------------+\033[0m\n");
}

void hotel_read(void) {
    // making a file pointer for hotels.dat
    FILE *fptr;

    if ((fptr = fopen("hotels.dat", "rb")) == NULL) { // checking for opening file
        puts("File can not be opened.");
        return;
    }

    while (!feof(fptr)) {
        // reading the data
        Hotel hotel = {0};
        int result = fread(&hotel, sizeof(Hotel), 1, fptr);
        // displaying the data
        if (result != 0 && hotel.id != 0) {
            printHotelDetails(&hotel);
        }
    }

    fclose(fptr);
}


int main ( void ){

    hotel_read();
    return 0;
}