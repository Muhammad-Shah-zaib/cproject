#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "car_delete.h"

// Define color codes
#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"
#define CYAN "\x1b[36m"
#define RESET "\x1b[0m"










// Function to add an SUV to the car rental
void add_suv(Car_Rental *car, unsigned int id) {

    FILE *cfptr;

    if ( (cfptr  = fopen ("cars.dat", "rb+")) == NULL ){
        puts ("File can not be opened.");
        return;
    }



    unsigned int n_modal;
    printf(BLUE "Total SUV cars: %d\n\n" RESET, (car->n_suv));

    // Reading SUV details
    printf("Enter the number of SUVs to add:\n");
    scanf("%u", &n_modal);

    // Check if there is enough space to add SUVs
    if ((car->n_suv) + n_modal > 50) {
        printf("\033[1;31mError: Not enough space to add SUVs.\033[0m\n");
        return;
    }

    // Adding SUVs
    for (unsigned int i = (car->n_suv); i < (car->n_suv) + n_modal; ++i) {
        printf("Enter details for SUV %u:\n", i + 1);
        printf("Modal Number: ");
        scanf("%u", &car->suv[i].modal);

        printf("Price: ");
        scanf("%u", &car->suv[i].price);

        printf("Name: ");
        scanf("%s", car->suv[i].name);
    }

    // Update the total number of SUVs
    (car->n_suv) += n_modal;
    car->n_total_cars += n_modal;
    car->available_cars += n_modal;

    puts("\n\033[1;34mSUVs added successfully\033[0m");
    printf("\033[1;32m=> Total SUVs: %u\n\n\033[0m", (car->n_suv));

    
    fseek (cfptr, (id - 1) * sizeof (Car_Rental), SEEK_SET);
    fwrite (car, sizeof (Car_Rental), 1, cfptr);
    fflush (cfptr);


    puts("Press enter to continue.");
    getchar(); // Ignore the enter
    getchar();
}







// Function to add a Non-SUV to the car rental
void add_non_suv(Car_Rental *car, unsigned int id) {

    FILE *cfptr;

    if ( (cfptr  = fopen ("cars.dat", "rb+")) == NULL ){
        puts ("File can not be opened.");
        return;
    }


    unsigned int n_modal;
    printf(BLUE "Total Non-SUV cars: %d\n\n" RESET, (car->n_non_suv));

    // Reading Non-SUV details
    printf("Enter the number of Non-SUVs to add:\n");
    scanf("%u", &n_modal);

    // Check if there is enough space to add Non-SUVs
    if ((car->n_non_suv) + n_modal > 50) {
        printf("\033[1;31mError: Not enough space to add Non-SUVs.\033[0m\n");
        return;
    }

    // Adding Non-SUVs
    for (unsigned int i = (car->n_non_suv); i < (car->n_non_suv) + n_modal; ++i) {
        printf("Enter details for Non-SUV %u:\n", i + 1);
        printf("Modal Number: ");
        scanf("%u", &car->non_suv[i].modal);

        printf("Price: ");
        scanf("%u", &car->non_suv[i].price);

        printf("Name: ");
        scanf("%s", car->non_suv[i].name);
    }

    // Update the total number of Non-SUVs
    (car->n_non_suv) += n_modal;
    car->n_total_cars += n_modal;
    car->available_cars += n_modal;

    puts("\n\033[1;34mNon-SUVs added successfully\033[0m");
    printf("\033[1;32m=> Total Non-SUVs: %u\n\n\033[0m", (car->n_non_suv));


    fseek (cfptr, (id - 1) * sizeof (Car_Rental), SEEK_SET);
    fwrite (car, sizeof (Car_Rental), 1, cfptr);
    fflush (cfptr);


    puts("Press enter to continue.");
    getchar(); // Ignore the enter
    getchar();
}





// Function to add a Premium car to the car rental
void add_premium(Car_Rental *car, unsigned int id) {

    FILE *cfptr;

    if ( (cfptr  = fopen ("cars.dat", "rb+")) == NULL ){
        puts ("File can not be opened.");
        return;
    }


    unsigned int n_modal;
    printf ("username: %s\n", car->username);
    printf ("id: %u\n", car->id);
    printf(BLUE "Total Premium cars: %d\n\n" RESET, (car->n_premium));

    // Reading Premium details
    printf("Enter the number of Premium cars to add:\n");
    scanf("%u", &n_modal);

    // Check if there is enough space to add Premium cars
    if ((car->n_premium) + n_modal > 50) {
        printf("\033[1;31mError: Not enough space to add Premium cars.\033[0m\n");
        return;
    }

    // Adding Premium cars
    for (unsigned int i = (car->n_premium); i < (car->n_premium) + n_modal; ++i) {
        printf("Enter details for Premium car %u:\n", i + 1);
        printf("Modal Number: ");
        scanf("%u", &car->premium[i].modal);

        printf("Price: ");
        scanf("%u", &car->premium[i].price);

        printf("Name: ");
        scanf("%s", car->premium[i].name);
    }

    // Update the total number of Premium cars
    (car->n_premium) += n_modal;
    car->n_total_cars += n_modal;
    car->available_cars += n_modal;

    puts("\n\033[1;34mPremium cars added successfully\033[0m");
    printf("\033[1;32m=> Total Premium cars: %u\n\n\033[0m", (car->n_premium));

    fseek (cfptr, (id - 1) * sizeof (Car_Rental), SEEK_SET);
    fwrite (car, sizeof (Car_Rental), 1, cfptr);
    fflush (cfptr);


    puts("Press enter to continue.");
    getchar(); // Ignore the enter
    getchar();
}






void add_car (unsigned int id){
    clearScreen();

    char choice; // selecting for car type to be added

    // making a file pointer to open cars.dat
    FILE *fptr;
    if ((fptr = fopen("cars.dat", "rb+")) == NULL) {
        puts("File Not Found!");
        return;
    }

    Car_Rental car = generate_empty_car();

    // offsetting the file pointer
    fseek(fptr, (id - 1) * sizeof(Car_Rental), SEEK_SET);
    fread(&car, sizeof(Car_Rental), 1, fptr); // reading
    fclose(fptr);

    do {
        clearScreen();
        printf("Please Select the Room Type (to add):\n"
                "0.\tExit\n"
                "1.\tAdd SUV\n"
                "2.\tAdd non-SUV\n"
                "3.\tAdd premium\n");

        choice  = getchar();

        if (choice == '0')
            return;

        // checking whether the choice provided by the user is valid or not
        if ((choice < '0') || (choice > '3')) 
            continue;
        

        switch (choice) {
            case '1': // FOR STANDARD ROOMS
                add_suv( &car, id );
                break;

            case '2': // FOR DELUX ROOMS
                add_non_suv( &car, id );
                break;
            case '3': // FOR LUXURY ROOMS

                add_premium ( &car, id );
                break;

            default:
                break;
        }
    } while (choice != '0');
    
}





















void car_details(int id) {
    clearScreen(); // Assuming you have a function to clear the screen

    FILE *fptr;

    if ((fptr = fopen("cars.dat", "rb+")) == NULL) {
        puts("File cannot be opened.");
        puts ("Press Enter to exit.");
        getchar();
        getchar();

        return;
    }

    Car_Rental carRental = generate_empty_car();

    fseek(fptr, (id - 1) * sizeof(Car_Rental), SEEK_SET);
    fread(&carRental, sizeof(Car_Rental), 1, fptr);

    printf(BLUE"\n+------------------------------+\n"RESET);
    printf(BLUE"|      Car Rental Details      |\n"RESET);
    printf(BLUE"+------------------------------+\n"RESET);
    printf("\n\033[1;32mTotal Cars: %u\n", carRental.n_total_cars);
    printf("Available Cars: %u\n", carRental.available_cars);
    printf("Booked Cars: %u\n", carRental.booked_cars);
    printf(BLUE"------------------------------\n");
    printf(BLUE"            SUV Cars           \n"RESET);
    printf(BLUE"------------------------------\n"RESET);
    printf(CYAN"Available Cars: %u\n\n", carRental.n_suv);
    for (unsigned int i = 0; i < carRental.n_suv; ++i) {
        printf(GREEN"=>%d.\tModel: %u, Price: %u, Name: %s\n"RESET, i+1, carRental.suv[i].modal, carRental.suv[i].price, carRental.suv[i].name);
    }
    printf(BLUE"------------------------------\n"RESET);
    printf(BLUE"         Non-SUV Cars          \n"RESET);
    printf(BLUE"------------------------------\n"RESET);
    printf(CYAN"Available Cars: %u\n\n", carRental.n_non_suv);
    for (unsigned int i = 0; i < carRental.n_non_suv; ++i) {
        printf(GREEN"=>%d.\tModel: %u, Price: %u, Name: %s\n"RESET, i+1, carRental.non_suv[i].modal, carRental.non_suv[i].price, carRental.non_suv[i].name);
    }
    printf(BLUE"------------------------------\n"RESET);
    printf(BLUE"         Premium Cars          \n"RESET);
    printf(BLUE"------------------------------\n"RESET);
    printf(CYAN"Available Cars: %u\n\n"RESET, carRental.n_premium);
    for (unsigned int i = 0; i < carRental.n_premium; ++i) {
        printf(GREEN"=>%d.\tModel: %u, Price: %u, Name: %s\n"RESET, i+1, carRental.premium[i].modal, carRental.premium[i].price, carRental.premium[i].name);
    }

    getchar(); // ignoring enter

    printf(YELLOW"\n\n Press enter to continue.\n"RESET);
    getchar();
    fclose(fptr);
}



void car_post_login ( unsigned int id ){
    char choice;

    do {
        clearScreen();
        printf("\n1.\tAdd cars\n"
            "2.\tChange or Delete cars\n"
            "3.\tView car Details\n"
            "\t *or enter zero '0' to exit*\n\n"
            "Please Select: ");

        choice = getchar();

        switch (choice)
            {
            case '1': // *ADD_CAR 
                add_car( id );
                break;
            case '2': // *DELETE_cAR 
                delete_car( id );
                break;
            case '3': // *CAR DETIALS
                car_details( id );
                break;

            case '0': // returning if '0' is encountered
                return;
                
            default: // ignoring the invalid inputs
                break;
            }


    } while (choice != '0');
    
}



