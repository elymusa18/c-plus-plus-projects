#pragma once
#include "Book.h"
#include "FictionBook.h"
#include "ScientificBook.h"
#include "Reader.h"

#define MAX_LIBRARY_BOOKS 200
#define MAX_LIBRARY_READERS 100

class Library {
private:
    Book* books[MAX_LIBRARY_BOOKS];
    Reader* readers[MAX_LIBRARY_READERS];
    int bookCount;
    int readerCount;

public:
    Library();
    ~Library();

    void addBook(Book* book);
    void addReader(Reader* reader);
    void borrowBook(const char* bookTitle, const char* readerName, const char* returnDate);
    void returnBook(const char* bookTitle, const char* readerName);
    void printBooks() const;
    void printReaders() const;
};
