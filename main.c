#include <stdio.h>
#include <stdlib.h>

#include "clearScreen.h"
#include "structHotel.h"
#include "structCarRental.h"
#include "emptyCarGenerator.h"
#include "postLogin.h"
#include "prompts.h"
#include "hotelRegistration.h"
#include "hotelLogin.h"
#include "carRentalRegistration.h"
#include "carLogin.h"
#include "carPostLogin.h"

// Define color codes
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"
#define CYAN "\033[1;36m"
#define RESET "\033[1;0m"





int main ( void) {

    // ? prompting user to select among the options
    clearScreen();
    int selection = starting_prompt(); // ? selection_prompt will return values (1, 2, 3)
    
    while ( selection != 3 ) {
        switch (selection)
        {
            case 1: {
                
                char choice; // checking for hotel_registration or car_rental_registration

                do{
                    clearScreen(); // clearing th eterminal screen

                    puts ("Select among the followings: ");
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

            }





            case 2:{

                char choice; // checking for hotel_login or car_login

                do{
                    clearScreen(); // clearing th eterminal screen
                    puts ("Choose among the following");
                    printf ("%s\n%s\n%s\n", // pompting suer
                        "0.\tExit",
                        "1.\tHotel Login.",
                        "2.\tCar Rental Login.");
                    choice = getchar(); // reading the choice

                    switch (choice) {
                        case '0': // to exit
                            break;

                        case '1':{ // for hotel
                            unsigned int id;
                            char name[20];

                            do {
                                // reading the credentials
                                printf ("Enter id: ");
                                scanf ("%d", &id);
                                printf ("Enter username: ");
                                scanf ("%19s", name);

                            } while ( !(hotel_login(id, name)) );
                            
                            post_login ( id );
                            break;
                        }

                        case '2': { // for car_rental
                            unsigned int id;
                            char name[20];

                            do {
                                // reading the credentials
                                printf ("Enter Car-Rental id: ");
                                scanf ("%d", &id);
                                printf ("Enter username: ");
                                scanf ("%19s", name);

                            } while ( !(car_login(id, name)) );
                            
                            car_post_login ( id );
                            break;
                        }


                        // ! IGNORING MISTAKES
                        default:
                            break;
                    }
                
                }while(choice != '0'); // cehcking for exit or not


                // declairing the credentials
                
                break;
            }
        }
        clearScreen();
        selection = starting_prompt();
    }


    
    return 0;
}