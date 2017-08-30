#pragma once
#include "Functions.h"
class UnaryMinus : public Functions
{
public:
	bool IsMine(std::string &);
	double GetRes(double &);
	UnaryMinus();
	virtual ~UnaryMinus();
};

