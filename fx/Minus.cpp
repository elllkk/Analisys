#include "Minus.h"

double Minus::GetRes(double &a, double &b)
{
	return a - b;
}

bool Minus::IsMine(std::string &lex)
{
	if (lex == "-")
		return true;
	else
		return false;
}

Minus::Minus() 
{
	priority = 1;
}

Minus::~Minus() {}
