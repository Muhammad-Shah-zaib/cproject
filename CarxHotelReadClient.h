#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


void select_car ( Car_Modal *car, char *car_company_name, char *car_type, const char *location ) {

    clearScreen();

    unsigned int car_count = 0;
    Car_Rental *cars = find_cars(location, &car_count);

    // Handle the case where no cars are found
    if (cars == NULL) {
        return;
    }

    // Print header for the entire car_rental information
    printf("\n\n");

    // Loop through each car_rental
    for (int i = 0; i < car_count; i++) {
        // Check if the car_rental is valid (ID not equal to 0)
        if (cars[i].id != 0) {
            // Print header for each car_rental entry
            printf(BLUE"------------------------------------------------------------------------\n");
            printf(YELLOW"=> %d.\t"GREEN"car_rental_name: %s, location: %s, \n",
                    i + 1, cars[i].company_name, cars[i].city_name);

            // Print SUVs information if available
            if (0 != cars[i].n_suv) {
                printf(BLUE"------------- SUVs -------------\n");
                // Loop through each SUV
                for (int j = 0; j < cars[i].n_suv; j++) {
                    // Print details of each SUV
                    printf(YELLOW"model: %5d| modal name: %10s| price: %6d\n"RESET, 
                            cars[i].suv[j].modal, cars[i].suv[j].name, cars[i].suv[j].price);
                }
            }

            // Print non-SUVs information if available
            if (0 != cars[i].n_non_suv) {
                printf(BLUE"---------- non-SUVs ----------\n");
                // Loop through each non-SUV
                for (int j = 0; j < cars[i].n_non_suv; j++) {
                    // Print details of each non-SUV
                    printf(YELLOW"model: %5d| modal name: %-10s| price: %6d\n"RESET, 
                            cars[i].non_suv[j].modal, cars[i].non_suv[j].name, cars[i].non_suv[j].price);
                }
            }

            // Print premium cars information if available
            if (0 != cars[i].n_premium) {
                printf(BLUE"----------  PREMIUMs ----------\n");
                // Loop through each premium car
                for (int j = 0; j < cars[i].n_premium; j++) {
                    // Print details of each premium car
                    printf(YELLOW"model: %5d| modal name: %-10s| price: %6d\n"RESET, 
                            cars[i].premium[j].modal, cars[i].premium[j].name, cars[i].premium[j].price);
                }
            }

            // Print footer for each car_rental entry
            printf(BLUE"------------------------------------------------------------------------\n"RESET);
        }

    }

    char choice;

    do {
        puts ("\nCan you choose among these:\n");
        printf ("%s%s",
            "1.\tSELECT.\n",
            "2.\tWant Recommendations.\n"
            "=> ");

        scanf ("%c", &choice);
        while('\n' != getchar()); // clearing buffer

        if (choice < '0' || choice > '2') {
            puts (RED"INVALID INPUT"RESET);
        }

    }while (choice < '0' || choice > '2');

        // checking the choice...
        switch ( choice ) {
            case '1': {

                int select_car_index; // for getting the hotel user want

                do {
                    
                    printf ("Enter the serial number of the Car Rental: ");
                    scanf ("%d", &select_car_index); // reading the hotel user want
                    getchar(); // ! clearing the buffer

                    if (select_car_index < 0 || select_car_index > car_count) {
                        
                        puts (RED"INVALID CAR-RENTAL-SERIAL-NUMBER."RESET);
                        continue;
                    }
                    

                    display_selected_car_rental ( &cars[select_car_index - 1] );


                    // ! GETTING THE COMPANY NAME!!!
                    strcpy (car_company_name, cars[select_car_index - 1].company_name );
                    
                    if (confirm_prompt()){
                        clearScreen();

                        char client_car_choice;

                        do {
                            printf (GREEN"%s",
                                "Select car type: \n"
                                "1.\tSUV\n"
                                "2\tnon-SUV\n"
                                "3.\tPremium\n=> "RESET);
                                client_car_choice = getchar();
                                getchar(); // clearing the buffer

                            switch (client_car_choice){

                                case '1':
                                    strcpy (car_type, "SUV");
                                    (*car) = display_cars( "SUV", cars[select_car_index - 1].company_name, cars[select_car_index - 1].suv, cars[select_car_index - 1].n_suv, location );
                                    break;  

                                case '2':
                                    strcpy (car_type, "non-SUV");
                                    (*car) = display_cars( "non-SUV", cars[select_car_index - 1].company_name, cars[select_car_index - 1].non_suv, cars[select_car_index - 1].n_non_suv, location );


                                    break;

                                case '3':
                                    strcpy (car_type, "Premium");
                                    (*car) = display_cars( "Premium", cars[select_car_index - 1].company_name, cars[select_car_index - 1].premium, cars[select_car_index - 1].n_premium, location );


                                    break;

                                default:
                                    break;
                            }
                        }while (client_car_choice < '0' || client_car_choice > '3');
                    }
                }while ( select_car_index < 0 || select_car_index > car_count );
                
                break;
            }


            default :
                puts ("INVALID!");
        }
    // Free the allocated memory for cars
    free(cars);


}   



















// this function will read all the hotels and the car Rentals at the provided location and will give choice to user whether he can 
// select among the given or need recommendations and then will generate ticket once the selection has done
void both_read_client ( const char *location ) {

    int hotels_count = 0; // => for storing total car_rentals and hotels at the place
    Hotel *hotels = find_hotels ( location, &hotels_count); // finding the totla hotels

    // printf ("hotels_count: %d", hotels_count);
    // CEHCKING FOR HOTELS AND DISIPLAYING THEM
    if (hotels != NULL) {
        // Process the retrieved hotels
        for (int i = 0; i < hotels_count ; i++) {
            // printf ("i = %d\n", i);

            if (hotels[i].id != 0){ // just an extra check
                // pringting the hotels
                printf(BLUE"-------------------------------------------------------------------------------------------------------------------------------------\n");

                printf (YELLOW"=> %d.\t"BLUE"hotel_name: %s, location: %s, ",
                i+1, hotels[i].hotel_name, hotels[i].city_name);

                // Display cost for STANDARD room
                printf(YELLOW"Standard Room: /-%u per night, ", hotels[i].p_standard_room);
                // Display cost for DELUXE room
                printf("Deluxe Room: /-%u per night, ", hotels[i].p_delux_room);
                // Display cost for LUXURY room
                printf("Luxury Room: /-%u per night\n"RESET, hotels[i].p_luxury_room);

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

        switch ( choice ) {
            case '1': {

                int select_hotel_index; // for getting the hotel user want

                do {
                    
                    printf ("Enter the serial number of the hotel: ");
                    scanf ("%d", &select_hotel_index); // reading the hotel user want
                    while('\n' != getchar()); // ! clearing the buffer


                    if (select_hotel_index < 0 || select_hotel_index > hotels_count) {
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


                                // declariing the cariable to get the car credentails needed for generating the ticket
                                char car_company_name[30], car_type[8];
                                Car_Modal car;

                            switch (client_room_choice){
                                
                                case '1':

                                    select_car ( &car, car_company_name, car_type, location);
                                    generate_ticket (hotels[select_hotel_index-1].hotel_name, "Standard Room",  hotels[select_hotel_index-1].n_standard_rooms, hotels[select_hotel_index-1].p_standard_room, &car, car_company_name, car_type, location);
                                    puts ("Thanks for using this service.");
                                    exit (EXIT_SUCCESS);
                                    sleep(2);
                                    break;  

                                case '2':
                                    select_car ( &car, car_company_name, car_type, location);
                                    generate_ticket (hotels[select_hotel_index-1].hotel_name, "Standard Room",  hotels[select_hotel_index-1].n_standard_rooms, hotels[select_hotel_index-1].p_standard_room, &car, car_company_name, car_type, location);
                                    printf ("Generating ticket!\n");
                                    puts ("Thanks for using this service.");
                                    exit (EXIT_SUCCESS);
                                    sleep(2);
                                    break;

                                case '3':
                                    select_car ( &car, car_company_name, car_type, location);
                                    generate_ticket (hotels[select_hotel_index-1].hotel_name, "Standard Room",  hotels[select_hotel_index-1].n_standard_rooms, hotels[select_hotel_index-1].p_standard_room, &car, car_company_name, car_type, location);
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
                }while ( select_hotel_index < 0 || select_hotel_index > hotels_count );
                
                break;
            }



            case '2':{
                int days, budget, hotel_budget, car_budget = hotel_budget = budget = days = 0;

                get_info(&days, &budget); // this function read days and budget
                make_calculations(&days, &budget, &hotel_budget, &car_budget, (true) ); // this will update my budget 

                // ! NOW ME CAR BUDGET IS ZERO IS USER DONT WANT ANY TRANSPORT
                // ! ALL THE BUDGET IS OPTED FOR DAYS
                printf(" Days : %d \n Total budget : %d \n Hotel Budget: %d \n Car_budget : %d \n ", days, budget, hotel_budget, car_budget);
                _get_hotels_under_budegt ( hotels, hotels_count, hotel_budget,car_budget,  days, location);

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