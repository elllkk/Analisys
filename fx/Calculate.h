#pragma once
#include <cstdlib>
#include "Parser.h"

class Calculate
{
private:
	Parser parser;
public:
	std::string MakeCalculations(const std::string &);
	Calculate();
	virtual ~Calculate();
};

