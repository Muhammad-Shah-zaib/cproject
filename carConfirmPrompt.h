#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


bool confirm_prompt( void ){
    char confirm;

    do {
        puts ("Do you conifrm?[Y\\n]");
        confirm = getchar();
        getchar();
        
        switch ( confirm ) {
            case 'Y':
            case 'y':
            case '1':
                return true;
                break;

            case 'n':
            case 'N':
            case '0':
                return false;
                break;

            default:
            puts (RED"Invalid Key");
            break;
        }
    }while (1);

    return true;
    
}