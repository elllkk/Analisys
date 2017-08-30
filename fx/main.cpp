#include <iostream>
#include <regex>
#include "Calculate.h"
#include <map>
std::vector <std::pair<std::regex, MathItem*>> Parser::RegexAndMathItem;

void Test()
{
	Calculate calculate;
	std::map <std::string, double> exp;
	exp["1- tG45"] = 0;
	exp["(-2)*3+4.2-12,13"] = -13.93;
	exp["----2"] = 2;

	for (auto now : exp)
	{
		if (atof(calculate.MakeCalculations(now.first).c_str()) == now.second)
			std::cout << "YES\n";
		else
		{
			std::cout << "NO\n";
			std::cout << calculate.MakeCalculations(now.first) << std::endl;
		}
			
	}
}

int main()
{
	//std::string exp;
	//std::cout << "Input expression:\n";
	//getline(std::cin, exp);
	//Calculate calculate;
	//std::cout << "Result:\n";
	//std::cout << calculate.MakeCalculations(exp) << "\n";
	Test();

	return 0;
}