#pragma once
#include "Book.h"

class FictionBook : public Book {
private:
    char* genre;

public:
    FictionBook(const char* title, const char* author, int year, const char* genre);
    ~FictionBook();

    void print() const override;
};
