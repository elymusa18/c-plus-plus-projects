#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

class lexicalUnit
{
	char identificator[20];
	char type[20];
	char descriptor[5];
	int address;
	static int newAddress;
	static int newDescriptor;
public:
	void setAddress(char* type);
	void setDescriptor();
	lexicalUnit();
	lexicalUnit(char* pIdentificator, char* pType);
	lexicalUnit& operator=(lexicalUnit& lu);
	~lexicalUnit();
	char* getIdentificator();
	void print();
};




