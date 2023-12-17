#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"
#define CYAN "\x1b[36m"
#define RESET "\x1b[0m"



int non_suv_find_car_modal_index(const Car_Rental *car, const unsigned int id, const char *modal_name, const unsigned int modal) {

    // getting the index
    for ( unsigned int i = 0; i < car->n_non_suv; i++ ) {
        if ( car->non_suv[i].modal == modal && (strcmp((car->non_suv[i].name), modal_name) == 0) ) {
            return i;
        }
    }

    // promppting and returning -1 if car modal not found
    printf(RED"Car with (modal=> %u\t:\tname=> %s) not found.\n"RESET, modal, modal_name );
    getchar(); // ignoring enter 
    getchar();
    return -1;
}




void non_suv_delete_car_modal (Car_Rental *car, const unsigned int index, const unsigned int id){

    // making a file pointer for "cars.dat"
    FILE *cfptr;

    // checking for file openeing
    if ( (cfptr = fopen ("cars.dat", "rb+")) == NULL ){ // ! OPENING IN UPDATE BINARY MODE ( rb+ )
        puts ("The file can not be opened.");
        exit (1);
    }

    // deleting the given car
    for  ( unsigned int i = index ; i < car->n_non_suv; i++ ){
            car->non_suv[i] = car->non_suv[i+1]; // just reducing all the further index after indexToDelete
    }
    car->n_non_suv--; // updating the total non_suv_cars
    car->n_total_cars--; // updating the total cars
    car->available_cars--; // updating the available cars

    puts (GREEN"Cars deleted successfully." RESET);
    printf (BLUE"\nTotal non_SUVs: %d\n"RESET, car->n_non_suv);

    // printing the updated list of cars
    for (int i = 0; i < car->n_non_suv; i++) {
        printf (CYAN"%d.\t%d: %s\n"RESET, i+1, (car->non_suv[i].modal), car->non_suv[i].name );
    }

    // ! GOING TO UPDATE THE FILE 
    rewind(cfptr); // just rewindin the pointer to the start, for surrety
    
    fseek ( cfptr, (id-1) * sizeof (Car_Rental), SEEK_SET );// off setting the poitner
    fwrite( car, sizeof(Car_Rental), 1, cfptr ); // updating the files ( in buffer )
    fflush(cfptr); // flushing the content into file for surety

    fclose (cfptr); // closing the file

    puts(YELLOW"\nPress Enter to continue."RESET);
    getchar();
    getchar();
}






void delete_non_suv( Car_Rental *car, const unsigned int id){
    // ! dont need to read the data as it is already passed in the function

    if ( 0 == car->n_non_suv ) {
        puts (RED"non_SUVs can not be deleted, as there is no non_SUV added yet");
        printf(RED"=>Total non_SUVs: %d\n"RESET, car->n_non_suv);
        puts (YELLOW "Press Enter to conitnue."RESET);
        getchar(); // ignoring enter
        getchar();
        return;
    }

    // decaliring the variables
    unsigned int modal;
    char modal_name[30];

    // reading mdoal
    printf ("Enter model: ");
    scanf ("%d", &modal);
    modal = abs( modal ); // keeping the modal value a positive int

    // reading modal name
    printf ("Enter model name: ");
    scanf ("%s", modal_name);


    //getting the index of the given modal
    const short int indexToDelete = non_suv_find_car_modal_index(car, id, modal_name, modal); 

    // deleting the car modal if the indexToDelete is valid 
    if ( -1 != indexToDelete ) {
        non_suv_delete_car_modal ( car, indexToDelete, id );
    }

}