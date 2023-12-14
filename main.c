#include <stdio.h>
#include <stdlib.h>

#include "structHotel.h"
#include "initilizeHotel.h"
#include "hotelRegistration.h"
#include "carRentalRegistration.h"
#include "hotelLogin.h"
#include "postLogin.h"
#include "read.h"
#include "prompts.h"
#include "clearScreen.h"

int main ( void) {

    // ? prompting user to select among the options
    clearScreen();
    int selection = starting_prompt(); // ? selection_prompt will return values (1, 2, 3)
    
    while ( selection != 3 ) {
        switch (selection)
        {
            case 1: 
                
                char choice; // checking for hotel_registration or car_rental_registration
                puts ("Select among the followings: ");

                do{
                    clearScreen(); // clearing th eterminal screen

                    printf ("%s\n%s\n%s\n", // pompting suer
                        "0.\tExit",
                        "1.\tHotel registration.",
                        "2.\tCar Rental registratoin.");
                    choice = getchar(); // reading the choice

                    switch (choice) {
                        case '0': // to exit
                            break;

                        case '1': // for hotel
                            hotel_registration();
                            break;

                        case '2': // for car_rental
                            car_rental_registration();
                            break;

                        // ! IGNORING MISTAKES
                        default:
                            break;
                    }
                
                }while(choice != '0'); // cehcking for exit or not

                break;

            case 2:
                    // declairing the credentials
                    unsigned int id;
                    char name[20];

                do {
                    // reading the credentials
                    printf ("Enter id: ");
                    scanf ("%d", &id);
                    printf ("Enter name: ");
                    scanf ("%19s", name);

                } while ( !(hotel_login(id, name)) );
                
                post_login ( id );
                break;
        }

        clearScreen();
        selection = starting_prompt();
    }


    
    return 0;
}