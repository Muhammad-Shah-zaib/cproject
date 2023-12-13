#include <stdio.h>
#include <stdlib.h>

#include "structHotel.h"
#include "initilizeHotel.h"
#include "registration.h"
#include "hotelLogin.h"
#include "postLogin.h"
#include "read.h"
#include "prompts.h"
#include "clearScreen.h"

int main ( void) {

    // ? prompting user to select among the options
    
    int selection = starting_prompt(); // ? selection_prompt will return values (1, 2, 3)
    
    while ( selection != 3 ) {
        switch (selection)
        {
            case 1: 
                hotel_registration();
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

        selection = starting_prompt();
    }


    
    return 0;
}