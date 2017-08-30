#pragma once
#include "Operations.h"
class Divide : public Operations
{
public:
	double GetRes(double &, double &);
	bool IsMine(std::string &);
	Divide();
	virtual ~Divide();
};

