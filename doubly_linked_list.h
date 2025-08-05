#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H
#include "STD_TYPES.h"

static u32 ID = 0;

typedef struct Book {
    u8 name[100];
    u8 author[100];
    u32 id;
    f32 price;
    struct Book *prev, *next;
} Book;

typedef struct {
    Book *head;
} Library;

void initLibrary(Library *lib);
Book* createBook(u8 *name, u8 *author, f32 price);
void insertBook(Library *lib, u8 *name, u8 *author, f32 price);
void deleteBook(Library *lib, u32 id);
// void displayBooks(Library *lib);
void viewBooks(Library *lib);
void freeLibrary(Library *lib);


#endif // DOUBLY_LINKED_LIST_H
