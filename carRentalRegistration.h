#include <stdio.h>
#include <stdlib.h>

// Define color codes
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"
#define CYAN "\033[1;36m"
#define RESET "\033[1;0m"


int extract_car_id ( void ) {
    FILE *idfptr;

    if ( (idfptr = fopen ("carid.txt", "r")) == NULL) {
        puts ("File can not be opened");
        exit(EXIT_SUCCESS);
    }
    int id;
    fscanf (idfptr, "%d", &id);

    fclose (idfptr);
    // printf ("%d", id);
    return id;
}






// ! UPDATING OUR ID FILE


void update_car_id ( int id ) {
    FILE *idfptr;

    if ( (idfptr = fopen ("carid.txt", "w")) == NULL) {
        puts ("File can not be opened");
        exit(EXIT_SUCCESS);
    }

    fprintf (idfptr, "%d", id);

    fclose (idfptr);
}





void car_rental_registration ( void ){

    

    Car_Rental car = generate_empty_car();
    

    // Providing th eunique id
    unsigned short int id = extract_car_id ();

    car.id = id;
    ++id;

    update_car_id( id );

    while ( '\n' != getchar() );
    printf ("Enter your user name: ");
    scanf("%29[^\n]", car.username);
    while ('\n' != getchar());
    

    printf ("Enter your company name: ");
    scanf("%29[^\n]", car.company_name);
    while ('\n' != getchar());

    do {
        printf ("Enter your city name: ");
        scanf("%29[^\n]", car.city_name);
        if ( check_name(car.city_name) ) break;
        else {
            puts  ("We are not currently available here yet.");
            continue;
        }

    }while (1);
    while ('\n' != getchar());



    // ! UPADTING THE FILE HERE
    FILE *cfptr; // car file pointer

    if ( (cfptr = fopen("cars.dat", "rb+")) == NULL ) { // opening the file
        puts ("FIle can not be opened!");
        return;
    }

    // writing the changes
    fseek ( cfptr, (car.id - 1) * sizeof (Car_Rental), SEEK_SET );
    fwrite( &car, sizeof (Car_Rental), 1, cfptr );
    fflush (cfptr);

    fclose ( cfptr ); // closing file

    puts (BLUE"+--------------------------------------------------------------------+"RESET);
    printf (BLUE"|"CYAN"Remember your following credentials, you need them while logging in."BLUE"|\n"RESET);
    puts (BLUE"+--------------------------------------------------------------------+"RESET);

    printf (GREEN"=>id: %d\n"RESET, car.id);
    printf (GREEN"=>username: %s\n\n"RESET, car.username);
    press_enter_to_continue();
    clearScreen();

}

