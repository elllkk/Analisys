#include "Divide.h"

double Divide::GetRes(double &a, double &b)
{
	return a / b;
}

bool Divide::IsMine(std::string &lex)
{
	if (lex == "/" || lex == ":")
		return true;
	else
		return false;
}

Divide::Divide()
{
	priority = 2;
}

Divide::~Divide() {}
