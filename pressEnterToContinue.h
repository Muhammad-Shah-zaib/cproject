#include <stdio.h>


// Define color codes
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"
#define CYAN "\033[1;36m"
#define RESET "\033[1;0m"



void press_enter_to_continue ( void ){

    puts (YELLOW"Press Enter to continue"RESET);
    while ('\n' != getchar()); // ! taking ginput and claering the buffer
}