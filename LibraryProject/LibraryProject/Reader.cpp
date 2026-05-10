#include "Reader.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

Reader::Reader(const char* n, int a) {
    name = (char*)malloc(strlen(n) + 1);
    strcpy(name, n);
    age = a;
    borrowedCount = 0;
}

Reader::~Reader() {
    free(name);
}

const char* Reader::getName() const {
    return name;
}

void Reader::borrowBook(Book* book) {
    if (borrowedCount < MAX_BOOKS) {
        borrowedBooks[borrowedCount++] = book;
    }
}

void Reader::returnBook(Book* book) {
    for (int i = 0; i < borrowedCount; ++i) {
        if (borrowedBooks[i] == book) {
            for (int j = i; j < borrowedCount - 1; ++j) {
                borrowedBooks[j] = borrowedBooks[j + 1];
            }
            --borrowedCount;
            break;
        }
    }
}

void Reader::print() const {
    printf("Chitatel: %s, vuzrast: %d\n", name, age);
    printf("  Zaeti knigi: %d\n", borrowedCount);
    for (int i = 0; i < borrowedCount; ++i) {
        printf("   -> %s\n", borrowedBooks[i]->getTitle());
    }
}
