#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "structHotel.h"
#include "structCarRental.h"

#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"
#define CYAN "\033[1;36m"
#define RESET "\033[1;0m"

void display_hotel_search(char hotel_list[100][4][10])
{
    int hotel_id;
    FILE *fptr;
    if ((fptr = fopen("hotels.dat", "rb")) == NULL)
    {
        puts("FILE NOT FOUND");
        return;
    }
    Hotel hotel = {0};
    fread(&hotel, sizeof(Hotel), 1, fptr);

    printf("%-30s%-20s%s\n", CYAN "Hotel Name" RESET, CYAN "\t\tRoom Type" RESET, CYAN "\tRoom Price" RESET);

    while (!feof(fptr))
    {
        for (int i = 0; i < 100; i++)
        {
            for (int j = 1; j < 4; j++)
            {
                if (strcmp(hotel_list[i][0], "") != 0)
                {
                    hotel_id = atoi(hotel_list[i][0]);
                    if (hotel_id == hotel.id && strcmp(hotel_list[i][j], "") != 0)
                    {
                        printf("%-30s", hotel.hotel_name);

                        if (strcmp(hotel_list[i][j], "Standard") == 0)
                            printf("%s%-20s%d%s\n", BLUE, "Standard Room", hotel.p_standard_room, RESET);

                        if (strcmp(hotel_list[i][j], "Delux") == 0)
                            printf("%s%-20s%d%s\n", GREEN, "Delux Room", hotel.p_delux_room, RESET);

                        if (strcmp(hotel_list[i][j], "Luxury") == 0)
                            printf("%s%-20s%d%s\n", CYAN, "Luxury Room", hotel.p_luxury_room, RESET);
                    }
                }
            }
        }
        fread(&hotel, sizeof(Hotel), 1, fptr);
    }
    fclose(fptr);
}

void hotel_search(int budget, int days, char location[])
{

    int b_per_day = budget / days, i = 0;
    char hotel_id[3];
    char listed_hotels[100][4][10] = {""};
    FILE *fptr;

    if ((fptr = fopen("hotels.dat", "rb")) == NULL)
    {
        puts("FILE NOT FOUND!");
        return;
    }
    Hotel hotel = {0};

    fseek(fptr, 0, SEEK_SET);
    while ((fread(&hotel, sizeof(Hotel), 1, fptr)) == 1)
    {
        if (
            (strcmp(hotel.city_name, location) == 0) &&
            ((b_per_day >= hotel.p_standard_room && hotel.n_standard_rooms > 0) ||
             (b_per_day >= hotel.p_delux_room && hotel.n_delux_rooms > 0) ||
             (b_per_day >= hotel.p_luxury_room && hotel.n_luxury_rooms > 0)))
        {
            sprintf(hotel_id, "%d", hotel.id); // converting the hotel id to string

            strcpy(listed_hotels[i][0], hotel_id);

            if (b_per_day >= hotel.p_standard_room)
            {
                // Add standard room type to the listed_hotels array
                strcpy(listed_hotels[i][1], "Standard");
            }

            if (b_per_day >= hotel.p_delux_room)
            {
                // Add delux room type to the listed_hotels array
                strcpy(listed_hotels[i][2], "Delux");
            }

            if (b_per_day >= hotel.p_luxury_room)
            {
                // Add luxury room type to the listed_hotels array
                strcpy(listed_hotels[i][3], "Luxury");
            }
            i++;
        }
    }
    fclose(fptr);

    display_hotel_search(listed_hotels);
}

int main()
{
    char name[15] = "skardu";
    hotel_search(50000, 5, name);

    return 0;
}