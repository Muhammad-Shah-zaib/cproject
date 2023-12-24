#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// #include "recommendationGetBudget.h"



void generate_ticket(const char *hotel_name,const char *room_tpye, unsigned int n_rooms, unsigned int p_per_room,  Car_Modal *car, const char *car_company_name, const char *car_type, const char *location) {

    char name[30], email[30];
    char contact [15] ;

    printf("Please Enter Your Name: ");
    // clear_input_buffer();
    while (getchar()!='\n');
    scanf("%29[^\n]", name);
    printf("Please Enter Your Phone Number: ");
    while (getchar()!='\n');
    scanf("%14[^\n]", contact);
    printf("Please Enter Your Email: ");
    while (getchar()!='\n');
    scanf("%29[^\n]", email);


    char filename[35];
    strcpy(filename, name);
    strcat(filename, "_receipt.csv");


    FILE *fptr;
    if ((fptr = fopen(filename, "w")) == NULL) {
        puts("FILE ERROR!");
        exit(7);
    }

    // Write header to the CSV file
    fprintf(fptr, "----Receipt for Booking----\n\n");
    fprintf(fptr, "Name: %s\n", name);
    fprintf(fptr, "Phone: %s\n", contact);
    fprintf(fptr, "Email: %s\n", email);
    fprintf(fptr, "\n----Booking Details----\n");
    fprintf(fptr, "Location: %s\n", location);


    
    if ( 0 != strcmp (hotel_name, "") ){
        fprintf(fptr, "\nhotel name: %s\n", hotel_name);
        fprintf(fptr, "Room Type: %s\n", room_tpye);
        fprintf(fptr, "Number of Rooms: %d\n", n_rooms);
    }

    if ( NULL != car ) {
        fprintf(fptr, "\nCar Rental Company name: %s\n", car_company_name);
        fprintf (fptr, "Car type: %s\n", car_type);
        fprintf(fptr, "Car Model-name: %s\n", car->name);
        fprintf(fptr, "Car Model: %d\n", car->modal);
        fprintf(fptr, "Car price: %d\n", car->price);
    }
    int total_cost;
    if (NULL != car)
        total_cost = p_per_room + car->price;
    else 
        total_cost = p_per_room ;

    fprintf(fptr, "\nTotal Cost: %d\n", total_cost);
    // fprintf(fptr, "Number of Days: %d\n", days/);

    fclose(fptr);

}




