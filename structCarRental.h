#include <stdio.h>

#define MAX_CAR_RENTAL 100


typedef struct  {
    unsigned int modal;
    unsigned int price;
    char name[30];
} Car_Modal;



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
    unsigned int n_suv;
    Car_Modal suv[50];
    

    //Non-SUV cars price and number 
    unsigned int n_non_suv;
    Car_Modal non_suv[50];

    //premium cars and their prices
    unsigned int n_premium;
    Car_Modal premium[50];
    
}Car_Rental;