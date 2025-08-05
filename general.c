#include <stdio.h>
#include <string.h>
#include <conio.h> // For getch() on Windows
#include "general.h"

void setPassword(u8 *password) {
    printf("Set your password: ");
    u32 i = 0;
    u8 ch;

    while ((ch = _getch()) != '\r' && i < 20) { // '\r' = Enter key
        if (ch == 8 && i > 0) { // Backspace key
            i--;
            printf("\b \b");
        } else if (ch != 8) {
            password[i++] = ch;
            printf("*");
        }
    }
    password[i] = '\0';
    printf("\nPassword set successfully!\n");
}

u32 verifyPassword(const u8 *password) {
    u8 input[21];
    u32 i = 0;
    u8 ch;

    printf("Enter your password to continue: ");

    while ((ch = _getch()) != '\r' && i < 20) {
        if (ch == 8 && i > 0) {
            i--;
            printf("\b \b");
        } else if (ch != 8) {
            input[i++] = ch;
            printf("*");
        }
    }
    input[i] = '\0';

    printf("\n");
    return strcmp(password, input) == 0;
}


void sortBooksByName(Library *lib) {
    if (!lib->head || !lib->head->next) return;

    u32 swapped;
    Book *ptr;
    do {
        swapped = 0;
        ptr = lib->head;
        while (ptr->next) {
            if (strcmp(ptr->name, ptr->next->name) > 0) {
                // Swap all data fields
                u8 tempName[100], tempAuthor[100];
                u32 tempID;
                f32 tempPrice;

                strcpy(tempName, ptr->name);
                strcpy(ptr->name, ptr->next->name);
                strcpy(ptr->next->name, tempName);

                strcpy(tempAuthor, ptr->author);
                strcpy(ptr->author, ptr->next->author);
                strcpy(ptr->next->author, tempAuthor);

                tempID = ptr->id;
                ptr->id = ptr->next->id;
                ptr->next->id = tempID;

                tempPrice = ptr->price;
                ptr->price = ptr->next->price;
                ptr->next->price = tempPrice;

                swapped = 1;
            }
            ptr = ptr->next;
        }
    } while (swapped);
}