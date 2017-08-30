#pragma once
#include "MathItem.h"
#include <string>
#include <cmath>
class Functions : public MathItem
{
public:	
	virtual bool IsMine(std::string &) = 0;
	virtual double GetRes(double &) = 0;
	Functions();
	virtual ~Functions();
};

