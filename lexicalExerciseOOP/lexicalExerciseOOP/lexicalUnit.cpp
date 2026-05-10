#include "lexicalUnit.h"


int lexicalUnit::newAddress = 0;
int lexicalUnit::newDescriptor = 1;

void lexicalUnit::setAddress(char* type)
{
	address = newAddress;
	int size = 0;
	if (strcmp(type, "int") == 0)
		size = 2;
	if (strcmp(type, "char") == 0)
		size = 1;
	if (strcmp(type, "float") == 0)
		size = 4;
	if (strcmp(type, "double") == 0)
		size = 8;

	newAddress += size;
}

void lexicalUnit::setDescriptor()
{
	sprintf_s(descriptor, "V%d", newDescriptor);
	newDescriptor++;
}

lexicalUnit::lexicalUnit()
{
	strcpy_s(identificator, 20, "");
	strcpy_s(type, 20, "");
	strcpy_s(descriptor, 5, "");
	address = 0;
}

lexicalUnit::lexicalUnit(char* pIdentificator, char* pType)
{
	strcpy_s(identificator, 20, pIdentificator);
	strcpy_s(type, 20, pType);
}

lexicalUnit& lexicalUnit::operator=(lexicalUnit& lu)
{
	strcpy_s(identificator, 20, lu.identificator);
	strcpy_s(type, 20, lu.type);
	strcpy_s(descriptor, 5, lu.descriptor);
	address = lu.address;
	return lu;
}

lexicalUnit::~lexicalUnit() {

}

char* lexicalUnit::getIdentificator()
{
	return identificator;
}

void lexicalUnit::print()
{
	printf("%s |\t %s|\t %s |\t %d", identificator, type, descriptor, address);
}



