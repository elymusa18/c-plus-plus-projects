#include "FictionBook.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

FictionBook::FictionBook(const char* t, const char* a, int y, const char* g)
    : Book(t, a, y) {
    genre = (char*)malloc(strlen(g) + 1);
    strcpy(genre, g);
}

FictionBook::~FictionBook() {
    free(genre);
}

void FictionBook::print() const {
    printf("Hudojestvena kniga: %s ot %s (%d), janr: %s\n", title, author, year, genre);
    if (isTaken)
        printf("  Zaeto do: %s\n", returnDate);
    else
        printf("  Nalichno\n");
}
