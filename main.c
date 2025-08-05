#include <stdio.h>
#include <stdlib.h>
#include "doubly_linked_list.h"
#include "library_management.h"
#include "general.h"


int main() {
    u8 password[21];
    u32 choice;
    Library lib;

    initLibrary(&lib);
    setPassword(password);

    while (!verifyPassword(password)) {
        printf("Incorrect password. Do you want to try agian? Y/N \n");
        u8 tryAgain;
        scanf(" %c", &tryAgain);
        if (tryAgain == 'N' || tryAgain == 'n') {
            printf("Exiting program. Goodbye!\n");
            return 1;
        }
    }

    do {
        printf("\n===== Library Management System =====\n");
        printf("1. Add Book\n");
        printf("2. Delete Book\n");
        printf("3. View Books\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBookUI(&lib);
                break;
            case 2:
                deleteBookUI(&lib);
                break;
            case 3:
                viewBooksUI(&lib);
                break;
            case 4:
                freeLibrary(&lib);
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
