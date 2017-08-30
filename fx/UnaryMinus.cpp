#include "UnaryMinus.h"

bool UnaryMinus::IsMine(std::string &lex)
{
	if (lex == "#")
		return true;
	else
		return false;
}
double UnaryMinus::GetRes(double &a)
{
	return -a;
}

UnaryMinus::UnaryMinus() {}

UnaryMinus::~UnaryMinus() {}
