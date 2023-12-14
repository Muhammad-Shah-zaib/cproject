#include <stdio.h>

#define MAX_CAR_RENTAL 100

typedef struct {
    // ID b/w 1-100
    unsigned int id;

    char username[30];
    char company_name[30];
    char city_name[25];

    // total number of cars in each company
    unsigned int n_total_cars;
    // Booked cars
    unsigned int booked_cars;
    // available cars
    unsigned int available_cars;  

    // SUV cars price and number
    unsigned int *n_suv;
    unsigned int *p_suv;
    unsigned int *suv_model;
    char *suv_model_name [20];

    //Non-SUV cars price and number 
    unsigned int *n_non_suv;
    unsigned int *p_non_suv;
    unsigned int *non_suv_model;
    char *non_suv_model_name[30];

    //premium cars and their prices
    unsigned int *n_premium;
    unsigned int *p_premium;
    unsigned int *premium_model;
    char *premium_model_name[30];
    
}Car_Rental;