#include "Operations.h"

unsigned int Operations::GetPriority()
{
	return priority;
}

bool Operations::IsMine(std::string &)
{
	return false;
}

Operations::Operations() 
{
	IsFunction = false;
	IsOperation = true;
}

Operations::~Operations() {}

