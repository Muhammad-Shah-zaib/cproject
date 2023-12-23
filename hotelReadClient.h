#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>

#include "getHotelsUnderBudget.h"

// Define color codes
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"
#define CYAN "\033[1;36m"
#define RESET "\033[1;0m"





void display_selected_hotel ( Hotel selected_hotel ) {
    printf(BLUE"\n---------------------------------\n");
    printf("Hotel Details - Cost per Room\n");
    printf("---------------------------------\n");

    printf(GREEN"Hotel Name: %s\n", selected_hotel.hotel_name);
    printf("City: %s\n", selected_hotel.city_name);
    printf(BLUE"---------------------------------\n");
    printf("\nRoom Types and Prices:\n");

    // Display cost for STANDARD room
    printf(YELLOW"Standard Room: $%u per night\n", selected_hotel.p_standard_room);

    // Display cost for DELUXE room
    printf("Deluxe Room: $%u per night\n", selected_hotel.p_delux_room);

    // Display cost for LUXURY room
    printf("Luxury Room: $%u per night\n"RESET, selected_hotel.p_luxury_room);

    printf(BLUE"---------------------------------\n"RESET);
}







Hotel* find_hotels(const char *location, unsigned int *hotels_count) {
    FILE *file = fopen("hotels.dat", "rb"); // opening the file
    
    if (file == NULL) { // checking for file opening
        perror("Error opening file");
        exit (5); // terminating hte program after prompting
    }

    Hotel *hotels = NULL; // aking a pointer to get the values and return it
    

    // Read each hotel entry from the file
    Hotel hotel;
    
    while (!feof (file) ){ // checking for end of file

        size_t result = fread(&hotel, sizeof(Hotel), 1, file); // reading the file 


        // ! NOW WE NEED TO CHECK WHETHER THE HOTEL WE READ IS THE WE NEED OR NOT...
        if (result != 0 && hotel.id != 0){ // chekcing for valid hotel 

            if (strcmp (location, hotel.city_name) == 0) { // compairing the locaiton name with hotel's city name
                (*hotels_count)++; // increase total hotel count
                hotels = (Hotel *) realloc (hotels, (*hotels_count )* sizeof(Hotel)); // reallocating the momeory to our hotels pointer
                hotels[(*hotels_count) - 1] = hotel; // adding to our pointer ( Array )
            }

        }
    }
    

    fclose(file); // closing hte file

    if ((*hotels_count) == 0) { // if the total hotel count is 0
        printf("No hotels found in %s\n", location);
        return NULL;
    }

    return hotels; // returning the hotels pointer
}










void hotel_read_client( char *location ) {
    clearScreen();
    unsigned int hotels_Count = 0; // * to get total hotels at desired location

    // this fucntion will return a pointer of
    Hotel *hotels = find_hotels(location, &hotels_Count); // passing pointer to hotels_count to get it updated

    

    // ! PRINTING THE LIST OF HOTELS...
    if (hotels != NULL) {
        // Process the retrieved hotels
        for (int i = 0; i < hotels_Count ; i++) {


            if (hotels[i].id != 0){ // just an extra check
                // pringting the hotels
                printf(BLUE"-------------------------------------------------------------------------------------------------------------------------------------\n");

                printf (YELLOW"=> %d.\t"BLUE"hotel_name: %s, location: %s, ",
                i+1, hotels[i].hotel_name, hotels[i].city_name);

                // Display cost for STANDARD room
                printf(YELLOW"Standard Room: $%u per night, ", hotels[i].p_standard_room);
                // Display cost for DELUXE room
                printf("Deluxe Room: $%u per night, ", hotels[i].p_delux_room);
                // Display cost for LUXURY room
                printf("Luxury Room: $%u per night\n"RESET, hotels[i].p_luxury_room);

                printf(BLUE"-------------------------------------------------------------------------------------------------------------------------------------\n" RESET);

            }


        }

        // ! PROMPTING USER TO EITHER SELECT OR WANT RECOMENDATIONS
        char choice;
        puts ("\nCan you choose among these:\n");
        do {
            printf ("%s%s",
                "1.\tSELECT.\n",
                "2.\tWant Recommendations.\n"
                "=> ");

            // WAS FACING SOME PREVIOUS BUFFER WHEN I RUN THIS PROGRAM SO CLEARING THE BUFFER HERE FOR NOW...
            getchar(); 
            scanf ("%c", &choice);
            while ( '\n' != getchar()); // clearing buffer
            if (choice < '0' || choice > '2') {
                puts (RED"INVALID INPUT"RESET);
            }
        }while( choice < '0' || choice > '2');

        // checking the choice...
        switch ( choice ) {
            case '1': {

                int select_hotel_index; // for getting the hotel user want

                do {
                    
                    printf ("Enter the serial number of the hotel: ");
                    scanf ("%d", &select_hotel_index); // reading the hotel user want
                    while('\n' != getchar()); // ! clearing the buffer


                    if (select_hotel_index < 0 || select_hotel_index > hotels_Count) {
                        puts (RED"INVALID HOTEL SERIAL NUMBER."RESET);
                        continue;
                    }

                    clearScreen();
                    display_selected_hotel ( hotels[select_hotel_index - 1] );

                    if (confirm_prompt()){

                        char client_room_choice;

                        do {
                            clearScreen();
                            printf (GREEN"%s",
                                "Select room type: \n"
                                "1.\tstandard\n"
                                "2\tDelux\n"
                                "3.\tLuxury\n"RESET);
                                client_room_choice = getchar();
                                while ( '\n' != getchar()); // clearing the buffer

                            switch (client_room_choice){

                                case '1':
                                    generate_ticket (hotels[select_hotel_index-1].hotel_name, "Standard Room",  hotels[select_hotel_index-1].n_standard_rooms, hotels[select_hotel_index-1].p_standard_room, NULL, "", "", location);
                                    puts ("Thanks for using this service.");
                                    exit (EXIT_SUCCESS);
                                    sleep(2);
                                    break;  

                                case '2':
                                    generate_ticket (hotels[select_hotel_index-1].hotel_name, "Delux Room",  hotels[select_hotel_index-1].n_delux_rooms, hotels[select_hotel_index-1].p_delux_room, NULL, "", "", location);
                                    printf ("Generating ticket!\n");
                                    puts ("Thanks for using this service.");
                                    exit (EXIT_SUCCESS);
                                    sleep(2);
                                    break;

                                case '3':
                                    generate_ticket (hotels[select_hotel_index-1].hotel_name, "Luxury Room",  hotels[select_hotel_index-1].n_luxury_rooms, hotels[select_hotel_index-1].p_luxury_room, NULL, "", "", location);
                                    printf ("Generating ticket!\n");
                                    puts ("Thanks for using this service.");
                                    exit (EXIT_SUCCESS);
                                    sleep(2);
                                    break;

                                default:
                                    puts ("Wrong input.");
                                    break;
                            }
                        }while (client_room_choice < '0' || client_room_choice > '3');
                    }
                }while ( select_hotel_index < 0 || select_hotel_index > hotels_Count );
                
                break;
            }

            case '2': {

                    int days, budget, hotel_budget, car_budget = hotel_budget = budget = days = 0;

                    get_info(&days, &budget); // this function read days and budget
                    make_calculations(&days, &budget, &hotel_budget, &car_budget, (false) ); // this will update my budget 
                    // ! NOW ME CAR BUDGET IS ZERO IS USER DONT WANT ANY TRANSPORT
                    // ! ALL THE BUDGET IS OPTED FOR DAYS


                    printf(" Days : %d \n Total budget : %d \n Hotel Budget: %d \n Car_budget : %d \n ", days, budget, hotel_budget, car_budget);


                    get_hotels_under_budegt ( hotels, hotels_Count, budget, days, location);
                    exit (EXIT_SUCCESS);
                    break;
            }
            default :
                puts ("INVALID!");
        }        
        free(hotels); // freeing the allocaitng memory
    }

    return;
}
