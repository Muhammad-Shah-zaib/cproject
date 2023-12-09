#include <stdio.h>

int starting_prompt(){
    int choice;
    puts ("\tWelcome");
    
        printf("%s","\nPlease Select: \n1.\tRegistration\n2.\tLogin\n3.\tClinet\n");
        scanf("%d",&choice);

        while ((choice<=0) || (choice >3)){
            puts("Invalid Input.");

            printf("%s","\nPlease Select: \n1.\tRegistration\n2.\tLogin\n3.\tClinet\n");
            scanf("%d",&choice);
        }

    // do{

    //     printf("%s","\nPlease Select: \n1.\tRegistration\n2.\tLogin\n3.\tClinet\n");
    //     scanf("%d",&choice);

    //     if () 
    //         printf("Invalid Input.\n");

    // }while ();
    return choice;
}



void post_login( void ) {


    int choice; // will store the user choice in this var
    // prompting user
    printf("Please Select:\n"
        "1.\tAdd Rooms\n"
        "2.\tChange or Delete Rooms\n"
        "3.\tView Room Details");


    scanf("%d", &choice); // reading choice

    switch (choice)
        {
        case 1:
            // add_room();
            break;
        case 2:
            // edit_room();
            break;
        case 3:
            // room_details();
            break;
        case 0:
            return;
            
        default:
            puts("Wrong Input!");
            break;
        }
}