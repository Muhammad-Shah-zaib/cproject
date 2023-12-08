#include <stdio.h>

#define MAX_HOTELS 100

int id = 0;

typedef struct {

    unsigned int id; // b\w 1-100
    char username[30];
    char hotel_name[30];
    // total roams
    unsigned int n_total_rooms;
    // TYPE: STANDARD
    unsigned int n_standard_rooms;
    unsigned int p_standard_room;
    // TYPE: DELUX
    unsigned int n_delux_rooms;
    unsigned int p_delux_room;
    // TYPE: LUXURY
    unsigned int n_luxury_rooms;
    unsigned int p_luxury_room;

    // Booked Roams
    unsigned int booked_rooms;
    // Available Roams
    unsigned int available_roams;
} Hotel;