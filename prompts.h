#include <stdio.h>

// Define color codes
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"
#define CYAN "\033[1;36m"
#define RESET "\033[1;0m"


int starting_prompt(){
    clearScreen();
    int choice;
    puts ("\tWelcome");

    while(1){
        printf("%s\n%s\n%s\n%s\n%s\n"GREEN"=> "RESET,"Please Select:",
                "1.\tRegistration",
                "2.\tLogin",
                "3.\tClinet",
                "\n\t0 to Exit");

        // checking for integer input
        if ( scanf("%d",&choice) != 1 ) {
            while ( '\n' != getchar() ); // ! clearing the input buffer
            clearScreen();
            puts (RED"Wrong input."RESET);
            continue;
        }
        while ( '\n' != getchar() ); // ! clearing the input buffer

        // checking for right int iput
        if ( (choice < 0 || choice > 3) ){
            clearScreen();
            puts (RED"Wrong input."RESET);
            continue;
        }


        break;

        
    }
    if (choice == 0) return 0;
    return choice;
}


void post_login( unsigned int id ) {

    clearScreen();

    int choice; // will store the user choice in this var
    // prompting user
    do {
        clearScreen();
        printf("%s"GREEN"=> "RESET,
            "\nPLease select...\n"
            "1.\tAdd Rooms\n"
            "2.\tChange or Delete Rooms\n"
            "3.\tView Room Details\n"
            " *or enter zero to exit*\n\n"
            );



        scanf("%d", &choice); // reading choice
        getchar();
        
        switch (choice)
            {
            case 1:
                add_room( id );
                break;
            case 2:
                delete_room( id );
                break;
            case 3:
                room_details( id );
                break;
            case 0:
                return;
                
            default:
                puts("Wrong Input!");
                break;
            }
    }while ( choice != 0 );
}