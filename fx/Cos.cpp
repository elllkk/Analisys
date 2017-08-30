#include "Cos.h"

bool Cos::IsMine(std::string &lex)
{
	if (lex == "cos")
		return true;
	else
		return false;
}

double Cos::GetRes(double &a)
{
	return cos(M_PI*a / 180);
}

Cos::Cos() 
{
}


Cos::~Cos() {}
