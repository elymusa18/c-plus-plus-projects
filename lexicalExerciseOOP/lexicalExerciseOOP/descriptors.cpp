#include "descriptors.h"
#include "lexicalUnit.h"

descriptors::descriptors()
{
	number = 0;
}

descriptors::~descriptors()
{

}

int descriptors::add(lexicalUnit& lu)
{
	int position;
	if (number >= 100)
		return 0;
	position = descriptors::search(lu.getIdentificator());
	if (position < 100) //identificatora go ima
		return 0;
	position -= 100; //nyama go
	if (strcmp(table[position].getIdentificator(), lu.getIdentificator()) < 0 && position < number)
		position++;
	for (int i = number; i > position; i--)
		table[i] = table[i - 1];
	table[position] = lu;
	number++;
	return 0;
}

int descriptors::del(char* pIdentificator)
{
	int srch;
	if (number == 0)
		return 0;
	srch = search(pIdentificator);
	if (srch > 128)
		return 0;
	for (int i = srch; i < number - 1; i++)
		table[i] = table[i + 1];
	number--;
	return 1;
}

int descriptors::search(char* pIdentificator) {
	int top = 0, bottom = number, middle = 0, rez;
	middle = (top + bottom) / 2;
	while (top <= bottom)
	{
		middle = (top + bottom) / 2;
		rez = strcmp(table[middle].getIdentificator(), pIdentificator);
		if (rez == 0) {
			return middle;
		}
		else if (rez < 0) {
			top = middle + 1;
		}
		else {
			bottom = middle - 1;
		}
	}
	return middle + 100;
}
void descriptors::print() {
	for (int i = 0; i < number; i++)
	{
		table[i].print();
		printf("\n");
	}
}
