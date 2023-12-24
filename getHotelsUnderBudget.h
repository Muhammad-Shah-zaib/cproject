#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>



#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"
#define CYAN "\033[1;36m"
#define RESET "\033[1;0m"


bool add_budget( unsigned int *budget, const Hotel *hotel, const char check_room ){
    char choice;
    int budget_to_add = 0;
    // there is a filter in its parent function so choice ca never be other than '1', '2', '3'
    if ( check_room == '1' ) budget_to_add =  hotel->p_standard_room - (*budget);
    else if ( check_room == '2' ) budget_to_add =  hotel->p_delux_room - (*budget);
    else if ( check_room == '3' ) budget_to_add =  hotel->p_luxury_room - (*budget);

    do {
        printf ("Do you want to add %d more budget?[Y\\n]", budget_to_add);
        printf ("=>");

        choice = getchar();
        while ('\n' != getchar()); // ! clearing buffer
        
        switch ( choice ){
            case 'Y':
            case 'y':
            case '1':
                (*budget) += budget_to_add;
                return true;

            case 'N':
            case 'n':
            case '0':
                return false;

            default:
                puts (RED"Invalid Input."RESET);
                break;
        }
    } while ( 1 );
}







bool check_for_room_budget( const Hotel *least_expensive_hotel, const unsigned int budget, const char choice ){
    switch ( choice ){
        case '1': {
            if ( least_expensive_hotel->p_standard_room > budget ){
                puts ("Your budget is not sufficent for this room.");
                return false;
            }
            break;
        }

        case '2': {
            if ( least_expensive_hotel->p_delux_room > budget ){
                puts ("Your budget is not sufficent for this room.");
                return false;
            }
            break;
        }
        case '3': {
            if ( least_expensive_hotel->p_luxury_room > budget ){
                puts ("Your budget is not sufficent for this room.");
                return false;
            }
            break;
        }
    }

    return true;
}







Hotel find_least_expensive_hotel (Hotel *hotels, const unsigned int hotels_count, const unsigned int b_per_day){
    
    int least_expensive  = 999999999, index = 0;

    // getting the budget
    int b_offset_value = b_per_day * .1;

    // getting the range according to our budget
    int b_lowest_point = b_per_day - b_offset_value;
    int b_highest_point = b_per_day + b_offset_value;

    do {
        for (int i = 0; i < hotels_count ; i++) {

            if ( least_expensive > hotels[i].p_standard_room && hotels[i].p_standard_room > b_lowest_point && hotels[i].p_standard_room < b_highest_point ){
                least_expensive = hotels[i].p_standard_room;
                index = i;
            }
        }

        // this condition will only be true if the hotels are in the range lowest and highest point 
        if ( least_expensive != 999999999 ){
            break; // this will break our looop
        } 
        // if the hotels are not in our range then we are going to decrese our offset value until we get the hotels
        b_lowest_point -= b_offset_value;

        if (b_lowest_point < 0) {
            puts ("Not sufficient balance.");
            exit (8);
        }

    }while (1);


    return hotels[index];
}






void get_hotels_under_budegt( Hotel *hotels, const unsigned int hotels_count,  unsigned int b_per_day, const unsigned int n_rooms, const char *location ) {

    Hotel least_expesive_hotel = find_least_expensive_hotel ( hotels, hotels_count, b_per_day );

    if ( b_per_day >= least_expesive_hotel.p_standard_room) {

        // NOW DISPLAYING ALL THE ROOM TYPES OF THEIS HOTEL
        printf (BLUE"\nHotel name: %s\n", least_expesive_hotel.hotel_name);
        printf ("Location: %s\n\n"RESET, least_expesive_hotel.city_name);

        printf (YELLOW"\t%15s : %15s\n"RESET,"Room Type", "Price per night");

        printf (GREEN"\t%15s : %15d\n"RESET, "Standard Room", least_expesive_hotel.p_standard_room);


        // displaying the delux and luxury room if he can affor them only
        printf (CYAN"\t%15s : %15d\n"RESET, "Delux Room", least_expesive_hotel.p_delux_room);

        printf (RED"\t%15s : %15d\n"RESET, "Luxury Room", least_expesive_hotel.p_luxury_room);

        char choice;
        do {
            puts ("Select among the followings.");
            printf ("1.\tStandard Room\n");
            printf ("2.\tDelux Room\n");
            printf ("3.\tLuxury Room\n=> ");

            choice = getchar(); // reading the room type he want to select
            while ( '\n' != getchar() ); // clearing the buffer

            // pormpting for wrong input 
            if ( choice < '0' || choice > '3' ){
                puts ("Wrong Input");
                continue;
            }
            
            if ( !check_for_room_budget( &least_expesive_hotel, b_per_day, choice )){
                if ( !add_budget( &b_per_day, &least_expesive_hotel, choice ) ){
                    choice = -1; 
                    continue;
                }
                
            }
        }while ( choice < '0' || choice > '3');


        do {
            switch (choice) {

                case '1':
                    generate_ticket (least_expesive_hotel.hotel_name, "Standard Room",  n_rooms , least_expesive_hotel.p_standard_room, NULL, "", "", location);
                    puts ("Thanks for using this service.");
                    sleep(2);
                    exit (EXIT_SUCCESS);
                    break;

                case '2':
                    generate_ticket (least_expesive_hotel.hotel_name, "Delux Room",  n_rooms , least_expesive_hotel.p_delux_room, NULL, "", "", location);
                    puts ("Thanks for using this service.");
                    sleep(2);
                    exit (EXIT_SUCCESS);
                    break;

                case '3':
                    generate_ticket (least_expesive_hotel.hotel_name, "Luxury Room",  n_rooms , least_expesive_hotel.p_luxury_room, NULL, "", "", location);
                    puts ("Thanks for using this service.");
                    sleep(2);
                    exit (EXIT_SUCCESS);
                    break;

                default:
                    puts("Wrong Input.");
                }

        }while ( 1 );
    }

}
