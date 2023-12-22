#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define color codes
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"
#define CYAN "\033[1;36m"
#define RESET "\033[1;0m"


void display_selected_hotel ( Hotel selected_hotel ) {
    printf(BLUE"\n---------------------------------\n");
    printf("Hotel Details - Cost per Room\n");
    printf("---------------------------------\n");

    printf(GREEN"Hotel Name: %s\n", selected_hotel.hotel_name);
    printf("City: %s\n", selected_hotel.city_name);
    printf(BLUE"---------------------------------\n");
    printf("\nRoom Types and Prices:\n");

    // Display cost for STANDARD room
    printf(YELLOW"Standard Room: $%u per night\n", selected_hotel.p_standard_room);

    // Display cost for DELUXE room
    printf("Deluxe Room: $%u per night\n", selected_hotel.p_delux_room);

    // Display cost for LUXURY room
    printf("Luxury Room: $%u per night\n"RESET, selected_hotel.p_luxury_room);

    printf(BLUE"---------------------------------\n"RESET);
}

Hotel* find_hotels(const char *location, unsigned int *hotels_count) {
    FILE *file = fopen("hotels.dat", "rb"); // opening the file
    
    if (file == NULL) { // checking for file opening
        perror("Error opening file");
        exit (5); // terminating hte program after prompting
    }

    Hotel *hotels = NULL; // aking a pointer to get the values and return it
    

    // Read each hotel entry from the file
    Hotel hotel;
    
    while (!feof (file) ){ // checking for end of file

        size_t result = fread(&hotel, sizeof(Hotel), 1, file); // reading the file 


        // ! NOW WE NEED TO CHECK WHETHER THE HOTEL WE READ IS THE WE NEED OR NOT...
        if (result != 0 && hotel.id != 0){ // chekcing for valid hotel 

            if (strcmp (location, hotel.city_name) == 0) { // compairing the locaiton name with hotel's city name
                (*hotels_count)++; // increase total hotel count
                hotels = (Hotel *) realloc (hotels, (*hotels_count )* sizeof(Hotel)); // reallocating the momeory to our hotels pointer
                hotels[(*hotels_count) - 1] = hotel; // adding to our pointer ( Array )
            }

        }
    }
    

    fclose(file); // closing hte file

    if ((*hotels_count) == 0) { // if the total hotel count is 0
        printf("No hotels found in %s\n", location);
        return NULL;
    }

    return hotels; // returning the hotels pointer
}










void hotel_read_client( char *location ) {

    unsigned int hotels_Count = 0; // * to get total hotels at desired location

    // this fucntion will return a pointer of
    Hotel *hotels = find_hotels(location, &hotels_Count); // passing pointer to hotels_count to get it updated

    

    // ! PRINTING THE LIST OF HOTELS...
    if (hotels != NULL) {
        // Process the retrieved hotels
        for (int i = 0; i < hotels_Count ; i++) {


            if (hotels[i].id != 0){ // just an extra check
                // pringting the hotels
                printf ("%d.\thotel_name: %s, location: %s\n",
                i+1, hotels[i].hotel_name, hotels[i].city_name);
            }


        }

        // ! PROMPTING USER TO EITHER SELECT OR WANT RECOMENDATIONS
        char c;
        puts ("\nCan you decide among these: ");
        printf ("%s%s",
            "1.\t SELECT.\n",
            "2.\tWant Recommendations.\n=> ");

        // WAS FACING SOME PREVIOUS BUFFER WHEN I RUN THIS PROGRAM SO CLEARING THE BUFFER HERE FOR NOW...
        getchar(); // 
        scanf ("%c", &c);
        getchar(); // clearing buffer
        // printf ("\n (%c: %d)\n\n", c, sizeof (c ));

        // checking the c...
        switch ( c ) {
            case '1': {

                int select_hotel_index; // for getting the hotel user want

                do {
                    
                    printf ("Enter the serial number of the hotel: ");
                    scanf ("%d", &select_hotel_index); // reading the hotel user want
                    getchar(); // ! clearing the buffer

                    if (select_hotel_index < 0 || select_hotel_index > hotels_Count) {
                        
                        puts (RED"INVALID HOTEL SERIAL NUMBER."RESET);
                        continue;
                    }
                    

                    display_selected_hotel ( hotels[select_hotel_index - 1] );
                }while ( select_hotel_index < 0 || select_hotel_index > hotels_Count );
                
                break;
            }


            default :
                puts ("INVALID!");
        }        
        free(hotels); // freeing the allocaitng memory
    }

    return;
}
