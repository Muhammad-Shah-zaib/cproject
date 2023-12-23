#include <stdio.h>
#include <string.h>
#include <stdlib.h>



#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"
#define CYAN "\033[1;36m"
#define RESET "\033[1;0m"




Hotel find_least_expensive_hotel (Hotel *hotels, const unsigned int hotels_count, const unsigned int b_lowest_point, const unsigned int b_highest_point){
    
    int least_expensive  = hotels[0].p_standard_room, index = 0;
    for (int i = 1; i < hotels_count ; i++) {

        if ( least_expensive > hotels[i].p_standard_room && hotels[i].p_standard_room > b_lowest_point && hotels[i].p_standard_room < b_highest_point ){
            least_expensive = hotels[i].p_standard_room;
            index = i;
        }
    }

    return hotels[index];
}






void get_hotels_under_budegt( Hotel *hotels, const unsigned int hotels_count, const unsigned int b_per_day, const unsigned int n_rooms, const char *location ) {

    Hotel least_expesive_hotel = find_least_expensive_hotel ( hotels, hotels_count, (b_per_day - (b_per_day * .3)), (b_per_day + (b_per_day * .3)) );

    if ( b_per_day >= least_expesive_hotel.p_standard_room) {

        // NOW DISPLAYING ALL THE ROOM TYPES OF THEIS HOTEL
        printf (BLUE"\nHotel name: %s\n", least_expesive_hotel.hotel_name);
        printf ("Location: %s\n\n"RESET, least_expesive_hotel.city_name);

        printf (YELLOW"\t%15s : %15s\n"RESET,"Room Type", "Price per night");

        printf (GREEN"\t%15s : %15d\n"RESET, "Standard Room", least_expesive_hotel.p_standard_room);


        // displaying the delux and luxury room if he can affor them only
        if (b_per_day >= least_expesive_hotel.p_delux_room)
            printf (CYAN"\t%15s : %15d\n"RESET, "Delux Room", least_expesive_hotel.p_delux_room);
        
        if ( b_per_day >= least_expesive_hotel.p_luxury_room)
            printf (RED"\t%15s : %15d\n"RESET, "Luxury Room", least_expesive_hotel.p_standard_room);


        puts ("Select among the followings.");
        printf ("1.\tStandard Room\n");
        printf ("2.\tDelux Room\n");
        printf ("3.\tLuxury Room\n=> ");
        char choice = getchar(); // reading the room type he want to select
        while ( '\n' != getchar() ); // clearing the buffer

        switch (choice) {

            case '1':
                generate_ticket (least_expesive_hotel.hotel_name, "Standard Room",  n_rooms , least_expesive_hotel.p_standard_room, NULL, "", "", location);
                puts ("Thanks for using this service.");
                exit (EXIT_SUCCESS);
                sleep(2);
                break;

            case '2':
                generate_ticket (least_expesive_hotel.hotel_name, "Delux Room",  n_rooms , least_expesive_hotel.p_delux_room, NULL, "", "", location);
                puts ("Thanks for using this service.");
                exit (EXIT_SUCCESS);
                sleep(2);
                break;

            case '3':
                generate_ticket (least_expesive_hotel.hotel_name, "Luxury Room",  n_rooms , least_expesive_hotel.p_luxury_room, NULL, "", "", location);
                puts ("Thanks for using this service.");
                exit (EXIT_SUCCESS);
                sleep(2);
                break;

            }
    }

}
