#include "ScientificBook.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

ScientificBook::ScientificBook(const char* t, const char* a, int y, const char* f, const char* i)
    : Book(t, a, y) {
    field = (char*)malloc(strlen(f) + 1);
    strcpy(field, f);
    isbn = (char*)malloc(strlen(i) + 1);
    strcpy(isbn, i);
}

ScientificBook::~ScientificBook() {
    free(field);
    free(isbn);
}

void ScientificBook::print() const {
    printf("Nauchna kniga: %s ot %s (%d), oblast: %s, ISBN: %s\n", title, author, year, field, isbn);
    if (isTaken)
        printf("  Zaeto do: %s\n", returnDate);
    else
        printf("  Nalichno\n");
}
