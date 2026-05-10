#include "Library.h"
#include <stdio.h>
#include <iostream>
#pragma warning(disable:4996)


int main() {
  

    Library lib;

    lib.addBook(new FictionBook("Pod igoto", "Ivan Vazov", 1894, "Istoriq"));
    lib.addBook(new ScientificBook("Fizika na budeshteto", "Michiu Kaku", 2011, "Fizika", "978954"));

    lib.addReader(new Reader("Petur Petrov", 22));
    lib.addReader(new Reader("Mariq Georgieva", 19));

    lib.borrowBook("Pod igoto", "Petur Petrov", "20.04.2025");
    lib.borrowBook("Fizika na budeshteto", "Mariq Georgieva", "21.04.2025");

    printf("\n--- Sustoqnie na bibliotekata ---\n");
    lib.printBooks();
    lib.printReaders();

    lib.returnBook("Pod igoto", "Petur Petrov");

    printf("\n--- Sled vrushtane ---\n");
    lib.printBooks();
    lib.printReaders();

    return 0;
}
