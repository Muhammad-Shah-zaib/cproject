#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

// #include "recommendationGetBudget.h"
// #include "structHotel.h"
// #include "structCarRental.h"
// #include "getHotelsUnderBudget.h"
// #include "ticketGenerator.h"
// #include "clearScreen.h"
// #include "check_location.h"
// #include "getCarRentalUnderBudget.h"
// #include "carReadClient.h"

#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"
#define CYAN "\033[1;36m"
#define RESET "\033[1;0m"






// make a function of get_carRentals_under_budegt() that first find out the least expensive car under a given range and then dislpay them and ask for selection
void _get_carRentals_under_budegt ( Car_Rental *cars, unsigned int cars_count, unsigned int b_per_day, const char *location, char *hotel_name
                                , char *room_tpye, unsigned int n_rooms, unsigned int p_room, int days) {

    // reading which type of car user wants
    char choice_car_type;
    do {
        printf ("\nSelect among the followings.\n"
            "1.\tSUV\n"
            "2.\tSedan\n"
            "3.\tLuxury\n");
        choice_car_type = getchar ();
        while ('\n' != getchar()); // ! clearing the buffer

        // prompting for wrong input
        if (choice_car_type < '0' && choice_car_type > '3') 
            puts (RED"Wrong Input."RESET);

    }while (choice_car_type < '0' && choice_car_type > '3');

    // now find the lesat expensive car of choice_car_type with the given range of budget
    char car_company_name[30];
    Car_Modal car = get_least_expensive_car ( cars, cars_count, b_per_day, choice_car_type, car_company_name );

    printf (GREEN"\nmodel name: %s\n=>model: %d\n=>price: %d\n"RESET, car.name, car.modal, car.price);

    // check for choice_car_type and gnerate ticekt


    char *car_type; // forstoring "SUV" or "Sedan" or "Luxury"
    car_type = get_car_type ( choice_car_type ); // this allocte memory the exact memory i ned to store particualr string

    if ( 0 == strcmp(car.name, "") )
        return;
    


    generate_ticket ( hotel_name, room_tpye, n_rooms, p_room, &car ,car_company_name, car_type, location, days);
    puts (GREEN"Thank you for using our service."RESET);
    free (car_type);
    exit (EXIT_SUCCESS);
    
}
























void _get_hotels_under_budegt(Hotel *hotels, const unsigned int hotels_count, unsigned int hotel_budget, unsigned int car_budget, unsigned int days, const char *location)
{
    int n_rooms;
    int budget_gap;
    unsigned int j, index = 0;
    Hotel least_expesive_hotel = {0};
    char choose_name[30];
    Hotel listed_hotels[3];

    for (int i = 1; i <= 3; i++)
    {
        least_expesive_hotel = find_least_expensive_hotel(hotels, hotels_count, hotel_budget, i);

        // Check if the hotel is already in the listed_hotels array
        if (least_expesive_hotel.n_total_rooms != 0)
        {
            int hotel_already_listed = 0;
            for (j = 0; j < i - 1; j++)
            {
                if (strcmp(listed_hotels[j].hotel_name, least_expesive_hotel.hotel_name) == 0)
                {
                    hotel_already_listed = 1;
                    break; // Exit the loop if the hotel is already in the list
                }
            }

            // If the hotel is not already in the list, add it
            if (!hotel_already_listed)
            {
                printf("\n%s\n", least_expesive_hotel.hotel_name);
                listed_hotels[index] = least_expesive_hotel;
                index++;
            }
            else
                continue;
        }

        if (least_expesive_hotel.n_total_rooms!= 0){
        printf(BLUE "\nHotel name: %s\n", least_expesive_hotel.hotel_name);
        printf("Location: %s\n\n" RESET, least_expesive_hotel.city_name);

        printf(YELLOW "\t%15s : %15s\n" RESET, "Room Type", "Price per night ");

        // diplaying the hotels and there rooms and tellinguser taht they are in your range or not
        if ((budget_gap = budget_difference(&hotel_budget, &least_expesive_hotel, '1')) <= 0)
            printf(GREEN "\t%15s : %8d\t : %-23s\n" RESET, "Standard Room", least_expesive_hotel.p_standard_room, "In Your Range");
        else if ((budget_gap = budget_difference(&hotel_budget, &least_expesive_hotel, '1')) > 0)
            printf(GREEN "\t%15s : %8d\t : %4s %-5d%13s\n" RESET, "Standard Room", least_expesive_hotel.p_standard_room, "PKR.", budget_gap, "Out Of Range");

        if ((budget_gap = budget_difference(&hotel_budget, &least_expesive_hotel, '2')) <= 0)
            printf(CYAN "\t%15s : %8d\t : %-23s\n" RESET, "Delux Room", least_expesive_hotel.p_delux_room, "In Your Range");
        else if ((budget_gap = budget_difference(&hotel_budget, &least_expesive_hotel, '2')) > 0)
            printf(CYAN "\t%15s : %8d\t : %4s %-5d%13s\n" RESET, "Delux Room", least_expesive_hotel.p_delux_room, "PKR.", budget_gap, "Out Of Range");

        if ((budget_gap = budget_difference(&hotel_budget, &least_expesive_hotel, '3')) <= 0)
            printf(RED "\t%15s : %8d\t : %-23s\n" RESET, "Luxury Room", least_expesive_hotel.p_luxury_room, "In Your Range");
        else if ((budget_gap = budget_difference(&hotel_budget, &least_expesive_hotel, '3')) > 0)
            printf(RED "\t%15s : %8d\t : %4s %-5d%13s\n" RESET, "Luxury Room", least_expesive_hotel.p_luxury_room, "PKR.", budget_gap, "Out Of Range");
        }
    }

    while (1)
    {
        int i;
        printf("Please Enter Hotel Name: ");
        scanf("%29[^\n]", choose_name);
        while ( '\n' != getchar() );

        for (i = 0; i < 3; i++)
        {
            if (strcmp(choose_name, listed_hotels[i].hotel_name) == 0)
                // least_expesive_hotel = listed_hotels[i];
                break;
        }
        if ( i != 3 ) {
            clearScreen();
            break;
        }
    }

    least_expesive_hotel = find_hotel_by_name(hotels, hotels_count, choose_name);
    display_selected_hotel( least_expesive_hotel );
    char choice;
    do
    {
        puts("Select among the followings.");
        printf("1.\tStandard Room\n");
        printf("2.\tDelux Room\n");
        printf("3.\tLuxury Room\n=> ");

        choice = getchar();   // reading the room type he want to select
        clear_input_buffer(); // Clearing input buffer

        // pormpting for wrong input
        if (choice < '0' || choice > '3')
        {
            puts("Wrong Input");
            continue;
        }


        if (!add_budget(&hotel_budget, &least_expesive_hotel, choice))
        {
            choice = -1;
            continue;
        }

        // }
    } while (choice < '0' || choice > '3');
    while (1)
    {
        printf("Please Enter Number of Rooms: ");
        if (scanf("%d", &n_rooms) != 1)
        {
            puts(RED "Wrong Input!" RESET);
            clear_input_buffer();
            continue;
        }
        break;
    }



    // GOING TO FIND CARS NOW
    clearScreen();

    unsigned int car_count = 0;
    char user_location[30];

    // ! READING THE USER LOCATION AND MATCHING IT WITH AVILABLE PLACES
    do {
        puts (GREEN"Enter your city name."RESET);
        printf ("=> ");
        scanf ("%s", user_location);
        while ('\n' != getchar() ); // ! clearing buffer

        // cehcking location and breaing the loop
        if ( !(check_name( user_location )) ) { // Matching different variations of spellings of the location

            clearScreen(); // clearing screen 
            puts("\tInvalid Location");
            continue; // iterating again for correct input
        }else 
            break;
    }while ( 1 );

    Car_Rental *cars = find_cars( user_location, &car_count );

    // Handle the case where no cars are found
    if (cars == NULL) {
        return;
    }



    do
    {
        switch (choice)
        {

        case '1':  
            _get_carRentals_under_budegt (cars, car_count, car_budget, location, least_expesive_hotel.hotel_name, "Standard", n_rooms, least_expesive_hotel.p_standard_room, days);
            break;

        case '2':

            _get_carRentals_under_budegt (cars, car_count, car_budget, location, least_expesive_hotel.hotel_name, "Standard", n_rooms, least_expesive_hotel.p_standard_room, days);
            break;

        case '3':
            _get_carRentals_under_budegt (cars, car_count, car_budget, location, least_expesive_hotel.hotel_name, "Standard", n_rooms, least_expesive_hotel.p_standard_room , days);
            break;

        default:
            puts("Wrong Input.");
        }

    } while (1);
}