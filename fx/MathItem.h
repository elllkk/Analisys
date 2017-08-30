#pragma once
#define _USE_MATH_DEFINES 
#include <iostream>
#include <string>
class MathItem
{
private:
	std::string lex;
public:
	bool IsFunction;
	bool IsOperation;
	virtual double GetRes(double &);
	virtual double GetRes(double &, double &);
	virtual unsigned int GetPriority();
	virtual bool IsOpenBracket();
	virtual bool IsCloseBracket();
	std::string GetLex();
	void SetLex(std::string);
	MathItem();
	~MathItem();
};

