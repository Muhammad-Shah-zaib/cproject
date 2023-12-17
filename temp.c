#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structCarRental.h"
// #include "emptyCarGenerator.h"
#include "clearScreen.h"

// Define color codes
#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"
#define RESET "\x1b[0m"
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
    unsigned int n_car, price_per_car; // n_car=> for number of cars to be added 

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
    printf ("username: %s\n", car.username);
    printf ("id: %u\n", car.id);
    fclose (fptr);

    do {
        // clearScreen();
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







void car_details( const Car_Rental *car ) {
    

    printf(BLUE "Car Rental Details:\n" RESET);
    printf("ID: %u\n", car->id);
    printf("Username: %s\n", car->username);
    printf("Company Name: %s\n", car->company_name);
    printf("City Name: %s\n", car->city_name);
    printf("Total Cars: %u\n", car->n_total_cars);
    printf("Booked Cars: %u\n", car->booked_cars);
    printf("Available Cars: %u\n", car->available_cars);

    // Display SUV details
    printf("\n" GREEN "SUV Cars:\n" RESET);
    for (unsigned int i = 0; i < (car->n_suv); ++i) {
        printf("Modal: %u, Price: %u, Name: %s\n", car->suv[i].modal, car->suv[i].price, car->suv[i].name);
    }

    // Display Non-SUV details
    printf("\n" YELLOW "Non-SUV Cars:\n" RESET);
    for (unsigned int i = 0; i < (car->n_non_suv); ++i) {
        printf("Modal: %u, Price: %u, Name: %s\n", car->non_suv[i].modal, car->non_suv[i].price, car->non_suv[i].name);
    }

    // Display Premium details
    printf("\n" RED "Premium Cars:\n" RESET);
    for (unsigned int i = 0; i < (car->n_premium); ++i) {
        printf("Modal: %u, Price: %u, Name: %s\n", car->premium[i].modal, car->premium[i].price, car->premium[i].name);
    }
}


int suv_find_car_modal_index(const Car_Rental *car, const unsigned int id, const char *modal_name, const unsigned int modal) {
    for (unsigned int i = 0; i < car->n_suv; ++i) {
        if ( car->suv[i].modal == modal && (strcmp((car->suv[i].name), modal_name) == 0) ) {
            return i;
        }
    }

    printf("Car with modal number (%u : %s) not found.\n", modal, car->suv->name );
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
            car->suv[i] = car->suv [i+1];
    }
    car->n_suv--; // updating suv cars
    car->n_total_cars--; // updating total cars
    car->available_cars--; // updating available cars

    for (int i = 0; i < car->n_suv; i++) {
        printf ("%d: %s\n", (car->suv[i].modal), car->suv[i].name );
    }
    rewind(cfptr);
    fseek ( cfptr, (id-1) * sizeof (Car_Rental), SEEK_SET );
    fwrite( car, sizeof(Car_Rental), 1, cfptr );
    fflush(cfptr);
    fclose(cfptr);
}

void delete_suv(Car_Rental *car, const unsigned int id){

    // decaliring the variables
    unsigned int modal;
    char modal_name[30];

    // reading mdoal
    printf ("Enter modal");
    scanf ("%d", &modal);
    // reading modal name
    printf ("Enter modal name: ");
    scanf ("%s", modal_name);


    // dont need to read the data as it is already passed in the function
    const unsigned short int indexToDelete = suv_find_car_modal_index(car, id, modal_name, modal); 

    // checking for valid indexToDelete
    if ( -1 == indexToDelete ) {
        puts ("Car not found.");
        exit (0);
    }else
        // deleting the suv car only if the indexToDelete is valid
        suv_delete_car_modal (car, indexToDelete, id);

    exit (0);
}





int non_suv_find_car_modal_index(const Car_Rental *car, const unsigned int id, const char *modal_name, const unsigned int modal) {

    // getting the index
    for ( unsigned int i = 0; i < car->n_non_suv; i++ ) {
        if ( car->non_suv[i].modal == modal && (strcmp((car->non_suv[i].name), modal_name) == 0) ) {
            return i;
        }
    }

    // promppting and returning -1 if index not ofund
    printf("Car with modal number (%u : %s) not found.\n", modal, modal_name );
    return -1;
}


void non_suv_delete_car_modal (Car_Rental *car, const unsigned int index, const unsigned int id){

    // making a file pointer for "cars.dat"
    FILE *cfptr;

    // checking the file openeing
    if ( (cfptr = fopen ("cars.dat", "rb+")) == NULL ){
        puts ("The file can not be opened.");
        exit (1);
    }

    // deleting the given car
    for  ( unsigned int i = index ; i < car->n_non_suv; i++ ){
            car->non_suv[i] = car->suv[i+1]; // just reducing all the further index after indexToDelete
    }
    car->n_non_suv--; // updating the total non_suv_cars
    car->n_total_cars--; // updating the total cars
    car->available_cars--; // updating the available cars

    // printing the updated list of cars
    for (int i = 0; i < car->n_non_suv; i++) {
        printf ("%d: %s\n", (car->non_suv[i].modal), car->suv[i].name );
    }

    // ! GOING TO UPDATE THE FILE 
    rewind(cfptr); // just rewindin the pointer to the start, for surrety
    
    fseek ( cfptr, (id-1) * sizeof (Car_Rental), SEEK_SET );// off setting the poitner
    fwrite( car, sizeof(Car_Rental), 1, cfptr ); // updating the files ( in buffer )
    fflush(cfptr); // flushing the content into file for surety

    fclose (cfptr); // closing the file
}




void delete_non_suv( Car_Rental *car, const unsigned int id){

    // decaliring the variables
    unsigned int modal;
    char modal_name[30];

    // reading mdoal
    printf ("Enter modal");
    scanf ("%d", &modal);
    // reading modal name
    printf ("Enter modal name: ");
    scanf ("%s", modal_name);

    // dont need to read the data as it is already passed in the function
    const short int indexToDelete = non_suv_find_car_modal_index(car, id, modal_name, modal); 
    printf ("This is your car index %u\n\n", indexToDelete);

    if ( -1 == indexToDelete ) {
        puts ("Car not found.");
        exit (0);
    }

    non_suv_delete_car_modal ( car, indexToDelete, id );

    exit (0);
}



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

    // checking the file openeing
    if ( (cfptr = fopen ("cars.dat", "rb+")) == NULL ){
        puts ("The file can not be opened.");
        exit (1);
    }

    // deleting the given car
    for  ( unsigned int i = index ; i < car->n_non_suv; i++ ){
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
}




void delete_premium( Car_Rental *car, const unsigned int id){

    // decaliring the variables
    unsigned int modal;
    char modal_name[30];

    // reading mdoal
    printf ("Enter modal");
    scanf ("%d", &modal);
    // reading modal name
    printf ("Enter modal name: ");
    scanf ("%s", modal_name);

    // dont need to read the data as it is already passed in the function
    const short int indexToDelete = premium_find_car_modal_index(car, id, modal_name, modal); 
    printf ("This is your car index %u\n\n", indexToDelete);

    if ( -1 == indexToDelete ) {
        puts ("Car not found.");
        exit (0);
    }

    premium_delete_car_modal ( car, indexToDelete, id );

    exit (0);
}



void delete_car ( unsigned int id ){
    // creating a file pointe rto open cars.dat
    FILE *cfptr;

    // chekcing for file opening
    if ( (cfptr = fopen ("cars.dat", "rb")) == NULL ){
        puts ("File can not be opened.");
        exit (1); // termimnating the program with 1
    }

    // making ampty car to stor data
    Car_Rental car = generate_empty_car();

    // offsetting and reading the data
    fseek (cfptr, (id-1) * sizeof (Car_Rental), SEEK_SET);
    fread (&car, sizeof (Car_Rental), 1, cfptr);

    fclose (cfptr); // closing the pointer 

    char choice; // for car type to delete 
    printf ("%s: %u\n", car.username, car.id);
    do{

        // prompt the user
        printf("Please Select the Car Type (to Delete):\n"
                "0.\tExit\n"
                "1.\tDelete SUV\n"
                "2.\tDelete non-SUV\n"
                "3.\tDelete premium\n");
        choice = getchar (); // reading the choice
        choice = getchar (); // reading the choice

        switch (choice)
        {
        case '1':
            delete_suv( &car, car.id );
            break;

        case '2':
            delete_non_suv( &car, id);
            break;
        case'3':
            delete_premium( &car, id);
            break;
        default:
            break;
        }
    }while(1);

}

int main (){

    Car_Rental empty_car = generate_empty_car();

    car_details ( &empty_car );
    add_car( 7 );
    delete_car ( 7 );

    return 0;

}