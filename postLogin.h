#include <stdio.h>
// #include "structHotel.h"




// This will show room details
void room_details ( int id ) {

    FILE *fptr;

    if( (fptr = fopen ("hotels.dat", "rb+")) == NULL ) {
        puts ("File can not be opened.");
        return;
    }

    Hotel hotel = {0, "", "", 0, 0, 0, 0, 0, 0, 0, 0, 0};

    fseek (fptr, (id-1) * sizeof (Hotel), SEEK_SET);
    fread (&hotel, sizeof(Hotel), 1, fptr);

    printf( "+-------------------------+\n"
            "       Room Details        \n"
            "+-------------------------+\n"
            "\nTotal rooms: %d\n"
            "Available rooms: %d\n"
            "Total rooms booked: %d\n"
            "---------------------------"
            "\n\tStandard Room\n"
            "Available Rooms: %d\n"
            "Price per Room: %d\n"
            "---------------------------"
            "\n\tDeluxe Rooms\n"
            "Available Rooms: %d\n"
            "Price per Room: %d\n"
            "---------------------------"
            "\n\tLuxury Rooms\n"
            "Available Rooms: %d\n"
            "Price per Room: %d\n"
            "---------------------------\n",
            hotel.n_total_rooms, hotel.available_roams, hotel.booked_rooms,
            hotel.n_standard_rooms, hotel.p_standard_room, 
            hotel.n_delux_rooms, hotel.p_delux_room, 
            hotel.n_luxury_rooms, hotel.p_luxury_room);


}



void add_room(int id) {
    unsigned int choice; // selecting for room type
    unsigned int n_room, price_per_room; // Temporarily temp id

    // making a file pointer to open hotels.dat
    FILE *fptr;
    if ((fptr = fopen("hotels.dat", "rb+")) == NULL) {
        puts("File Not Found!");
        return;
    }

    // making an empty hotel
    Hotel hotel = {0, "", "", 0, 0, 0, 0, 0, 0, 0, 0, 0};

    // offsetting the file pointer
    fseek(fptr, (id - 1) * sizeof(Hotel), SEEK_SET);
    fread(&hotel, sizeof(Hotel), 1, fptr); // reading

    printf("EXTRACTED: %d: %d", hotel.n_total_rooms, hotel.n_standard_rooms);
    // prompting the user

    do {
        printf("Please Select the Room Type (to add):\n"
                "0.\tExit\n"
                "1.\tStandard Room\n"
                "2.\tDeluxe Room\n"
                "3.\tLuxury Room\n");

        // reading the user choice
        scanf("%d", &choice);

        if (choice == 0)
            return;

        // checking whether the choice provided by the user is valid or not
        if ((choice < 0) || (choice > 3)) {
            puts("Invalid input");

            // prompting the user
            printf("Please Select the Room Type ( to add ):\n"
                    "1.\tStandard Room\n"
                    "2.\tDeluxe Room\n"
                    "3.\tLuxury Room\n");

            // reading the user choice
            scanf("%d", &choice);
            continue;
        }

        // reading rooms and price_per_room per room
        printf("Enter number of rooms to add:\n");
        scanf("%d", &n_room);
        printf("Enter price per room:\n");
        scanf("%d", &price_per_room);

        switch (choice) {
            case 1: // FOR STANDARD ROOMS
                hotel.n_standard_rooms += n_room;
                hotel.n_total_rooms += n_room;
                hotel.available_roams += n_room;
                hotel.p_standard_room = price_per_room;
                puts("\nrooms added successfully");
                printf("=>total standard rooms: %d\n", hotel.n_standard_rooms);
                printf("=>price per standard rooms: %d\n\n", hotel.p_standard_room);
                break;

            case 2: // FOR DELUX ROOMS
                hotel.n_delux_rooms += n_room;
                hotel.n_total_rooms += n_room;
                hotel.available_roams += n_room;
                hotel.p_delux_room = price_per_room;
                puts("\nrooms added successfully");
                printf("=>total delux rooms: %d\n", hotel.n_delux_rooms);
                printf("=>price per delux rooms: %d\n\n", hotel.p_delux_room);
                break;

            case 3: // FOR LUXURY ROOMS
                hotel.n_luxury_rooms += n_room;
                hotel.n_total_rooms += n_room;
                hotel.available_roams += n_room;
                hotel.p_luxury_room = price_per_room;
                puts("\nrooms added successfully");
                printf("=>total luxury rooms: %d\n", hotel.n_luxury_rooms);
                printf("=>price per luxury rooms: %d\n\n", hotel.p_luxury_room);
                break;

            default:
                printf("Wrong Input!");
        }

        // offsetting the pointer to the correct place
        rewind ( fptr );
        fseek(fptr, (id - 1) * sizeof(Hotel), SEEK_SET);
        fwrite(&hotel, sizeof(Hotel), 1, fptr); // overwriting the hotel details
        fflush(fptr); // flushing the file buffer

    } while (choice != 0);

    // close the file
    fclose(fptr);
}





void delete_room(int id) {

    FILE *fptr; // File pointer for hotels.dat
    int choice, n_room; // choice for room type and no of rooms to remove
    
    if ( (fptr = fopen("hotels.dat", "rb+")) == NULL ) { // check for opening the file
        puts("File Not Found!");
        return;
    }
    
       // prompting to enter tpye
    printf("Please Choose Room Type (to DELETE): \n"
        "0.\tExit.\n"
        "1.\tStandard Rooms\n"
        "2.\tDeluxe Rooms\n"
        "3.\tLuxury Rooms\n");
    scanf("%d", &choice); // ! reading the choice

    while ( choice ) {
        
            Hotel hotel = {0, "", "", 0, 0, 0, 0, 0, 0, 0, 0, 0}; // making an empty Hotel object

        rewind (fptr); // rewinding fptr to make sure we are at correct place
        // off-setting he file pointer
        fseek(fptr, (id - 1) * sizeof( Hotel ), SEEK_SET);
        fread(&hotel, sizeof( Hotel ), 1, fptr);

        // If less than 0 and greater than 3 prompt again
        if (choice < 0 || choice > 3) {

            puts("Wrong Input");
            printf("Please Choose Room Type:\n"
                "0.\tExit.\n"
                "1.\tStandard Rooms.\n"
                "2.\tDeluxe Rooms.\n"
                "3.\tLuxury Rooms.\n");
            scanf("%d", &choice);

            continue;
        }

        // displaying no of rooms and price (User Friendly)
        printf( "------------------------"
                "\n\tStandard Room\n"
                "Available Rooms: %d\n"
                "Price per Room: %d\n"
                "------------------------"
                "\n\tDeluxe Rooms\n"
                "Available Rooms: %d\n"
                "Price per Room: %d\n"
                "------------------------"
                "\n\tLuxury Rooms\n"
                "Available Rooms: %d\n"
                "Price per Room: %d\n"
                "------------------------\n",
                hotel.n_standard_rooms, hotel.p_standard_room, 
                hotel.n_delux_rooms, hotel.p_delux_room, 
                hotel.n_luxury_rooms, hotel.p_luxury_room);

        do {

            printf ("%s", "Enter no of rooms to delete: ");
            scanf ("%d", &n_room);

            switch ( choice ){
                
                case 1: // FOR STANDARD ROOMS

                    if ( n_room > hotel.n_standard_rooms ) { // checking whether the rooms enough to delete or not
                        puts ("\nNumber of rooms exceeds than the original number."); 
                        printf ("=>Number of rooms already existing: %d\n"
                            "=>Number of rooms to delete: %d\n\n",
                            hotel.n_standard_rooms, n_room );
                            continue;
                    }
                    hotel.n_standard_rooms -= n_room;
                    hotel.n_total_rooms -= n_room;
                    hotel.available_roams -= n_room;
                    printf ("rooms Deleted successfully\n"
                    "=>Updated number of standard-rooms: %d\n\n", hotel.n_standard_rooms);
                    break;

                case 2: // FOR DELUX ROOMS

                    if ( n_room > hotel.n_delux_rooms ) { // checking whether the rooms enough to delete or not
                        puts ("number of rooms exceeds than the original number."); 
                        printf ("=>already existing rooms: %d\n"
                            "=>no of rooms to delete: %d\n\n",
                            hotel.n_delux_rooms, n_room );
                            continue;
                    }

                    hotel.n_delux_rooms -= n_room;
                    hotel.n_total_rooms -= n_room;
                    hotel.available_roams -= n_room;
                    printf ("rooms Deleted successfully\n"
                    "=>Updated number of delux-rooms: %d\n\n", hotel.n_delux_rooms);
                    break;

                case 3: // FOR LUXURY ROOMS

                    if ( n_room > hotel.n_luxury_rooms ) { // checking whether the rooms enough to delete or not
                        puts ("number of rooms exceeds than the original number."); 
                        printf ("=>already existing rooms: %d\n"
                            "=>no of rooms to delete: %d\n\n",
                            hotel.n_luxury_rooms, n_room );
                            continue;
                    }
                    hotel.n_luxury_rooms -= n_room;
                    hotel.n_total_rooms -= n_room;
                    hotel.available_roams -= n_room;
                    printf ("rooms Deleted successfully\n"
                    "=>Updated number of luxury-rooms: %d\n\n", hotel.n_luxury_rooms);
                    break;

                default:
                    puts ("INVALID INPUT!");
            }
        } while ( 0 );

        rewind(fptr);   // rewind pointer

        // offsetting the pointer again
        fseek(fptr, (id - 1) * sizeof(Hotel), SEEK_SET);
        fwrite(&hotel, sizeof(Hotel), 1, fptr); // write the taken data
        fflush ( fptr );

        // prompt again
        printf("Please Choose Room Type:\n"
            "0.\tExit\n"
            "1.\tStandard Rooms\n"
            "2.\tDeluxe Rooms\n"
            "3.\tLuxury Rooms\n");
        scanf("%d", &choice);
    }

    fclose(fptr); // close file pointer at the end of the program
}

