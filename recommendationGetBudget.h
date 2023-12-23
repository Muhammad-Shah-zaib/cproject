#include <stdio.h>
#include <stdbool.h>

// Prompt User to enter number of days of stay and budget
// then divide the budget with number of days and add 10% to it  and if
// the customer wants both car and room, divide the per day budget into two with 60% ig for hotel and 40 for car



// This function clear the input buffer of all the invalid values which are entered
void clear_input_buffer( void ) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}






// This function gets the information from the user. It takes in 3 parameters in the form of pointers
void get_info( int * days, int  *budget ) { // This variable ensures that the correct data is entered
    clearScreen();  
    int input_status = 0;

    // ! READING DAYS
    do {

        printf("Please enter the number of days you are planning to go for\n=> ");
        input_status = scanf("%d", days);
        clear_input_buffer();

        if ( (*days) <= 0 || input_status != 1 )
            puts ("Invalid input.");

    } while ( (*days) <= 0 || input_status != 1 );


    // ! READING BUDGET
    do {

        printf("Please enter your total budget for the trip\n=> ");
        input_status = scanf("%d", budget);
        clear_input_buffer();

        // prompting for invalid input
        if ( (*budget) <= 0 || input_status != 1 )
            puts ("Invalid Input.");

    } while ( (*budget) <= 0 || input_status != 1 );

}





// This function makes the calculations and provides the range for the hotel, the car budget and the room budget
void make_calculations(const int *days, int *const budget_range, int *const hotel_budget,  int *const car_budget, const bool istransport) { //  Updating the the budget for per day

    ( *budget_range ) /= *days; // getting budget per day



    // the user has opted for transport as well we will divide the budget per day as =>
    // 60 % => HOTEL
    // 40 % => CARS 
    if (istransport) {
        ( *hotel_budget ) = 0.6 * ( *budget_range );
        ( *car_budget ) = 0.4 * ( *budget_range );
    }
    // Else this will run
    else {
        ( *hotel_budget ) = ( *budget_range );
        ( *car_budget ) = 0;
    }
}

