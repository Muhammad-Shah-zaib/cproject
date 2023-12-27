#include <stdio.h>
// #include "structHotel.h"

// Function to update the number of rooms after the user books room

void update_rooms(int id, int room_type, int rooms_booked) {
    FILE *fptr;

    // Open the file in binary read and write mode
    if ((fptr = fopen("hotels.dat", "rb+")) == NULL) { // opnening the file
        puts("File Not Found!");
        return;
    }
 
    // Read the hotel details from the file
    Hotel hotel = {0};
    // Move the file pointer to the correct position

    fseek(fptr, (id - 1) * sizeof(Hotel), SEEK_SET);

    fread(&hotel, sizeof(Hotel), 1, fptr);
    // Update the booked and available rooms based on the room type
    switch (room_type) {
        case 1: // Standard Room
            hotel.booked_standard_room += rooms_booked;
            hotel.available_standard_room -= rooms_booked;
            break;
        case 2: // Deluxe Room
            hotel.booked_delux_room += rooms_booked;
            hotel.available_delux_room -= rooms_booked;
            break;

        case 3: // Luxury Room
            hotel.booked_luxury_room += rooms_booked;
            hotel.available_luxury_room -= rooms_booked;
            break;

        default:
            // Handle invalid room type
            puts("Invalid room type!");
            fclose(fptr);
            return;
    }

    // Update the total available rooms and booked rooms
    hotel.available_roams -= rooms_booked;
    hotel.booked_rooms += rooms_booked;

    rewind(fptr);
    // Move the file pointer back to the correct position
    fseek(fptr, (id - 1) * sizeof(Hotel), SEEK_SET);

    // Write the updated hotel details back to the file
    fwrite(&hotel, sizeof(Hotel), 1, fptr);

    // Flush the file buffer
    fflush(fptr);

    // Close the file
    fclose(fptr);
}