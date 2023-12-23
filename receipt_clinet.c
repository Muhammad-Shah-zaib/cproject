#include <stdio.h>
#include <string.h>

void ticket_client(char location[], char hotel_name[], char car_rental[], 
                   char r_type[], int n_rooms, int t_cost, int days) {
    char name[30], email[30];
    char contact [15] ;

    printf("Please Enter Your Name: ");
    scanf("%s", name);
    printf("Please Enter Your Phone Number: ");
    scanf("%s", contact);
    printf("Please Enter Your Email: ");
    scanf("%s", email);

    char filename[35];
    strcpy(filename, name);
    strcat(filename, "_receipt.csv");

    FILE *fptr;
    if ((fptr = fopen(filename, "w")) == NULL) {
        puts("FILE ERROR!");
        return;
    }

    // Write header to the CSV file
    fprintf(fptr, "Receipt for Booking\n\n");
    fprintf(fptr, "Name: %s\n", name);
    fprintf(fptr, "Phone: %s\n", contact);
    fprintf(fptr, "Email: %s\n", email);
    fprintf(fptr, "\nBooking Details\n");
    fprintf(fptr, "Location: %s\n", location);
    if (car_rental != "")
    fprintf(fptr, "Car Rental: %s\n", car_rental);
    if (hotel_name != ""){
    fprintf(fptr, "Hotel: %s\n", hotel_name);
    fprintf(fptr, "Room Type: %s\n", r_type);
    fprintf(fptr, "Number of Rooms: %d\n", n_rooms);
    }
    fprintf(fptr, "Total Cost: %d\n", t_cost);
    fprintf(fptr, "Number of Days: %d\n", days);

    fclose(fptr);
}

int main() {
    ticket_client("Skardu", "Mount Vista", "", "Standard", 2, 30000, 5);

    printf("Receipt generated successfully!\n");

    return 0;
}
