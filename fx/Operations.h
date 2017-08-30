#pragma once
#include "MathItem.h"
#include <string>
#include <vector>
class Operations : public MathItem
{
protected :
	unsigned int priority;
public:
	unsigned int GetPriority();
	virtual bool IsMine(std::string &) = 0;
	virtual double GetRes(double &, double &) = 0;
	Operations();
	virtual ~Operations();
};

