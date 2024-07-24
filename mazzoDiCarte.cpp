#include <iostream>
#include "mazzoDiCarte.h"

MazzoDiCarte::MazzoDiCarte()
{
	dim = 0;
	c = nullptr;
}

MazzoDiCarte::~MazzoDiCarte()
{
	delete[] c;
}
