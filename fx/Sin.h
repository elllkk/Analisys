#pragma once
#include "Functions.h"
class Sin : public Functions
{
public:
	bool IsMine(std::string &) override;
	double GetRes(double &) override;
	Sin();
	virtual ~Sin();
};

