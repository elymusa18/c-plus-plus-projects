#include "Book.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

Book::Book(const char* t, const char* a, int y) {
    title = (char*)malloc(strlen(t) + 1);
    strcpy(title, t);
    author = (char*)malloc(strlen(a) + 1);
    strcpy(author, a);
    year = y;
    isTaken = false;
    takenByReaderId = -1;
    returnDate[0] = '\0';
}

Book::~Book() {
    free(title);
    free(author);
}

const char* Book::getTitle() const {
    return title;
}

bool Book::available() const {
    return !isTaken;
}

void Book::markAsTaken(int readerId, const char* date) {
    isTaken = true;
    takenByReaderId = readerId;
    strcpy(returnDate, date);
}

void Book::markAsReturned() {
    isTaken = false;
    takenByReaderId = -1;
    returnDate[0] = '\0';
}
