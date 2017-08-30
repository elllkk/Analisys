#include "Plus.h"

double Plus::GetRes(double &a, double &b)
{
	return a + b;
}

bool Plus::IsMine(std::string &sign)
{
	if (sign == "+")
		return true;
	else
		return false;
}

Plus::Plus() 
{
	priority = 1;
};


Plus::~Plus() {}
