#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>




short int premium_find_car_modal_index(const Car_Rental *car, const unsigned int id, const char *modal_name, const unsigned int modal) {

    // getting the index
    for ( unsigned int i = 0; i < car->n_premium; i++ ) {
        if ( (car->premium[i].modal == modal) && (strcmp((car->premium[i].name), modal_name) == 0) ) {
            return i;
        }
    }

    // promppting and returning -1 if index not ofund
    printf("Car with modal number (%u : %s) not found.\n", modal, modal_name );
    return -1;
}


void premium_delete_car_modal (Car_Rental *car, const unsigned int index, const unsigned int id){

    // making a file pointer for "cars.dat"
    FILE *cfptr;

    // checking for file openeing
    if ( (cfptr = fopen ("cars.dat", "rb+")) == NULL ){
        puts ("The file can not be opened.");
        exit (1);
    }

    // deleting the given car
    for ( unsigned int i = index ; i < car->n_non_suv; i++ ){
            car->premium[i] = car->premium[i+1]; // just reducing all the further index after indexToDelete
    }
    car->n_premium--; // updating the total premium cars
    car->n_total_cars--; // updating the total cars
    car->available_cars--; // updating the available cars

    // printing the updated list of cars
    for (int i = 0; i < car->n_premium; i++) {
        printf ("%d: %s\n", (car->premium[i].modal), car->premium[i].name );
    }

    // ! GOING TO UPDATE THE FILE 
    rewind(cfptr); // just rewinding the pointer to the start,( for surrety )
    
    fseek ( cfptr, (id-1) * sizeof (Car_Rental), SEEK_SET );// off setting the poitner
    fwrite( car, sizeof(Car_Rental), 1, cfptr ); // updating the files ( in buffer )
    fflush(cfptr); // flushing the content into file ( for surety )

    fclose (cfptr); // closing the file

    puts("Press Enter to continue.");
    getchar();
    getchar();
}




void delete_premium( Car_Rental *car, const unsigned int id){

    // decaliring the variables
    unsigned int modal;
    char modal_name[30];

    // reading mdoal
    printf ("Enter modal");
    scanf ("%d", &modal);
    modal = abs ( modal ); // making sure the modal number is always positive
    
    // reading modal name
    printf ("Enter modal name: ");
    scanf ("%s", modal_name);

    // dont need to read the data as it is already passed in the function
    const short int indexToDelete = premium_find_car_modal_index(car, id, modal_name, modal); 

    // deleting the car modal only if indexToDelete is a valid index
    if ( -1 != indexToDelete ) {
        premium_delete_car_modal ( car, indexToDelete, id );
    }


    
}
