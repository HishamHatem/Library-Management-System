#ifndef GENERAL_H
#define GENERAL_H

#include "doubly_linked_list.h"

void setPassword(u8 *password);
u32 verifyPassword(const u8 *password);
void sortBooksByName(Library *lib);


#endif // GENERAL_H