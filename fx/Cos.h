#pragma once
#include "Functions.h"
class Cos : public Functions
{
public:
	bool IsMine(std::string &);
	double GetRes(double &);
	Cos();
	virtual ~Cos();
};

