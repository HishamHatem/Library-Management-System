#include "library_management.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void addBookUI(Library *lib) {
    u8 name[100], author[100];
    u32 id;
    f32 price;
    u8 price_str[100]; // Buffer for price input
    u8 *endptr;
    
    printf("Enter book name: ");
    scanf(" %s", name);
    getchar(); // Consume newline
    
    printf("Enter author name: ");
    scanf(" %s", author);
    getchar(); // Consume newline
    
    // Price validation loop
    while (1) {
        printf("Enter book price: ");
        if (fgets(price_str, sizeof(price_str), stdin) == NULL) {
            printf("Error reading input. Try again.\n");
            continue;
        }
        
        // Remove trailing newline
        price_str[strcspn(price_str, "\n")] = '\0';
        
        // Try to convert string to float
        price = strtof(price_str, &endptr);
        
        // Check if conversion was successful
        if (*endptr != '\0' || endptr == price_str) {
            printf("Invalid price! Please enter a numeric value.\n");
            continue;
        }
        
        // Check if price is positive
        if (price <= 0) {
            printf("Price must be positive! Try again.\n");
            continue;
        }
        
        break; // Valid price entered
    }
    
    insertBook(lib, name, author, price);
    printf("Book added successfully.\n");

}

void deleteBookUI(Library *lib) {
    u32 id;
    printf("Enter book ID to delete: ");
    scanf("%d", &id);
    deleteBook(lib, id);
}

void viewBooksUI(Library *lib) {
    sortBooksByName(lib);
    viewBooks(lib);
}