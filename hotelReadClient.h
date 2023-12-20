#include <stdio.h>
#include <stdlib.h>
#include <string.h>




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

        if (result != 0 && hotel.id != 0){ // chekcing for valid hotel 

            if (strcmp (location, hotel.city_name) == 0) { // compairing the locaiton name with hotel's city name
                (*hotels_count)++; // increase total hotel count
                hotels = (Hotel *) realloc (hotels, (*hotels_count )* sizeof(Hotel)); // reallocating the momeory to our hotels pointer
                hotels[(*hotels_count)-1] = hotel; // adding to our pointer ( Array )
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

    unsigned int hotels_Count = 0; // to get total hotels at desired location

    // this fucntion will return a pointer of
    Hotel *hotels = find_hotels(location, &hotels_Count); // passing pointer to hotels_count to get it updated

    // printf ("hotels count: %d\n", hotels_Count);
    if (hotels != NULL) {
        // Process the retrieved hotels
        for (int i = 0; i < hotels_Count ; i++) {


            if (hotels[i].id != 0){ // just an extra check
                // pringting the hotels
                printf ("hotel_name: %s, location: %s\n", hotels[i].hotel_name, hotels[i].city_name);
            }


        }

        
        free(hotels); // freeing the allocaitng memory
    }

    return;
}
