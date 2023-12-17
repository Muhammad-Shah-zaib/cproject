#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>



short int suv_find_car_modal_index(const Car_Rental *car, const unsigned int id, const char *modal_name, const unsigned int modal) {
    // finding the index
    for (unsigned int i = 0; i < car->n_suv; ++i) {
        if ( car->suv[i].modal == modal && (strcmp((car->suv[i].name), modal_name) == 0) ) {
            return i;
        }
    }

    // pormpting and returning -1 if index not found
    printf("Car with (modal=> %u\t:\nname: %s) not found.\n", modal, modal_name );
    return -1;
}

void suv_delete_car_modal (Car_Rental *car, const unsigned int index, const unsigned int id){

    // making a file pointer for "cars.dat"
    FILE *cfptr;

    // cehcking for file openeing
    if ( (cfptr = fopen ("cars.dat", "rb+")) == NULL ){
        puts ("The file can not be opened.");
        exit (1);
    }

    // printing the updated list
    for  (unsigned int i = index ; i < car->n_suv; i++ ){
            car->suv[i] = car->suv [i+1]; // just reducing all the further index after indexToDelete
    }
    car->n_suv--; // updating suv cars
    car->n_total_cars--; // updating total cars
    car->available_cars--; // updating available cars

    //printing the updated list of cars
    for (int i = 0; i < car->n_suv; i++) {
        printf ("%d: %s\n", (car->suv[i].modal), car->suv[i].name );
    }

    rewind(cfptr);// just rewinding file ptr to start, ( for surety )

    fseek ( cfptr, (id-1) * sizeof (Car_Rental), SEEK_SET ); // offsetting the poitner
    fwrite( car, sizeof(Car_Rental), 1, cfptr ); // wrting the updated info in buffer
    fflush(cfptr); // flushing the updated buffer ( for surety )

    fclose(cfptr); // closing the pointer

    puts("Press Enter to continue.");
    getchar();
    getchar();
}

void delete_suv(Car_Rental *car, const unsigned int id){

    // decaliring the variables
    unsigned int modal;
    char modal_name[30];

    // reading mdoal
    printf ("Enter modal");
    scanf ("%d", &modal);
    modal = abs( modal ); // keeping the modal value a positive int

    // reading modal name
    printf ("Enter modal name: ");
    scanf ("%s", modal_name);


    // dont need to read the data as it is already passed in the function
    const unsigned short int indexToDelete = suv_find_car_modal_index(car, id, modal_name, modal); 

    // checking for valid indexToDelete
    if ( -1 != indexToDelete ) {
        suv_delete_car_modal(car, indexToDelete, id);
    }


}