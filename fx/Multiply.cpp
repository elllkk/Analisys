#include "Multiply.h"

double Multiply::GetRes(double &a, double &b)
{
	return a*b;
}

bool Multiply::IsMine(std::string &sign)
{
	if (sign == "*")
		return true;
	else
		return false;
}

Multiply::Multiply()
{
	priority = 2;
}


Multiply::~Multiply() {}
