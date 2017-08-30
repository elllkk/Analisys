#include "Parser.h"

void Parser::CommaToPoint(std::string &exp)
{
	const char *first = &exp[0];
	const char *last = first + exp.length();
	std::regex rx(",");
	std::string fmt(".");
	std::regex_constants::match_flag_type def = std::regex_constants::match_default;
	//выбирать только 1 и тд
	*std::regex_replace(&exp[0], first, last, rx, fmt, def) = '\0';
	//в конец ставить конец строки
	exp = &exp[0];
}

bool Parser::IsNumber(std::string &token)
{
	if (atof(token.c_str()) == 0 && atof(("1" + token).c_str()) == 1)
		return false;
	return true;
}

void Parser::DeleteSpaces(std::string &exp)
{
	const char *first = &exp[0];
	const char *last = first + exp.length();
	std::regex rx(" ");
	std::string fmt("");
	std::regex_constants::match_flag_type def = std::regex_constants::match_default;
	//выбирать только 1 и тд
	*std::regex_replace(&exp[0], first, last, rx, fmt, def) = '\0';
	//в конец ставить конец строки
	exp = &exp[0];
}

void Parser::PutMultiplication(std::string &exp)
{
	std::regex putThere1("(.{0,}[0-9\\)]{1,})([^-+*/:0-9.,\\)].{0,})");
	//std::regex putThere2("(.{0,}[\)])([^-^+^*^/^:^0-9^.^,^\)].{0,})");
	std::smatch searchRes;
	//(7+8)(-3+2)
	while (std::regex_search(exp, searchRes, putThere1)) 
	{
		exp = searchRes[1].str() + "*" + searchRes[2].str(); //(2+sin(10))(456+6)
	}
	//while (std::regex_search(exp, searchRes, putThere2))
	//{
		//exp = searchRes[1].str() + "*" + searchRes[2].str();
	//}
}

void Parser::FromUnaryMinusToGrid(std::string &exp)
{
	std::regex changeThis1("(.{0,}[\-+*\/:\(])-(.{0,})");
	std::regex changeThis2("^-(.{0,})");
	std::smatch searchRes;
	while (std::regex_search(exp, searchRes, changeThis1))
	{
		//exp[searchRes.position] = '#';
		exp = searchRes[1].str() + "#" + searchRes[2].str();
	}
	while (std::regex_search(exp, searchRes, changeThis2))
	{
		exp = "#" + searchRes[1].str();
	}
}

MathItem *Parser::GetLexeme(std::string &exp)
{
	if (exp.length() != 0)
	{
		for (int i = 0; i < RegexAndMathItem.size() - 2; i++)
		{
			std::smatch result;
			if (std::regex_match(exp, result, RegexAndMathItem[i].first))
			{
				std::string res = result[1];
				exp = result[2];
				RegexAndMathItem[i].second->SetLex(res);
				return RegexAndMathItem[i].second;
			}
		}

		for (int i = RegexAndMathItem.size() - 2; i < RegexAndMathItem.size(); i++)
		{
			std::smatch result;
			if (std::regex_match(exp, result, RegexAndMathItem[i].first))
			{
				std::string res = result[1];
				exp = result[2];
				Numbers *num = new Numbers;
				num->SetLex(res);
				return num;
			}
		}
	}

	return new MathItem;
}

std::queue <MathItem *> Parser::Translate(std::string &exp)
{
	std::queue <MathItem *> outputQueue;
	std::stack <MathItem *> stack;

	CommaToPoint(exp);
	DeleteSpaces(exp);
	PutMultiplication(exp);
	FromUnaryMinusToGrid(exp);
	transform(exp.begin(), exp.end(), exp.begin(), ::tolower);

	while (exp.length() != 0)
	{
		MathItem *item = GetLexeme(exp);

		if (typeid(*item) == typeid(Numbers))
		{
			outputQueue.push(item);
			continue;
		}
			
		if (typeid(*item) == typeid(RoundBrackets))
		{
			if ((*item).IsOpenBracket())
			{
				stack.push(item);
				continue;
			}
			else
			{// closing bracket
				if (stack.empty())
				{
					throw std::exception();
					//return std::queue <MathItem *>();
				}
				//
				while (typeid(*stack.top()) != typeid(RoundBrackets))
				{
					outputQueue.push(stack.top());
					stack.pop();
					if (stack.empty())
					{
						throw std::exception("Wrong closing bracket");
						//return std::queue <MathItem *>();
					}
				} // x -> x

				if (typeid(*stack.top()) == typeid(RoundBrackets)) // can only be ( !!!!
				{
					stack.pop();
					if (stack.top()->IsFunction) // function(......)
					{
						outputQueue.push(stack.top());
						stack.pop();
						continue;
					}
					continue;
				}
				else
				{
					throw std::exception("!!!! Parser logic error, fix me");
				}
				
			}
		}

		//если лексема -операция 
		if (item->IsOperation)
		{
			if (!stack.empty()) while (stack.top()->IsFunction)
			{
				outputQueue.push(stack.top());
				stack.pop();
				if (stack.empty())
					break;
			}
			if (!stack.empty())
			{
				while (stack.top()->IsOperation &&
					item->GetPriority() <= stack.top()->GetPriority())
				{
					outputQueue.push(stack.top());
					stack.pop();
					if (stack.empty())
						break;
				}
			}
			stack.push(item);
			continue;
		}
		
		//если лекс - ф-я
		if (item->IsFunction)
		{
			stack.push(item);
			continue;
		}
	}

	while (!stack.empty())
	{
		if (typeid(*stack.top()) == typeid(RoundBrackets))
		{
			throw std::exception();
			return std::queue <MathItem *>();
		}
		outputQueue.push(stack.top());
		stack.pop();
	}	
		return outputQueue;
}
//
//std::string Parser::GetPreffixView(std::string &exp)
//{
//	std::queue <MathItem *> tempQueue = Translate(exp);
//	if (tempQueue.empty())
//		return "Invalid expression! Try again.\n";
//	else
//	{
//		std::string preffixExp;
//		while (!tempQueue.empty())
//		{
//			preffixExp += tempQueue.front()->GetLex() + " ";
//			tempQueue.pop();
//		}
//		return preffixExp;
//	}
//}

Parser::Parser() 
{
	if (RegexAndMathItem.size() == 0)
	{
		RegexAndMathItem.push_back(make_pair(std::regex("^([+])(.{0,})"), new Plus));
		RegexAndMathItem.push_back(make_pair(std::regex("^([-])(.{0,})"), new Minus));
		RegexAndMathItem.push_back(make_pair(std::regex("^([\*])(.{0,})"), new Multiply));
		RegexAndMathItem.push_back(make_pair(std::regex("^([\/])(.{0,})"), new Divide));
		RegexAndMathItem.push_back(make_pair(std::regex("^([:])(.{0,})"), new Divide));
		RegexAndMathItem.push_back(make_pair(std::regex("^([#])(.{0,})"), new UnaryMinus));
		RegexAndMathItem.push_back(make_pair(std::regex("^(sin)(.{0,})"), new Sin));
		RegexAndMathItem.push_back(make_pair(std::regex("^(cos)(.{0,})"), new Cos));
		RegexAndMathItem.push_back(make_pair(std::regex("^(tg)(.{0,})"), new Tg));
		RegexAndMathItem.push_back(make_pair(std::regex("^(ctg)(.{0,})"), new Ctg));
		RegexAndMathItem.push_back(make_pair(std::regex("^([\(])(.{0,})"), new RoundBrackets(0)));
		RegexAndMathItem.push_back(make_pair(std::regex("^([\)])(.{0,})"), new RoundBrackets(1)));
		RegexAndMathItem.push_back(make_pair(std::regex("^([0-9]{1,}[\.,][0-9]{1,})(.{0,})"), new Numbers));
		RegexAndMathItem.push_back(make_pair(std::regex("^([0-9]{1,})(.{0,})"), new Numbers));
	}
}

Parser::~Parser() {}
