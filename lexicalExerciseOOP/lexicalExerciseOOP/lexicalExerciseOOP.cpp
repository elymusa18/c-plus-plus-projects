#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "lexicalUnit.h"
#include "descriptors.h"

int main()
{
    char identificator[20];
    char type[20];

    printf("Enter identificator: \n");
    scanf_s("%s", identificator, (unsigned)_countof(identificator));
    printf("Enter type: \n");
    scanf_s("%s", type, (unsigned)_countof(type));
    lexicalUnit lex1(identificator, type);
    lex1.setDescriptor();
    lex1.setAddress(type);
    lex1.print();
    printf("\n");

    printf("Enter identificator:\n");
    scanf_s("%s", identificator, (unsigned)_countof(identificator));
    printf("Enter type:\n");
    scanf_s("%s", type, (unsigned)_countof(type));
    lexicalUnit lex2(identificator, type);
    lex2.setDescriptor();
    lex2.setAddress(type);
    lex2.print();
    printf("\n");

    printf("Enter identificator:\n");
    scanf_s("%s", identificator, (unsigned)_countof(identificator));
    printf("Enter type:\n");
    scanf_s("%s", type, (unsigned)_countof(type));
    lexicalUnit lex3(identificator, type);
    lex3.setDescriptor();
    lex3.setAddress(type);
    lex3.print();
    printf("\n");

    printf("-------------------------------------- \n");
    printf("Tablica na descriptorite: \n");
    descriptors des;
    des.add(lex1);
    des.add(lex2);
    des.add(lex3);
    des.print();
    printf("\n");

    printf("-------------------------------------- \n");
    printf("Enter id to be deleted: ");
    scanf_s("%s", identificator, (unsigned)_countof(identificator));
    des.del(identificator);
    printf("\n");
    des.print();
}


