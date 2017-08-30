#include "Ctg.h"

bool Ctg::IsMine(std::string &lex)
{
	if (lex == "ctg")
		return true;
	else
		return false;
}

double Ctg::GetRes(double &a)
{
	return 1/tan(M_PI*a / 180);
}

Ctg::Ctg() {}


Ctg::~Ctg() {}
