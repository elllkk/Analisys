#include "Sin.h"

bool Sin::IsMine(std::string &lex)
{
	if (lex == "sin")
		return true;
	else
		return false;
}

double Sin::GetRes(double &a)
{
	return sin(M_PI*a/180);
}

Sin::Sin() {}


Sin::~Sin() {}
