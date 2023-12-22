#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>

// #include "structCarRental.h"

// Define color codes
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"
#define CYAN "\033[1;36m"
#define RESET "\033[1;0m"


void display_selected_car_rental (Car_Rental *car) {
    clearScreen(); // Assuming you have a function to clear the screen


    printf(BLUE"\n+------------------------------+\n"RESET);
    printf(BLUE"|      Car Rental Details      |\n"RESET);
    printf(BLUE"+------------------------------+\n"RESET);
    printf(GREEN"\nCompany name: %s\n", car->company_name);
    printf("Location: %s\n", car->city_name);
    printf(BLUE"------------SUV Cars------------\n"RESET);
    printf(CYAN"Available Cars: %u\n\n", car->n_suv);
    for (unsigned int i = 0; i < car->n_suv; ++i) {
        printf(GREEN"=>%d.\tModel: %u, Price: %u, Name: %s\n"RESET, i+1, car->suv[i].modal, car->suv[i].price, car->suv[i].name);
    }
    printf(BLUE"---------Non-SUV Cars---------\n"RESET);
    printf(CYAN"Available Cars: %u\n\n", car->n_non_suv);
    for (unsigned int i = 0; i < car->n_non_suv; ++i) {
        printf(GREEN"=>%d.\tModel: %u, Price: %u, Name: %s\n"RESET, i+1, car->non_suv[i].modal, car->non_suv[i].price, car->non_suv[i].name);
    }
    printf(BLUE"---------Premium Cars---------\n"RESET);
    printf(CYAN"Available Cars: %u\n\n"RESET, car->n_premium);
    for (unsigned int i = 0; i < car->n_premium; ++i) {
        printf(GREEN"=>%d.\tModel: %u, Price: %u, Name: %s\n"RESET, i+1, car->premium[i].modal, car->premium[i].price, car->premium[i].name);
    }


}

void display_cars ( Car_Modal *car, int car_count ){
    puts(BLUE"---------------------------------------------------------");

    for (int i = 0 ; i < car_count ; i++ ){
        printf (YELLOW"%d.\t" CYAN"Model: %d,Model Name: %s, price: %d\n"RESET
            , i+1, car[i].modal, car[i].name, car[i].price);
    }
    puts(BLUE"---------------------------------------------------------"RESET);

    int car_index;
    printf ("Enter the serial number of the car you want to book: ");
    scanf ("%d", &car_index);
    getchar(); // clearing the buffer

    printf (GREEN"Car booked.\n"
        "=> Price: %d, Car: %s ( %d ), \n"RESET
        , car[car_index - 1].price, car[car_index - 1].name, car[car_index-1].modal);

    puts (YELLOW"Press Enter to Proceed to generate ticket."RESET);
    getchar();
}


Car_Rental* find_cars(const char *location, unsigned int *car_rentals_count) {
    FILE *file = fopen("cars.dat", "rb"); // opening the file
    
    if (file == NULL) { // checking for file opening
        perror("Error opening file");
        exit(6); // terminating the program after prompting
    }

    Car_Rental *car_rentals = NULL; // a pointer to store car_rental values and return it
    
    // Read each car_rental entry from the file
    Car_Rental car_rental;
    
    while (!feof(file)) { // checking for end of file

        size_t result = fread(&car_rental, sizeof(Car_Rental), 1, file); // reading the file 

        // ! NOW WE NEED TO CHECK WHETHER THE CAR RENTAL WE READ IS THE ONE WE NEED OR NOT...
        if (result != 0 && car_rental.id != 0) { // checking for valid car_rental 

            if (strcmp(location, car_rental.city_name) == 0) { // comparing the location name with car_rental's city name
                (*car_rentals_count)++; // increase total car_rental count
                car_rentals = (Car_Rental *) realloc(car_rentals, (*car_rentals_count) * sizeof(Car_Rental)); // reallocating memory to our car_rentals pointer
                car_rentals[(*car_rentals_count) - 1] = car_rental; // adding to our pointer ( Array )
            }

        }
    }

    fclose(file); // closing the file

    if ((*car_rentals_count) == 0) { // if the total car_rental count is 0
        printf("No car rentals found in %s\n", location);
        return NULL;
    }

    return car_rentals; // returning the car_rentals pointer
}





void car_read_client(const char *location) {

    clearScreen();

    unsigned int car_count = 0;
    Car_Rental *cars = find_cars(location, &car_count);

    // Handle the case where no cars are found
    if (cars == NULL) {
        return;
    }

    // Print header for the entire car_rental information
    printf("\n\n");
    // Loop through each car_rental
    for (int i = 0; i < car_count; i++) {
        // Check if the car_rental is valid (ID not equal to 0)
        if (cars[i].id != 0) {
            // Print header for each car_rental entry
            printf(BLUE"------------------------------------------------------------------------\n");
            printf(YELLOW"=> %d.\t"GREEN"car_rental_name: %s, location: %s, \n",
                    i + 1, cars[i].company_name, cars[i].city_name);

            // Print SUVs information if available
            if (0 != cars[i].n_suv) {
                printf(BLUE"------------- SUVs -------------\n");
                // Loop through each SUV
                for (int j = 0; j < cars[i].n_suv; j++) {
                    // Print details of each SUV
                    printf(YELLOW"model: %5d| modal name: %10s| price: %6d\n"RESET, 
                            cars[i].suv[j].modal, cars[i].suv[j].name, cars[i].suv[j].price);
                }
            }

            // Print non-SUVs information if available
            if (0 != cars[i].n_non_suv) {
                printf(BLUE"---------- non-SUVs ----------\n");
                // Loop through each non-SUV
                for (int j = 0; j < cars[i].n_non_suv; j++) {
                    // Print details of each non-SUV
                    printf(YELLOW"model: %5d| modal name: %-10s| price: %6d\n"RESET, 
                            cars[i].non_suv[j].modal, cars[i].non_suv[j].name, cars[i].non_suv[j].price);
                }
            }

            // Print premium cars information if available
            if (0 != cars[i].n_premium) {
                printf(BLUE"----------  PREMIUMs ----------\n");
                // Loop through each premium car
                for (int j = 0; j < cars[i].n_premium; j++) {
                    // Print details of each premium car
                    printf(YELLOW"model: %5d| modal name: %-10s| price: %6d\n"RESET, 
                            cars[i].premium[j].modal, cars[i].premium[j].name, cars[i].premium[j].price);
                }
            }

            // Print footer for each car_rental entry
            printf(BLUE"------------------------------------------------------------------------\n"RESET);
        }


    }



    char choice;
        puts ("\nCan you choose among these:\n");
        printf ("%s%s",
            "1.\tSELECT.\n",
            "2.\tWant Recommendations.\n"
            "=> ");

        // WAS FACING SOME PREVIOUS BUFFER WHEN I RUN THIS PROGRAM SO CLEARING THE BUFFER HERE FOR NOW...
        getchar();
        scanf ("%c", &choice);
        getchar(); // clearing buffer


        // checking the choice...
        switch ( choice ) {
            case '1': {

                int select_car_index; // for getting the hotel user want

                do {
                    
                    printf ("Enter the serial number of the Car Rental: ");
                    scanf ("%d", &select_car_index); // reading the hotel user want
                    getchar(); // ! clearing the buffer

                    if (select_car_index < 0 || select_car_index > car_count) {
                        
                        puts (RED"INVALID CAR-RENTAL-SERIAL-NUMBER."RESET);
                        continue;
                    }
                    

                    display_selected_car_rental ( &cars[select_car_index - 1] );

                    if (confirm_prompt()){
                        clearScreen();

                        char client_car_choice;

                        do {
                            printf (GREEN"%s",
                                "Select car type: \n"
                                "1.\tSUV\n"
                                "2\tnon-SUV\n"
                                "3.\tPremium\n=> "RESET);
                                client_car_choice = getchar();
                                getchar(); // clearing the buffer

                            switch (client_car_choice){

                                case '1':
                                    display_cars( cars[select_car_index - 1].suv, cars[select_car_index - 1].n_suv );
                                    sleep(2);
                                    printf ("Generating ticket!\n");
                                    sleep(2);
                                    puts ("room booked!");
                                    break;  

                                case '2':
                                    display_cars( cars[select_car_index - 1].non_suv, cars[select_car_index - 1].n_non_suv );
                                    sleep(2);
                                    printf ("Generating ticket!\n");
                                    sleep(2);
                                    puts ("room booked!");
                                    break;

                                case '3':
                                    display_cars( cars[select_car_index - 1].premium, cars[select_car_index - 1].n_premium );
                                    printf ("Generating ticket!\n");
                                    sleep(2);
                                    puts ("Car booked!");
                                    break;

                                default:
                                    puts ("Wrong input.");
                                    break;
                            }
                        }while (client_car_choice < '0' || client_car_choice > '3');
                    }
                }while ( select_car_index < 0 || select_car_index > car_count );
                
                break;
            }


            default :
                puts ("INVALID!");
        }
    // Free the allocated memory for cars
    free(cars);
}
