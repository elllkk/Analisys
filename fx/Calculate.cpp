#include "Calculate.h"
#include <iomanip>
#include <iostream>

void Round3(double &x)
{
	x = trunc(x*1000)/1000;
}
std::string Calculate::MakeCalculations(const std::string &expr)
{
	std::string exp = expr;
	std::queue <MathItem *> preffixView;
	try 
	{
		preffixView = parser.Translate(exp);
	}
	catch(std::exception)
	{
		return "There are errors in expression. May you forgot a bracket? \n";
	}
	std::stack<double> stack;

	//int numOfFunctionOrOperation;
	while (!preffixView.empty())
	{
		MathItem *frontItem = preffixView.front();
		if (typeid(*frontItem) == typeid(Numbers))
		{
			stack.push(atof((frontItem->GetLex()).c_str()));
			preffixView.pop();
		}
		else if (frontItem->IsFunction)
		{
			stack.top() = frontItem->GetRes(stack.top());
			preffixView.pop();
		}

		else
		{
			double b = stack.top();
			stack.pop();
			stack.top() = frontItem->GetRes(stack.top(), b);
			preffixView.pop();
		}
	}

	std::stringstream doubleToStr;
	//Round3(stack.top());
	doubleToStr.setf(std::ios::fixed);
	doubleToStr <<std::setprecision(3)<<stack.top();
	//doubleToStr << stack.top();
	return doubleToStr.str();
}

Calculate::Calculate() {}

Calculate::~Calculate() {}
