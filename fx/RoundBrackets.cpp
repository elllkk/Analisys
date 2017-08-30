#include "RoundBrackets.h"

bool RoundBrackets::IsOpenBracket()
{
	if (typeOfBracket)
		return false;
	else
		return true;
}

bool RoundBrackets::IsCloseBracket()
{
	if (typeOfBracket)
		return true;
	else
		return false;
}


RoundBrackets::RoundBrackets(bool type)
{
	typeOfBracket = type;
}

RoundBrackets::~RoundBrackets()
{
}
