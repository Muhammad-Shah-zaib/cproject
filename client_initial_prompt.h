#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

#include "carConfirmPrompt.h"
#include "hotelReadClient.h"
#include "carReadClient.h"



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
        {"sawaat", "swat"},
        {"hunza", "hunza"},
        {"hunza valley", "hunza"},
        {"murree", "murree"},
        {"muree", "murree"},
        {"murre", "murree"},
        {"murri", "murree"},
        {"muri", "murree"},
        {"babusar", "babusar"},
        {"babusar top", "babusar top"},
        {"kashmir", "kashmir"},
        {"kashmr", "kashmir"},
        {"kashmeer", "kashmir"},
        {"kaashmir", "kashmir"},
        {"gilgit", "gilgit"},
        {"glt", "gilgit"},
        {"gilgt", "gilgit"},
        {"lahore", "lahore"},
        {"laahore", "lahore"},
        {"lahre", "lahore"},
        {"lore", "lahore"},
        {"lhr", "lahore"},
        {"islamabad", "islamabad"},
        {"islam-abad", "islamabad"},
        {"islam abad", "islamabad"},
        {"isb", "islamabad"},
        {"karachi", "karachi"},
        {"krachi", "karachi"},
        {"khi", "karachi"},
        {"rawalpindi", "rawalpindi"},
        {"rwlp", "rawalpindi"},
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
        {"mlt", "multan"},
        {"multaan", "multan"},
        {"sialkot", "sialkot"},
        {"slkt", "sialkot"},
        {"siaalkot", "sialkot"},
        {"gujranwala", "gujranwala"},
        {"gujranwaala", "gujranwala"},
        {"bahawalpur", "bahawalpur"},
        {"bwp", "bahawalpur"},
        {"bhawalpur", "bahawalpur"},
        {"sargodha", "sargodha"},
        {"sgd", "sargodha"},
        {"sargodhaa", "sargodha"},
        {"saargodha", "sargodha"},
        {"abbottabad", "abbottabad"},
        {"abt", "abbottabad"},
        {"abotabad", "abbottabad"},
        {"abtabad", "abbottabad"},
        {"abottabad", "abbottabad"},
        {"abbotabad", "abbottabad"},
        {"dera ismail khan", "dera ismail khan"},
        {"divisions", "divisions"},
        {"jhang", "jhang"},
        {"jhaang", "jhang"},
        {"jhng", "jhang"},
        {"kasur", "kasur"},
        {"kaasur", "kasur"},
        {"kasoor", "kasur"},
        {"kaasoor", "kasur"},
        {"kharian", "kharian"},
        {"khariaan", "kharian"},
        {"sahiwal", "sahiwal"},
        {"sahiwaal", "sahiwal"},
        {"saahiwal", "sahiwal"},
        {"jhelum", "jhelum"},
        {"jhelm", "jhelum"},
        {"jhelam", "jhelum"},
        {"jhlum", "jhelum"},
        {"jhlam", "jhelum"},
        {"bahawalnagar", "bahawalnagar"},
        {"nowshera", "nowshera"},
        {"dera ghazi khan", "dera ghazi khan"},
        {"bannu", "bannu"},
        {"banu", "bannu"},
        {"banno", "bannu"},
        {"kohat", "kohat"},
        {"kohaat", "kohat"},
        {"khat", "kohat"},
        {"koht", "kohat"},
        {"mardan", "mardan"},
        {"mardaan", "mardan"},
        {"maardan", "mardan"},
        {"mrdan", "mardan"},
        {"chakwal", "chakwal"},
        {"chakwaal", "chakwal"},
        {"chaakwal", "chakwal"},
        {"chkwal", "chakwal"},
        {"chkwaal", "chakwal"},
        {"swabi", "swabi"},
        {"swbi", "swabi"},
        {"swaabi", "swabi"},
        {"sawabi", "swabi"},
        {"saawabi", "swabi"},
        {"jacobabad", "jacobabad"},
        {"jacobaabad", "jacobabad"},
        {"jaacobabad", "jacobabad"},
        {"jacobad", "jacobabad"},
        {"jaccobabad", "jacobabad"},
        {"okara", "okara"},
        {"okaara", "okara"},
        {"okaraa", "okara"},
        {"dadu", "dadu"},
        {"chaman", "chaman"},
        {"chaaman", "chaman"},
        {"chamaan", "chaman"},
        {"chamann", "chaman"},
        {"turkham", "turkham"},
        {"sukkur", "sukkur"},
        {"sukur", "sukkur"},
        {"sukkar", "sukkur"},
        {"larkana", "larkana"},
        {"larkaana", "larkana"},
        {"larkanaa", "larkana"},
        {"laarkana", "larkana"},
        {"nawabshah", "nawabshah"},
        {"nawaabshah", "nawabshah"},
        {"mirpurkhas", "mirpurkhas"},
        {"mirpurkhaas", "mirpurkhas"},
        {"muzaffarabad", "muzaffarabad"},
        {"muzafarabad", "muzaffarabad"},
        {"muzzaffarabad", "muzaffarabad"},
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
                    // both_read_client ( location ) // location is a string
                    puts ("case 3");
                    break;

            }
        getchar();

    } while (choice != '0'); // ! condition for the while loop (0 to exit)

}

