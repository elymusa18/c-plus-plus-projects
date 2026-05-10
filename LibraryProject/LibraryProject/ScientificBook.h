#pragma once
#include "Book.h"

class ScientificBook : public Book {
private:
    char* field;
    char* isbn;

public:
    ScientificBook(const char* title, const char* author, int year, const char* field, const char* isbn);
    ~ScientificBook();

    void print() const override;
};
