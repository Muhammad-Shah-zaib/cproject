#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

#include "check_location.h"
#include "recommendationGetBudget.h"
#include "carConfirmPrompt.h"
#include "hotelReadClient.h"
#include "carReadClient.h"
#include "CarxHotelReadClient.h"











void client_initial_prompt( void ) {

    
    char choice = '\0', location[30]; 

    clearScreen();

    puts("\n\tWelcome"); // WELCOME PROMPT

    do
    {
        // reading the DESTINATION
        
        printf("Please enter your destination:\n");
        scanf("%29[^\n]", location); // ! Taking location as input with spaces allowed

        while (getchar() != '\n'); // ! Clearing buffer


        if ( !(check_name(location)) ) { // Matching different variations of spellings of the location
            
            clearScreen(); // clearing screen 
            puts("\tInvalid Location");
            continue; // iterating again for correct input
        }

        while (choice < '0' || choice > '3') {

            printf("What are you looking for:\n" 
                    "1.\tHotel Bookings\n"
                    "2.\tCar Rental\n"
                    "3.\tBoth\n"
                    "\t0 to Exit\n=> ");
            if (scanf("%c", &choice) != 1) {// checking for valid int input

                clearScreen();
                puts("\tWrong Input");

                while('\n' != getchar()); // clearing input buffer


                continue;
            }
        }


            switch(choice){

                case '1': 
                    hotel_read_client( location ); // location is a string
                    puts ("case 1");
                    break;

                case '2': 
                    car_read_client( location ); // location is a string
                    puts ("case 2");
                    break;

                case '3':
                    both_read_client ( location ); // location is a string
                    puts ("case 3");
                    break;

            }
        getchar();

    } while (choice != '0'); // ! condition for the while loop (0 to exit)

}

