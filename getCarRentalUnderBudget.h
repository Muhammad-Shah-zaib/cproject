#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

// #include "structCarRental.h"
// #include "ticketGenerator.h" 

#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"
#define CYAN "\033[1;36m"
#define RESET "\033[1;0m"






char *get_car_type ( char choice){

    char *car_type;

    switch ( choice ){
        case '1' :
            car_type = ( char * ) malloc ( 4 * sizeof (char) );
            strcpy ( car_type, "SUV" );

            break;

        case '2':
            car_type = ( char * ) malloc ( 6 * sizeof (char) );
            strcpy ( car_type, "Sedan" );
            break;

        case '3':
            car_type = ( char * ) malloc ( 8 * sizeof (char) );
            strcpy ( car_type, "Premium" );
            break;
    }

    return car_type;
}













bool car_add_budget (unsigned int *b_per_day, int *b_lowest_p, int *b_highest_p){
    char choice;
    do {
        // asking for adding 2500/- more or not
        printf (RED"%s"RESET, "Want to add RS-2500 more in your budget?\n=> ");
        choice = getchar();
        while ( '\n' != getchar() );// ! clearing buffer

        // cehcking his response
        switch ( choice ){
            // if his response is +ve
            case 'Y':
            case 'y':
            case '1':
                (*b_per_day) += 2500;
                (*b_lowest_p) = (*b_per_day) - ((*b_per_day) * .1) ;
                (*b_highest_p) = (*b_per_day) +  ((*b_per_day) * .1);
                puts (GREEN"\nAdding budget and searching...\n"RESET);
                sleep (2);
                return true;

            // id his response is -ve
            case 'N':
            case 'n':
            case '0':
                puts (GREEN"Thanks for using our service."RESET);
                sleep (1);
                return false;

            // handle other caases
            default:
                // clearScreen();
                break;

        }       
    } while ( 1 );

    return false;
    

}


Car_Modal get_least_expensive_car ( Car_Rental *cars, unsigned int cars_count, unsigned int b_per_day, const char car_type, char *car_company_name ) {

    // initializing a laest_expensive_car var
    Car_Modal least_expensive_car = {
        2023, // model
        9999999, // price
        "" // name
    };

    unsigned int b_offset = b_per_day * .1; 
    int b_lowest_point = b_per_day - b_offset, b_highest_point = b_per_day + b_offset; 



    // iterate over cars ( array of Car_Rental ) and then check car_type, as if it is '1' then compare all the suv of all the Car_Rentals in cars and compare with least_expensive and then reutrn it
    for (int i = 0 ; i < cars_count ; i++) {
        switch ( car_type ) {



            // since each suv, non_suv and premium... is itself an array so we need to iterate over that to get each exixting car
            case '1': {
                do {
                    for (int j = 0 ; j < cars[i].n_suv ; j++) {
                        
                        if ( cars[i].suv[j].price > b_lowest_point && cars[i].suv[j].price  < b_highest_point){

                            // check for lesat_expensive car 
                            if ( cars[i].suv[j].price < least_expensive_car.price ) {
                                least_expensive_car = cars[i].suv[j];
                                strcpy ( car_company_name, cars[i].company_name );
                            }
                            // check if the car prices are same then car with latest model will be shown
                            else if ( cars[i].suv[j].price == least_expensive_car.price && cars[i].suv[j].modal > least_expensive_car.modal){
                                least_expensive_car = cars[i].suv[j];
                                strcpy ( car_company_name, cars[i].company_name );
                            }
                        }

                    } // nested for loop ends


                    // checking if the car is found or not
                    if ( 0 == strcmp (least_expensive_car.name, "") ){
                        b_lowest_point -= b_offset;

                        // checking for requirement of more budget
                        if ( b_lowest_point < 0 ){
                            puts ("Not sufficent budget");

                            // adding budget if user wants
                            if ( ! car_add_budget (&b_per_day, &b_lowest_point, &b_highest_point) ){
                                return least_expensive_car; 
                            }

                        }
                        continue;
                    } // checking if the lesat_expensive car is found or not
                    break;


                } while ( 1 );

                break;
            } // case '1' ends



            case '2': {
                do {
                    for (int j = 0 ; j < cars[i].n_non_suv ; j++) {
                        
                        if ( cars[i].non_suv[j].price > b_lowest_point && cars[i].non_suv[j].price  < b_highest_point){

                            // check for lesat_expensive car 
                            if ( cars[i].non_suv[j].price < least_expensive_car.price ) {
                                least_expensive_car = cars[i].non_suv[j];
                                strcpy ( car_company_name, cars[i].company_name );
                            }
                            // check if the car prices are same then car with latest model will be shown
                            else if ( cars[i].non_suv[j].price == least_expensive_car.price && cars[i].non_suv[j].modal > least_expensive_car.modal){
                                least_expensive_car = cars[i].non_suv[j];
                                strcpy ( car_company_name, cars[i].company_name );
                            }
                        }

                    } // nested for loop ends


                    // checking if the car is found or not
                    if ( 0 == strcmp (least_expensive_car.name, "") ){
                        b_lowest_point -= b_offset;

                        // checking for requirement of more budget
                        if ( b_lowest_point < 0 ){
                            puts ("Not sufficent budget");

                            // adding budget if user wants
                            if ( ! car_add_budget (&b_per_day, &b_lowest_point, &b_highest_point) ){
                                return least_expensive_car; 
                            }

                        }
                        continue;
                    } // checking if the lesat_expensive car is found or not
                    break;


                } while ( 1 );

                break;
            } // case '2' ends



            // since each suv, non_suv and premium... is itself an array so we need to iterate over that to get each exixting car
            case '3': {
                do {
                    for (int j = 0 ; j < cars[i].n_premium ; j++) {
                        
                        if ( cars[i].premium[j].price > b_lowest_point && cars[i].premium[j].price  < b_highest_point){

                            // check for lesat_expensive car 
                            if ( cars[i].premium[j].price < least_expensive_car.price ) {
                                least_expensive_car = cars[i].premium[j];
                                strcpy ( car_company_name, cars[i].company_name );
                            }
                            // check if the car prices are same then car with latest model will be shown
                            else if ( cars[i].premium[j].price == least_expensive_car.price && cars[i].premium[j].modal > least_expensive_car.modal){
                                least_expensive_car = cars[i].premium[j];
                                strcpy ( car_company_name, cars[i].company_name );
                            }
                        }
                    } // nested for loop ends


                    // checking if the car is found or not
                    if ( 0 == strcmp (least_expensive_car.name, "") ){
                        b_lowest_point -= b_offset;

                        // checking for requirement of more budget
                        if ( b_lowest_point < 0 ){
                            puts ("Not sufficent budget");

                            // adding budget if user wants
                            if ( ! car_add_budget (&b_per_day, &b_lowest_point, &b_highest_point) ){
                                return least_expensive_car; 
                            }

                        }
                        continue;
                    } // checking if the lesat_expensive car is found or not
                    break;


                } while ( 1 );

                break;
            } // case '3' ends

        } // switch ends

    } // outer for loop ends


    
    return least_expensive_car;
}




// make a function of get_carRentals_under_budegt() that first find out the least expensive car under a given range and then dislpay them and ask for selection
void get_carRentals_under_budegt ( Car_Rental *cars, unsigned int cars_count, unsigned int b_per_day, const char *location) {

    // reading which type of car user wants
    char choice_car_type;
    do {
        printf ("\nSelect among the followings.\n"
            "1.\tSUV\n"
            "2.\tSedan\n"
            "3.\tLuxury\n");
        choice_car_type = getchar ();
        while ('\n' != getchar()); // ! clearing the buffer

        // prompting for wrong input
        if (choice_car_type < '0' && choice_car_type > '3') 
            puts (RED"Wrong Input."RESET);

    }while (choice_car_type < '0' && choice_car_type > '3');

    // now find the lesat expensive car of choice_car_type with the given range of budget
    char car_company_name[30];
    Car_Modal car = get_least_expensive_car ( cars, cars_count, b_per_day, choice_car_type, car_company_name );

    printf (GREEN"\nmodel name: %s\n=>model: %d\n=>price: %d\n"RESET, car.name, car.modal, car.price);

    // check for choice_car_type and gnerate ticekt


    char *car_type;

    car_type = get_car_type ( choice_car_type );

    if ( 0 == strcmp(car.name, "") )
        return;
    
    generate_ticket ("", '\0',0,0, &car ,car_company_name, car_type, location);

    free (car_type);
    exit (EXIT_SUCCESS);
    
}