#include <stdio.h>
// #include "structHotel.h"
int input_valid(){
    int valid_int;
    while(1){
        if (scanf("%d", &valid_int)!=1) 
        {
            clearScreen();
            puts("Invalid Input!");
            puts("Please Re-Enter:");
            while('\n'!= getchar());
            continue; 
        }
        break;
    }
return valid_int;
}


// This will show room details
void room_details(int id) {
    clearScreen();
    FILE *fptr;

    if ((fptr = fopen("hotels.dat", "rb+")) == NULL) {
        puts("File cannot be opened.");
        return;
    }

    Hotel hotel = {0};

    fseek(fptr, (id - 1) * sizeof(Hotel), SEEK_SET);
    fread(&hotel, sizeof(Hotel), 1, fptr);

    printf("\n\033[1;34m+-------------------------+\033[0m\n");
    printf("\033[1;34m|      Room Details       |\033[0m\n");
    printf("\033[1;34m+-------------------------+\033[0m\n");
    printf("\n\033[1;32mTotal rooms: %u\n", hotel.n_total_rooms);
    printf("Available rooms: %u\n", hotel.available_roams);
    printf("Total rooms booked: %u\n", hotel.booked_rooms);
    printf("\033[1;34m---------------------------\033[0m\n");
    printf("\033[1;34m        Standard Room      \033[0m\n");
    printf("\033[1;34m---------------------------\033[0m\n");
    printf("\033[1;32mTotal: %u\n", hotel.n_standard_rooms);
    printf("\033[1;32mAvailable Rooms: %u\n", hotel.available_standard_room);
    printf("Price per Room: %u\n", hotel.p_standard_room);
    printf("\033[1;34m---------------------------\033[0m\n");
    printf("\033[1;34m         Deluxe Rooms       \033[0m\n");
    printf("\033[1;34m---------------------------\033[0m\n");
    printf("\033[1;32mTotal: %u\n", hotel.n_delux_rooms);
    printf("\033[1;32mAvailable Rooms: %u\n", hotel.available_delux_room);
    printf("Price per Room: %u\n", hotel.p_delux_room);
    printf("\033[1;34m---------------------------\033[0m\n");
    printf("\033[1;34m         Luxury Rooms       \033[0m\n");
    printf("\033[1;34m---------------------------\033[0m\n");
    printf("\033[1;32mTotal: %u\n", hotel.n_luxury_rooms);
    printf("\033[1;32mAvailable Rooms: %u\n", hotel.available_luxury_room);
    printf("Price per Room: %u\n", hotel.p_luxury_room);
    printf("\033[1;34m---------------------------\033[0m\n");


    getchar(); // ignoring enter
    printf ("\n\n Press enter to conitnue.\n");
    getchar();
    fclose(fptr);
}





void add_room(int id) {
    clearScreen();
    unsigned int choice; // selecting for room type
    unsigned int n_room, price_per_room; // Temporarily temp id

    // making a file pointer to open hotels.dat
    FILE *fptr;
    if ((fptr = fopen("hotels.dat", "rb+")) == NULL) {
        puts("File Not Found!");
        return;
    }

    // making an empty hotel
    Hotel hotel = {0};

    // offsetting the file pointer
    fseek(fptr, (id - 1) * sizeof(Hotel), SEEK_SET);
    fread(&hotel, sizeof(Hotel), 1, fptr); // reading

    // prompting the user

    do {
        clearScreen();
        while (1){
        printf("Please Select the Room Type (to add):\n"
                "0.\tExit\n"
                "1.\tStandard Room\n"
                "2.\tDeluxe Room\n"
                "3.\tLuxury Room\n");

        // reading the user choice
        if (scanf("%d", &choice)!= 1){
            clearScreen();
            puts("Invalid Input!");
            while('\n'!=getchar());
            continue;
        }
        break;
        }
        if (choice == 0)
            return;

        // checking whether the choice provided by the user is valid or not
        if ((choice < 0) || (choice > 3)) {
            puts("Invalid input");
            continue;
        }

        

        switch (choice) {
            case 1: // FOR STANDARD ROOMS

                printf ("\033[1;32mTotal Standard rooms: %d\n\n\033[0m", hotel.n_standard_rooms);

                // reading rooms and price_per_room per room
                while(1){
                printf("Enter number of rooms to add:\n");
                if (scanf("%d", &n_room)!= 1){
                    clearScreen();
                    puts("Invalid Input!");
                    while('\n'!=getchar());
                    continue;
                }
                break;
                }

                while(1){
                printf("Enter price per room:\n");
                if (scanf("%d", &price_per_room)!= 1){
                    clearScreen();
                    puts("Invalid Input!");
                    while('\n'!=getchar());
                    continue;                
                }
                break;
                }
                hotel.n_standard_rooms += n_room;
                hotel.available_standard_room += n_room;
                hotel.n_total_rooms += n_room;
                hotel.available_roams += n_room;
                hotel.p_standard_room = price_per_room;
                hotel.available_standard_room += n_room;

                puts("\n\033[1;34mrooms added successfully\033[0m");
                printf("\033[1;32m=>total standard rooms: %d\n\033[0m", hotel.n_standard_rooms);
                printf("\033[1;32m=>price per standard rooms: %d\n\n\033[0m", hotel.p_standard_room);
                puts("Press enter to continue.");
                getchar(); // ignoring the enter
                getchar();
                break;

            case 2: // FOR DELUX ROOMS
                printf ("\033[1;32mTotal Deluxe rooms: %d\n\n\033[0m", hotel.n_delux_rooms);

                // reading rooms and price_per_room per room
                while (1){
                printf("Enter number of rooms to add:\n");
                if (scanf("%d", &n_room)!= 1){
                    clearScreen();
                    puts("Invalid Input!");
                    while('\n'!=getchar());
                    continue;}
                break;
                
                }
                while(1){
                printf("Enter price per room:\n");
                
                if (scanf("%d", &price_per_room)!= 1){
                    clearScreen();
                    puts("Invalid Input!");
                    while('\n'!=getchar());
                    continue;}
                break;
                
                }
                hotel.available_delux_room += n_room;
                hotel.n_delux_rooms += n_room;
                hotel.n_total_rooms += n_room;
                hotel.available_roams += n_room;
                hotel.p_delux_room = price_per_room;
                hotel.available_delux_room += n_room;

                puts("\n\033[1;34mrooms added successfully\033[0m");
                printf("\033[1;32m=>total delux rooms: %d\n\033[0m", hotel.n_delux_rooms);
                printf("\033[1;32m=>price per delux rooms: %d\n\n\033[0m", hotel.p_delux_room);
                puts("Press enter to continue.");
                getchar(); // ignoring the enter
                getchar();
                break;

            case 3: // FOR LUXURY ROOMS

                printf ("\033[1;32mTotal luxury rooms: %d\n\n\033[0m", hotel.n_luxury_rooms);

                // reading rooms and price_per_room per room
                while(1){
                printf("Enter number of rooms to add:\n");
                if (scanf("%d", &n_room)!= 1){
                    clearScreen();
                    puts("Invalid Input!");
                    while('\n'!=getchar());
                    continue;}
                break;
                
                }
                while(1){
                printf("Enter price per room:\n");
                if (scanf("%d", &price_per_room)!= 1){
                    clearScreen();
                    puts("Invalid Input!");
                    while('\n'!=getchar());
                    continue;}
                break;
                
                }
                hotel.available_luxury_room += n_room;
                hotel.n_luxury_rooms += n_room;
                hotel.n_total_rooms += n_room;
                hotel.available_roams += n_room;
                hotel.p_luxury_room = price_per_room;
                hotel.available_luxury_room += n_room;

                puts("\n\033[1;34mrooms added successfully\033[0m");
                printf("\033[1;32m=>total luxury rooms: %d\n\033[0m", hotel.n_luxury_rooms);
                printf("\033[1;32m=>price per luxury rooms: %d\n\n\033[0m", hotel.p_luxury_room);
                puts("Press enter to continue.");
                getchar();// ignoring the enter
                getchar();
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






// _____________________________________________________________________________________________________
// !TO DELETE ROOMs


void delete_room(int id) {

    clearScreen();
    FILE *fptr; // File pointer for hotels.dat
    int choice, n_room; // choice for room type and no of rooms to remove
    
    if ( (fptr = fopen("hotels.dat", "rb+")) == NULL ) { // check for opening the file
        puts("File Not Found!");
        return;
    }
    
       // prompting to enter tpye
    clearScreen();
    printf("Please Choose Room Type (to DELETE): \n"
        "0.\tExit.\n"
        "1.\tStandard Rooms\n"
        "2.\tDeluxe Rooms\n"
        "3.\tLuxury Rooms\n");

    choice = input_valid(); // ! reading the choice
    while('\n'!= getchar());
    while ( choice ) {
        
        Hotel hotel = {0}; // making an empty Hotel object

        rewind (fptr); // rewinding fptr to make sure we are at correct place
        // off-setting he file pointer
        fseek(fptr, (id - 1) * sizeof( Hotel ), SEEK_SET);
        fread(&hotel, sizeof( Hotel ), 1, fptr);

        // If less than 0 and greater than 3 prompt again
        if (choice < 0 || choice > 3) {
            clearScreen();
            puts("Wrong Input");
            printf("Please Choose Room Type:\n"
                "0.\tExit.\n"
                "1.\tStandard Rooms.\n"
                "2.\tDeluxe Rooms.\n"
                "3.\tLuxury Rooms.\n");
            choice = input_valid();
            while('\n'!= getchar());

            continue;
        }

        // displaying no of rooms and price (User Friendly)

        do {

            switch ( choice ){
                
                case 1: // FOR STANDARD ROOMS

                    printf ("\033[1;34mTotal standard rooms: %d\n\033[0m", hotel.n_standard_rooms);
                    printf ("%s", "Enter no of rooms to delete: ");
                    n_room = input_valid();
                    while('\n'!= getchar());

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
                    printf ("\033[1;32mRooms Deleted Successfully\n"
                    "=>Updated number of standard-rooms: %d\n\n\033[0m", hotel.n_standard_rooms);
                    puts("Press enter to continue.");
                    getchar();// ignoring the enter
                    getchar();
                    break;

                case 2: // FOR DELUX ROOMS

                    printf ("\033[1;34mTotal delux rooms: %d\n\033[0m", hotel.n_delux_rooms);
                    printf ("%s", "Enter no of rooms to delete: ");
                    scanf ("%d", &n_room);

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
                    printf ("\033[1;32mrooms Deleted successfully\n"
                    "=>Updated number of delux-rooms: %d\n\n\033[0m", hotel.n_delux_rooms);
                    puts("Press enter to continue.");
                    getchar();// ignoring the enter
                    getchar();
                    break;

                case 3: // FOR LUXURY ROOMS

                    printf ("\033[1;34mTotal luxury rooms: %d\n\033[0m", hotel.n_luxury_rooms);
                    printf ("%s", "Enter no of rooms to delete: ");
                    n_room = input_valid();
                    while('\n'!= getchar());

                    if ( n_room > hotel.n_luxury_rooms ) { // checking whether the rooms enough to delete or not
                        puts ("Number of Rooms Exceeds Existing Rooms."); 
                        printf ("=>already existing rooms: %d\n"
                            "=>no of rooms to delete: %d\n\n",
                            hotel.n_luxury_rooms, n_room );
                            continue;
                    }
                    hotel.n_luxury_rooms -= n_room;
                    hotel.n_total_rooms -= n_room;
                    hotel.available_roams -= n_room;
                    printf ("\033[1;32mrooms Deleted successfully\n"
                    "=>Updated number of luxury-rooms: %d\n\n\033[0m", hotel.n_luxury_rooms);
                    puts("Press enter to continue.");
                    getchar();// ignoring the enter
                    getchar();
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

        clearScreen();
        // prompt again
        printf("Please Choose Room Type:\n"
            "0.\tExit\n"
            "1.\tStandard Rooms\n"
            "2.\tDeluxe Rooms\n"
            "3.\tLuxury Rooms\n");
        choice = input_valid();
        while('\n'!= getchar());
    }

    fclose(fptr); // close file pointer at the end of the program
}

