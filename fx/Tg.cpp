#include "Tg.h"

bool Tg::IsMine(std::string &lex)
{
	if (lex == "tg")
		return true;
	else
		return false;
}

double Tg::GetRes(double &a)
{
	return tan(M_PI*a / 180);
}

Tg::Tg() {}


Tg::~Tg() {}
