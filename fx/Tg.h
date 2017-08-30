#pragma once
#include "Functions.h"
class Tg : public Functions
{
public:
	bool IsMine(std::string &);
	double GetRes(double &);
	Tg();
	virtual ~Tg();
};

