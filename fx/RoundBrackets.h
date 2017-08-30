#pragma once
#include "MathItem.h"
class RoundBrackets : public MathItem
{
private:
	bool typeOfBracket;
public:
	bool IsOpenBracket();
	bool IsCloseBracket();
	RoundBrackets(bool);
	virtual ~RoundBrackets();
};

