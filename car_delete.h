#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "delete_suv.h"
#include "delete_non_suv.h"
#include "delete_premium.h"

void delete_car ( unsigned int id ){
    // creating a file pointe rto open cars.dat
    FILE *cfptr;

    // checking for file opening
    if ( (cfptr = fopen ("cars.dat", "rb")) == NULL ){ // ! OPENING ONLY IN READ-BINARY ( rb ) 
        puts ("File can not be opened.");
        exit (1); // termimnating the program with 1
    }

    // making empty car to store data
    Car_Rental car = generate_empty_car();

    // offsetting and reading the data
    fseek (cfptr, (id-1) * sizeof (Car_Rental), SEEK_SET);
    fread (&car, sizeof (Car_Rental), 1, cfptr);

    fclose (cfptr); // closing the pointer 


    char choice; // for car type to delete 

    do{
        clearScreen();

        // prompting the user id and username ( ar top )
        printf ("Id: %u\nUsername: %s\n", car.id, car.username); 

        // prompt the user
        printf("Please Select the Car Type (to Delete):\n"
                "0.\tExit\n"
                "1.\tDelete SUV\n"
                "2.\tDelete non-SUV\n"
                "3.\tDelete premium\n");
        choice = getchar (); // reading the choice

        switch (choice)
        {
        case '1': // *FOR SUV
            delete_suv( &car, car.id );
            break;

        case '2': // * FOR NON_SUV
            delete_non_suv( &car, car.id);
            break;
        case '3': // * FOR PREMIUM 
            delete_premium( &car, car.id);
            break;
        case '0':
            return;
            
        default:
            break;
        }

    }while(1);

}

