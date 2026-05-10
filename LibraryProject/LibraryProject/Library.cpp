#include "Library.h"
#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

Library::Library() : bookCount(0), readerCount(0) {}

Library::~Library() {
    for (int i = 0; i < bookCount; ++i) delete books[i];
    for (int i = 0; i < readerCount; ++i) delete readers[i];
}

void Library::addBook(Book* book) {
    if (bookCount < MAX_LIBRARY_BOOKS) books[bookCount++] = book;
}

void Library::addReader(Reader* reader) {
    if (readerCount < MAX_LIBRARY_READERS) readers[readerCount++] = reader;
}

void Library::borrowBook(const char* bookTitle, const char* readerName, const char* returnDate) {
    Book* b = nullptr;
    Reader* r = nullptr;
    for (int i = 0; i < bookCount; ++i) {
        if (strcmp(books[i]->getTitle(), bookTitle) == 0 && books[i]->available()) {
            b = books[i];
            break;
        }
    }
    for (int i = 0; i < readerCount; ++i) {
        if (strcmp(readers[i]->getName(), readerName) == 0) {
            r = readers[i];
            break;
        }
    }
    if (b && r) {
        b->markAsTaken(0, returnDate); // ID не се използва реално
        r->borrowBook(b);
        printf("Knigata \"%s\" e zaeta ot %s\n", bookTitle, readerName);
    }
    else {
        printf("Neuspeshno zaemane na kniga.\n");
    }
}

void Library::returnBook(const char* bookTitle, const char* readerName) {
    Book* b = nullptr;
    Reader* r = nullptr;
    for (int i = 0; i < bookCount; ++i) {
        if (strcmp(books[i]->getTitle(), bookTitle) == 0) {
            b = books[i];
            break;
        }
    }
    for (int i = 0; i < readerCount; ++i) {
        if (strcmp(readers[i]->getName(), readerName) == 0) {
            r = readers[i];
            break;
        }
    }
    if (b && r) {
        b->markAsReturned();
        r->returnBook(b);
        printf("Knigata \"%s\" e vurnata ot %s\n", bookTitle, readerName);
    }
}

void Library::printBooks() const {
    printf("Spisuk s knigi:\n");
    for (int i = 0; i < bookCount; ++i) {
        books[i]->print();
    }
}

void Library::printReaders() const {
    printf("Spisuk s chitateli:\n");
    for (int i = 0; i < readerCount; ++i) {
        readers[i]->print();
    }
}
