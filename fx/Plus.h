#pragma once
#include "Operations.h"
class Plus : public Operations
{
public:
	double GetRes(double &, double &);
	bool IsMine(std::string &);
	Plus();
	virtual ~Plus();
};

