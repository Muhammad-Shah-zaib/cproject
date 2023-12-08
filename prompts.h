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
