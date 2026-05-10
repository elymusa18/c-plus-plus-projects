#pragma once
#include <string.h>

class Book {
protected:
    char* title;
    char* author;
    int year;
    bool isTaken;
    int takenByReaderId;
    char returnDate[16];

public:
    Book(const char* title, const char* author, int year);
    virtual ~Book();

    virtual void print() const = 0;

    const char* getTitle() const;
    bool available() const;

    void markAsTaken(int readerId, const char* returnDate);
    void markAsReturned();
};
