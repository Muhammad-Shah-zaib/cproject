#include<stdio.h>
#include <stdlib.h>
#include <string.h>


Car_Rental generate_empty_car( void ) {
    Car_Rental emptyCar;

    // Initialize all fields to default values
    emptyCar.id = 0;
    strcpy(emptyCar.username, "");
    strcpy(emptyCar.company_name, "");
    strcpy(emptyCar.city_name, "");

    emptyCar.n_total_cars = 0;
    emptyCar.booked_cars = 0;
    emptyCar.available_cars = 0;

    // Initialize SUV details
    emptyCar.n_suv = 0;
    memset(emptyCar.suv, 0, sizeof(emptyCar.suv)); // this will filll partcular block of memory with 0

    // Initialize Non-SUV details
    emptyCar.n_non_suv = 0;
    memset(emptyCar.non_suv, 0, sizeof(emptyCar.non_suv)); // this will filll partcular block of memory with 0

    // Initialize Premium details
    emptyCar.n_premium = 0;
    memset(emptyCar.premium, 0, sizeof(emptyCar.premium)); // this will filll partcular block of memory with 0

    return emptyCar;
}
