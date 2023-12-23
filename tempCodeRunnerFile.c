#include <stdio.h>
#include <string.h>

#include "structHotel.h"
#include "structCarRental.h"




void hotel_search(int budget, int days, char location[]){

int b_per_day = budget/days, i=0;
char hotel_id[3];
char listed_hotels[100][4][10]= {""};
FILE *fptr;


if ((fptr = fopen("hotels.dat", "rb"))== NULL){
    puts("FILE NOT FOUND!");
    return; 

}
Hotel hotel = {0};

fseek(fptr, sizeof(Hotel), SEEK_SET);
fread(&hotel, sizeof(Hotel), 1, fptr);
while ( ((hotel.id != 0 ) && (strcmp(hotel.city_name, location) == 0)) &&
       ((b_per_day >= hotel.p_standard_room && hotel.n_standard_rooms>0)|| 
       (b_per_day >= hotel.p_delux_room && hotel.n_delux_rooms>0)|| 
       (b_per_day >= hotel.p_luxury_room && hotel.n_luxury_rooms>0 ))) {

    sprintf(hotel_id, "%d", hotel.id);  // converting the hotel id to string

    strcpy(listed_hotels[i][0],hotel_id);

    if (b_per_day >= hotel.p_standard_room) {
        // Add standard room type to the listed_hotels array
         strcpy(listed_hotels[i][1], "Standard");    
        }

    if (b_per_day >= hotel.p_delux_room) {
        // Add delux room type to the listed_hotels array
         strcpy(listed_hotels[i][2], "Delux");
    }

    if (b_per_day >= hotel.p_luxury_room) {
        // Add luxury room type to the listed_hotels array
         strcpy(listed_hotels[i][3], "Luxury");
    }
    fread(&hotel, sizeof(Hotel), 1, fptr);
    
    i++;
}
fclose(fptr);
for (int k =0; k<i; k++){
    for (int j=0; j<4; j++){
        if (strcmp(listed_hotels[k][j], "") != 0)                
            printf("%s ", listed_hotels[k][j]);
    }
puts("");
}
}

// void display_hotel_search(char hotel_list[][][]){
    
// }
int main(){
    char name [15]= "skardu";
 hotel_search(50000, 5,name);   

    return 0;
}