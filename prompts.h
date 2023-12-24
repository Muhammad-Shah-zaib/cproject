#include <stdio.h>




int starting_prompt(){
    int choice;
    puts ("\tWelcome");

        while(1){
        printf("%s\n%s\n%s\n%s\n%s\n","Please Select:",
                "1.\tRegistration",
                "2.\tLogin",
                "3.\tClinet",
                "\n\t0 to Exit");
        if (scanf("%d",&choice)==1)
        break;
        clearScreen();
        puts("Wrong Input Please Make a Valid Selection!");
        while(getchar()!='\n');
        }
        getchar(); // claring buffer

        while ((choice<0) || (choice >3)){
            puts("Invalid Input.");

            printf("%s\n%s\n%s\n%s\n%s","Please Select: ",
                    "1.\tRegistration",
                    "2.\tLogin",
                    "3.\tClinet",
                    "\n\t0 to Exit.");
            scanf("%d",&choice);
        }
    if (choice == 0) return 0;
    return choice;
}


void post_login( unsigned int id ) {

    // clearScreen();

    int choice; // will store the user choice in this var
    // prompting user
    do {
        clearScreen();
        printf("\n1.\tAdd Rooms\n"
            "2.\tChange or Delete Rooms\n"
            "3.\tView Room Details\n"
            " *or enter zero to exit*\n\n"
            "Please Select: ");



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