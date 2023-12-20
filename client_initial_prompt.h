#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>




bool check_name(char *location) {
    char lowercase_name[30];  // Assuming a maximum length for the location
    strcpy(lowercase_name, location);

    // Convert the location to lowercase for case-insensitive comparison
    for (int i = 0; lowercase_name[i]; i++) {
        lowercase_name[i] = tolower(lowercase_name[i]);
    }

    // Array of valid city names and variations
    const char *standard_location [][2] = {
        {"skardu", "skardu"},
        {"sakardo", "skardu"},
        {"sakardu", "skardu"},
        {"nathia gali", "nathia gali"},
        {"nathiagali", "nathia gali"},
        {"swat", "swat"},
        {"sawat", "swat"},
        {"hunza", "hunza"},
        {"hunza valley", "hunza"},
        {"murree", "murree"},
        {"muree", "murree"},
        {"murre", "murree"},
        {"babusar", "babusar"},
        {"babusar top", "babusar top"},
        {"kashmir", "kashmir"},
        {"gilgit", "gilgit"}
    };

    // Compare the lowercase location with the valid names and update if necessary
    unsigned int size_of_standard_location = sizeof(standard_location) / sizeof(standard_location[0]);

    for (unsigned int i = 0; i < size_of_standard_location; i++) {
        if (strcmp(lowercase_name, standard_location[i][0]) == 0) {
            strcpy(location, standard_location[i][1]);
            return true;
        }
    }

    return false;
}








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
                    "3.\tBoth\n\n"
                    "\t0 to Exit\n");
            if (scanf("%c", &choice) != 1) {// checking for valid int input

                clearScreen();
                puts("\tWrong Input");

                getchar(); // clearing input buffer

                continue;
            }
        }

            switch(choice){

                case '1': 
                    // hotel_read_client( location ); // location is a string
                    puts ("case 1");
                    break;

                case '2': 
                    // car_read_client(location); // location is a string
                    puts ("case 2");
                    break;

                case '3':
                    // both_read_client ( location ) // location is a string
                    puts ("case 3");
                    break;

            }


    } while (choice != '0'); // ! condition for the while loop (0 to exit)

}