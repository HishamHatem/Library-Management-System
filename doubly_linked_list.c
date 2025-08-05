#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "doubly_linked_list.h"


void initLibrary(Library *lib) {
    lib->head = NULL;
}

Book* createBook(u8 *name, u8 *author, f32 price) {
    Book *newBook = (Book*)malloc(sizeof(Book));
    if (!newBook) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    strcpy(newBook->name, name);
    strcpy(newBook->author, author);
    newBook->id = ID++;
    newBook->price = price;
    newBook->prev = newBook->next = NULL;
    return newBook;
}

void insertBook(Library *lib, u8 *name, u8 *author, f32 price) {
    Book *newBook = createBook(name, author, price);
    if (!newBook) return;
    if (!lib->head) {
        lib->head = newBook;
        return;
    }
    Book *temp = lib->head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newBook;
    newBook->prev = temp;
}

void deleteBook(Library *lib, u32 id) {
    Book *temp = lib->head;
    while (temp && temp->id != id) {
        temp = temp->next;
    }
    if (!temp) {
        printf("Book with ID %d not found!\n", id);
        return;
    }
    if (temp->prev) temp->prev->next = temp->next;
    if (temp->next) temp->next->prev = temp->prev;
    if (temp == lib->head) lib->head = temp->next;
    free(temp);
    printf("Book with ID %d deleted successfully.\n", id);
}

void viewBooks(Library *lib) {
    if (!lib->head) {
        printf("No books available in the library.\n");
        return;
    }
    Book *temp = lib->head;
    printf("\nLibrary Books:\n");
    printf("--------------------------------------\n");
    while (temp) {
        printf("ID: %d, Name: %s, Author: %s, Price: %.2f\n", temp->id, temp->name, temp->author, temp->price);
        temp = temp->next;
    }
    printf("--------------------------------------\n");
}

void freeLibrary(Library *lib) {
    Book *temp = lib->head;
    while (temp) {
        Book *next = temp->next;
        free(temp);
        temp = next;
    }
    lib->head = NULL;
}
