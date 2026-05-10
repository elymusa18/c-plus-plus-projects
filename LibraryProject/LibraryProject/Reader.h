#pragma once
#include "Book.h"

#define MAX_BOOKS 10

class Reader {
private:
    char* name;
    int age;
    Book* borrowedBooks[MAX_BOOKS];
    int borrowedCount;

public:
    Reader(const char* name, int age);
    ~Reader();

    const char* getName() const;
    void borrowBook(Book* book);
    void returnBook(Book* book);
    void print() const;
};
