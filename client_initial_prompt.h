#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

#include "hotelReadClient.h"



bool check_name(char *location) {
    char lowercase_name[30];  // Assuming a maximum length for the location
    strcpy(lowercase_name, location);

    // Convert the location to lowercase for case-insensitive comparison
    for (int i = 0; lowercase_name[i]; i++) {
        lowercase_name[i] = tolower(lowercase_name[i]);
    }

    // Array of valid city names and variations
    const char *standard_location[][2] = {
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
    {"gilgit", "gilgit"},
    {"lahore", "lahore"},
    {"lhr", "lahore"},
    {"islamabad", "islamabad"},
    {"isb", "islamabad"},
    {"karachi", "karachi"},
    {"khi", "karachi"},
    {"rawalpindi", "rawalpindi"},
    {"rwp", "rawalpindi"},
    {"quetta", "quetta"},
    {"queta", "quetta"},
    {"quetta", "quetta"},
    {"peshawar", "peshawar"},
    {"pshawar", "peshawar"},
    {"peshawer", "peshawar"},
    {"faisalabad", "faisalabad"},
    {"fasalabad", "faisalabad"},
    {"faislabad", "faisalabad"},
    {"faisalabd", "faisalabad"},
    {"fsd", "faisalabad"},
    {"multan", "multan"},
    {"sialkot", "sialkot"},
    {"gujranwala", "gujranwala"},
    {"bahawalpur", "bahawalpur"},
    {"sargodha", "sargodha"},
    {"abbottabad", "abbottabad"},
    {"dera ismail khan", "dera ismail khan"},
    {"divisions", "divisions"},
    {"jhang", "jhang"},
    {"kasur", "kasur"},
    {"kharian", "kharian"},
    {"sahiwal", "sahiwal"},
    {"jhelum", "jhelum"},
    {"bahawalnagar", "bahawalnagar"},
    {"nowshera", "nowshera"},
    {"dera ghazi khan", "dera ghazi khan"},
    {"bannu", "bannu"},
    {"kohat", "kohat"},
    {"mardan", "mardan"},
    {"chakwal", "chakwal"},
    {"swabi", "swabi"},
    {"jacobabad", "jacobabad"},
    {"okara", "okara"},
    {"dadu", "dadu"},
    {"chaman", "chaman"},
    {"turkham", "turkham"},
    {"sukkur", "sukkur"},
    {"larkana", "larkana"},
    {"nawabshah", "nawabshah"},
    {"mirpurkhas", "mirpurkhas"},
    {"muzaffarabad", "muzaffarabad"},
    {"bhimber", "bhimber"},
    {"havelian", "havelian"},
    {"kamra", "kamra"},
    {"muridke", "muridke"},
    {"pindi gheb", "pindi gheb"},
    {"raiwind", "raiwind"},
    {"shahdadkot", "shahdadkot"},
    {"sibi", "sibi"},
    {"tando adam", "tando adam"},
    {"zhob", "zhob"}
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
                    hotel_read_client( location ); // location is a string
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
        getchar();

    } while (choice != '0'); // ! condition for the while loop (0 to exit)

}

