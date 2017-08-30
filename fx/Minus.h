#pragma once
#include "Operations.h"
class Minus : public Operations
{
public:
	double GetRes(double &, double &);
	bool IsMine(std::string &);
	Minus();
	virtual ~Minus();
};

