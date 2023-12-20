$include <stdio.h>


void client_initial_prompt()
{
    
    char choice = -1, location[30];
    puts("\n\tWelcome"); // WELCOME PROMPT
    do
    {
        printf("Please enter your destination:\n");
        scanf("%29[^\n]", location); // ! Taking location as input with spaces allowed
        while (getchar() != '\n')
            ;
        if (!(check_name(location))) // Matching different variations of spellings of the location
        {
            clear_screen(); // clearing screen 
            puts("\tInvalid Location");
            continue; // iterating again for correct input
        }
        while (choice < 0 || choice > 3)
        {
            printf("What are you looking for:\n" 
                   "1.\tHotel Bookings\n"
                   "2.\tCar Rental\n"
                   "3.\tBoth\n\n"
                   "4.\tPackages\n"
                   "\t0 to Exit\n");
            if (scanf("%d", &choice) != 1) // checking for valid int input
            {
                clear_screen();
                puts("\tWrong Input");
                while (getchar() != '\n'); // clearing input buffer

                continue;
            }
        }
            switch(choice){
                case 1: hotel_read_client(location);
                    break;
                case 2: car_read_client(location);
                    break;
                case 3: hotel_read_client(location);
                        car_read_client(location);
                    break;
                // case 4: display_package_client();
                    // break;                    
                case 0: exit(1); // ! EXIT POINT 1
                    break;
            }

        while (getchar() != '\n'); // clearing input buffer

        choice = -1; 
    } while (choice != 0); // ! condition for the while loop (0 to exit)
