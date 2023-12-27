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

Hotel find_hotel_by_name(Hotel *hotels, const unsigned int hotels_count, const char *name)
{
    Hotel found_hotel = {0}; // Initialize with default values

    for (unsigned int i = 0; i < hotels_count; ++i)
    {
        if (strcmp(hotels[i].hotel_name, name) == 0)
        {
            found_hotel = hotels[i];
            break;
        }
    }

    return found_hotel;
}

int budget_difference(unsigned int *budget, const Hotel *hotel, const char check_room)
{
    int budget_to_add;
    if (check_room == '1')
        budget_to_add = hotel->p_standard_room - (*budget);
    else if (check_room == '2')
        budget_to_add = hotel->p_delux_room - (*budget);
    else if (check_room == '3')
        budget_to_add = hotel->p_luxury_room - (*budget);
    return budget_to_add;
}

bool add_budget(unsigned int *budget, const Hotel *hotel, const char check_room)
{
    char choice;
    int budget_to_add = 0;
    // there is a filter in its parent function so choice ca never be other than '1', '2', '3'
    if (check_room == '1')
        budget_to_add = hotel->p_standard_room - (*budget);
    else if (check_room == '2')
    {
        budget_to_add = hotel->p_delux_room - (*budget);
        printf("\n%d\n", hotel->p_delux_room);
        printf("\n%d\n", hotel->p_luxury_room);
    }
    else if (check_room == '3')
        budget_to_add = hotel->p_luxury_room - (*budget);

    do
    {
        // break the loop if budget is sufficient
        if (budget_to_add <= 0) return true;
        printf("Do you want to add %d more budget?[Y\\n]", budget_to_add);
        printf("=>");

        choice = getchar();
        clear_input_buffer();
        // while ('\n' != getchar()); // ! clearing buffer

        switch (choice)
        {
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
            puts(RED "Invalid Input." RESET);
            break;
        }
    } while (1);
}

bool check_for_room_budget(const Hotel *least_expensive_hotel, const unsigned int budget, const char choice)
{
    switch (choice)
    {
    case '1':
    {
        if (least_expensive_hotel->p_standard_room > budget)
        {
            puts("Your budget is not sufficent for this room.");
            return false;
        }
        break;
    }

    case '2':
    {
        if (least_expensive_hotel->p_delux_room > budget)
        {
            puts("Your budget is not sufficent for this room.");
            return false;
        }
        break;
    }
    case '3':
    {
        if (least_expensive_hotel->p_luxury_room > budget)
        {
            puts("Your budget is not sufficent for this room.");
            return false;
        }
        break;
    }
    }

    return true;
}

Hotel find_least_expensive_hotel(Hotel *hotels, const unsigned int hotels_count, const unsigned int b_per_day, unsigned int choice)
{

    int least_expensive = 999999999, index = 0, i = 0;
    Hotel NO_MATCH = {0};
    // getting the budget
    int b_offset_value = b_per_day * .1;

    // getting the range according to our budget
    int b_lowest_point = b_per_day - b_offset_value;
    int b_highest_point = b_per_day + b_offset_value;

    switch (choice)
    {
    case 1:
        do
        {
            for (i = 0; i < hotels_count; i++)
            {

                if (least_expensive >= hotels[i].p_standard_room && hotels[i].p_standard_room >= b_lowest_point && hotels[i].p_standard_room <= b_highest_point)
                {
                    least_expensive = hotels[i].p_standard_room;
                    index = i;
                }
            }

            // this condition will only be true if the hotels are in the range lowest and highest point
            if (least_expensive != 999999999)
            {
                break; // this will break our looop
            }
            // if the hotels are not in our range then we are going to decrese our offset value until we get the hotels
            b_lowest_point -= b_offset_value;

            if (b_lowest_point < 0)
            {

                return NO_MATCH;
            }

        } while (1);

        return hotels[index];

    case 2:
        do
        {
            for (i = 0; i < hotels_count; i++)
            {

                if (least_expensive >= hotels[i].p_luxury_room && hotels[i].p_luxury_room >= b_lowest_point && hotels[i].p_luxury_room <= b_highest_point)
                {
                    least_expensive = hotels[i].p_luxury_room;
                    index = i;
                }
            }

            // this condition will only be true if the hotels are in the range lowest and highest point
            if (least_expensive != 999999999)
            {
                break; // this will break our looop
            }
            // if the hotels are not in our range then we are going to decrese our offset value until we get the hotels
            b_lowest_point -= b_offset_value;

            if (b_lowest_point < 0)
            {
                return NO_MATCH;
            }

        } while (1);
        // if (i == hotels_count)
        //     return NO_MATCH;
        return hotels[index];

    case 3:
        do
        {
            for (i = 0; i < hotels_count; i++)
            {

                if (least_expensive >= hotels[i].p_delux_room && hotels[i].p_delux_room >= b_lowest_point && hotels[i].p_delux_room <= b_highest_point)
                {
                    least_expensive = hotels[i].p_delux_room;
                    index = i;
                }
            }

            // this condition will only be true if the hotels are in the range lowest and highest point
            if (least_expensive != 999999999)
            {
                break; // this will break our looop
            }
            // if the hotels are not in our range then we are going to decrese our offset value until we get the hotels
            b_lowest_point -= b_offset_value;

            if (b_lowest_point < 0)
            {
                return NO_MATCH;
            }

        } while (1);

        return hotels[index];
    }
}

void get_hotels_under_budegt(Hotel *hotels, const unsigned int hotels_count, unsigned int b_per_day, unsigned int n_rooms, const char *location)
{

    int budget_gap;
    unsigned int j, index = 0;
    Hotel least_expesive_hotel = {0};
    char choose_name[30];
    Hotel listed_hotels[3];

    for (int i = 1; i <= 3; i++)
    {
        least_expesive_hotel = find_least_expensive_hotel(hotels, hotels_count, b_per_day, i);

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
        if ((budget_gap = budget_difference(&b_per_day, &least_expesive_hotel, '1')) <= 0)
            printf(GREEN "\t%15s : %8d\t : %-23s\n" RESET, "Standard Room", least_expesive_hotel.p_standard_room, "In Your Range");
        else if ((budget_gap = budget_difference(&b_per_day, &least_expesive_hotel, '1')) > 0)
            printf(GREEN "\t%15s : %8d\t : %4s %-5d%13s\n" RESET, "Standard Room", least_expesive_hotel.p_standard_room, "PKR.", budget_gap, "Out Of Range");

        if ((budget_gap = budget_difference(&b_per_day, &least_expesive_hotel, '2')) <= 0)
            printf(CYAN "\t%15s : %8d\t : %-23s\n" RESET, "Delux Room", least_expesive_hotel.p_delux_room, "In Your Range");
        else if ((budget_gap = budget_difference(&b_per_day, &least_expesive_hotel, '2')) > 0)
            printf(CYAN "\t%15s : %8d\t : %4s %-5d%13s\n" RESET, "Delux Room", least_expesive_hotel.p_delux_room, "PKR.", budget_gap, "Out Of Range");

        if ((budget_gap = budget_difference(&b_per_day, &least_expesive_hotel, '3')) <= 0)
            printf(RED "\t%15s : %8d\t : %-23s\n" RESET, "Luxury Room", least_expesive_hotel.p_luxury_room, "In Your Range");
        else if ((budget_gap = budget_difference(&b_per_day, &least_expesive_hotel, '3')) > 0)
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
        if (i != 3) break;
        puts(RED "Invalid! Please Select From The Recommended List" RESET);
    }
    least_expesive_hotel = find_hotel_by_name(hotels, hotels_count, choose_name);
    char choice;
    do
    {
        puts("Select among the followings.(C1)");
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

        // if ( !check_for_room_budget( &least_expesive_hotel, b_per_day, choice )){
        printf("\n%d\n", b_per_day);

        if (!add_budget(&b_per_day, &least_expesive_hotel, choice))
        {
            choice = -1;
            continue;
        }

        // }
    } while (choice < '0' || choice > '3');
    while (1){
    // {   while('\n'!= getchar());
        int check = 1;
        printf("Please Enter Number of Rooms:");
        if (scanf("%d", &n_rooms) != 1)
        {
            puts(RED "Wrong Input!" RESET);
            clear_input_buffer();
            continue;
        }
    
    if (n_rooms <=0){ //! If entered room to book is less than or 0 then exit
        puts("Thank You For Using Our Service!");
        exit(10);
    }

    switch (choice){

    case '1':
        if (least_expesive_hotel.available_standard_room < n_rooms  ){
            printf("%d\n", least_expesive_hotel.available_standard_room);
            puts("Number of Rooms Not Available");
            check = 0;
        }else {
            least_expesive_hotel.available_standard_room -= n_rooms;
            least_expesive_hotel.available_roams -= n_rooms;
            least_expesive_hotel.booked_standard_room += n_rooms;
            least_expesive_hotel.booked_rooms += n_rooms;
        }

        break;
    case '2':
        if (least_expesive_hotel.available_delux_room < n_rooms ){
            puts("Number Of Rooms Not Available");
            check = 0;
        }else least_expesive_hotel.available_delux_room -= n_rooms;
        
        break;
    case '3':
        if (least_expesive_hotel.available_luxury_room < n_rooms ){
            puts("Number of Rooms Not Available");
            check = 0; 
        }else least_expesive_hotel.available_luxury_room -= n_rooms;
    }
        if (check == 0)
            continue;

        else break;
    }

    do
    {
        switch (choice)
        {

        case '1':
       
            update_rooms(least_expesive_hotel.id, 1 , n_rooms); // ! passing to update the rooms
            generate_ticket(least_expesive_hotel.hotel_name, "Standard Room", n_rooms, least_expesive_hotel.p_standard_room, NULL, "", "", location);
            puts("Thank You For Using Our Service!");
            sleep(2);
            exit(EXIT_SUCCESS);
            break;

        case '2':
            update_rooms(least_expesive_hotel.id, 2, n_rooms); // ! passing to update the rooms
            generate_ticket(least_expesive_hotel.hotel_name, "Delux Room", n_rooms, least_expesive_hotel.p_delux_room, NULL, "", "", location);
            puts("Thank You For Using Our Service!");
            sleep(2);
            exit(EXIT_SUCCESS);
            break;

        case '3':
            update_rooms(least_expesive_hotel.id, 3, n_rooms); // ! passing to update the rooms
            generate_ticket(least_expesive_hotel.hotel_name, "Luxury Room", n_rooms, least_expesive_hotel.p_luxury_room, NULL, "", "", location);
            puts("Thank You For Using Our Service!");
            sleep(2);
            exit(EXIT_SUCCESS);
            break;

        default:
            puts("Wrong Input.");
        }

    } while (1);
}

// }
