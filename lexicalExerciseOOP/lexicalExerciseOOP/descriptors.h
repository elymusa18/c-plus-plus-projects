#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "lexicalUnit.h"

class descriptors
{
	lexicalUnit table[100];
	int number;
public:
	descriptors();
	~descriptors();
	int add(lexicalUnit& lu);
	int del(char* pIdentificator);
	int search(char* pIdentificator);
	void print();
};

