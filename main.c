#include <stdio.h>

#include "structHotel.h"
#include "initilizeHotel.h"
#include "registration.h"
#include "hotelLogin.h"
#include "read.h"
#include "prompts.h"

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
                if( hotel_login() ){ // hotel_login() => returns either true or false
                    post_login(); // Present in prompts.h
                }
                break;
        }

        selection = starting_prompt();
    }


    
    return 0;
}