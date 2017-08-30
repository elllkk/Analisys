#pragma once
#include "Operations.h"
class Multiply : public Operations
{
public:
	double GetRes(double &, double &);
	bool IsMine(std::string &);
	Multiply();
	virtual ~Multiply();
};

