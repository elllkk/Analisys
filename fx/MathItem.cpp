#include "MathItem.h"

std::string MathItem::GetLex()
{
	return lex;
}
void MathItem::SetLex(std::string lex)
{
	this->lex = lex;
}

unsigned int MathItem::GetPriority() { return 0; }
bool MathItem::IsOpenBracket() { return false; }
bool MathItem::IsCloseBracket() { return false; }
double MathItem::GetRes(double &) { return 0; }
double MathItem::GetRes(double &, double &) { return 0; }

MathItem::MathItem() 
{
	IsFunction = false;
	IsOperation = false;
}

MathItem::~MathItem() {}
