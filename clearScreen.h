#include <stdio.h>
#include <stdlib.h>

void clearScreen() {
#ifdef _WIN32
    system("cls");  // For Windows
#else
    system("clear"); // For Linux and macOS
#endif
}