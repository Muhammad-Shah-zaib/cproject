#include <stdio.h>

// Prompt User to enter number of days of stay and budget
// then divide the budget with number of days and add 10% to it  and if
// the customer wants both car and room, divide the per day budget into two with 60% ig for hotel and 40 for car

// This function gets the information from the user. It takes in 3 parameters in the form of pointers
void get_info(int *const days, int *const budget, int *const istransport);
// This function clears the buffer if an invalid value if given
void clear_input_buffer();

// This function makes the calculations and provides the range for the hotel, the car budget and the room budget
void make_calculations(const int *days, int *const budget_range, int *const hotel_budget, int *const car_budget, int *const istransport);

int client_Starting_prompt() { // Setting the values to zero
    int days, budget, hotel_budget, car_budget = hotel_budget = budget = days = 0;
    // Giving transport the value of false to start with
    int istransport = 0;
    get_info(&days, &budget, &istransport);
    make_calculations(&days, &budget, &hotel_budget, &car_budget, &istransport);
    printf(" Days : %d \n Total budget : %d \n Hotel Budget: %d \n Car_budget : %d \n ", days, budget, hotel_budget, car_budget);
}

void get_info(int *const days, int *const budget, int *const istransport)
{ // This variable ensures that the correct data is entered
    int input_status = 0;
    do
    { // Getting the input from the user
        puts("Please enter the number of days you are planning to go for:");
        input_status = scanf("%d", days);
        // In case of invalid input clearing the buffer
        if (input_status != 1)
        {
            clear_input_buffer();
        }
    } while (*days <= 0 || input_status != 1);

    do
    {
        puts("Please enter your total budget for the trip");
        input_status = scanf("%d", budget);
        if (input_status != 1)
        {
            clear_input_buffer();
        }
    } while (*budget <= 0 || input_status != 1);

    do
    {
        puts("Are you looking to get transport as well? Enter 1 for yes and 0 for no");
        input_status = scanf("%d", istransport);
        if (input_status != 1)
        {
            clear_input_buffer();
        }
    } while (*istransport != 0 && *istransport != 1);
}

// This function clear the input buffer of all the invalid values which are entered
void clear_input_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}
// This function makes the calculations
void make_calculations(const int *days, int *const budget_range, int *const hotel_budget, int *const car_budget, int *const istransport)
{ //  Updating the the budget for per day
    *budget_range = *budget_range / *days;
    // the user has opted for transport as well this will run
    if (istransport)
    {
        *hotel_budget = 0.6 * *budget_range;
        *car_budget = 0.4 * *budget_range;
    }
    // Else this will run
    else
    {
        *hotel_budget = *budget_range;
        *car_budget = 0;
    }
}