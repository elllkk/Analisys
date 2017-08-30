#pragma once
#include <cctype>
#include <iostream>
#include <regex>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <sstream>
#include "MathItem.h"
#include "RoundBrackets.h"
#include"Numbers.h"
#include "Operations.h"
#include "Plus.h"
#include "Minus.h"
#include "Multiply.h"
#include "Divide.h"
#include "Functions.h"
#include "Sin.h"
#include "Cos.h"
#include "Tg.h"
#include "Ctg.h"
#include "UnaryMinus.h"
class Parser
{
public:
	static std::vector <std::pair<std::regex, MathItem*>> RegexAndMathItem;
	static bool IsNumber(std::string &);
	static void DeleteSpaces(std::string &);
	static void PutMultiplication(std::string &);
	static void FromUnaryMinusToGrid(std::string &);
	static MathItem *GetLexeme(std::string &);
	static void CommaToPoint(std::string &);
	//std::string GetPreffixView(std::string &);
	std::queue <MathItem *> Translate(std::string &);
	Parser();
	virtual ~Parser();
};

