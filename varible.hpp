#include <iostream>
#include "string"
#include <cmath>
#include "map"

using namespace std;

static inline bool containsCertainMathFunctions(string expression, string funName);
// check if certain function name is contained in the expression
static inline string replaceAllMathFunctions(string expression);
// if contains, then replace it into real value.

static inline bool isAssigning(string expression);
// to check if the expression is for assigning
static inline void addVariable(string expression);
// to add some variables ArrayList.
static inline string replaceVar(string expression);
// to replace the variables in the expression.

map<string, string> varibles;
bool isAssigning(string expression)
{
	int indexOfAssign = expression.find('=');
	if (indexOfAssign != -1)
	{
		string var = expression.substr(0, indexOfAssign);
		bool varNameValid = true;
		// check varName isValid start.
		// throw an exception if not valid.
		if (!(isalpha(var[0]) || var[0] == '_'))
		{
			varNameValid = false;
		}
		for (int i = 1; (i < var.length() && varNameValid == true); ++i)
		{
			if (!(isdigit(var[i]) || isalpha(var[i]) || var[i] == '_'))
			{
				varNameValid = false;
				break;
			}
		}
		if (!varNameValid)
		{
			throw exception();
		}
		// check varName isValid
		return true;
	}
	return false;
}

string replaceVar(string expression)
{
	// read the ith key-value pair
	map<string, string, int>::iterator it = varibles.begin();
	string varName = it->first;
	string varValue = it->second;
	it = varibles.begin();
	while (it != varibles.end())
	{
		varName = it->first;
		varValue = it->second;
		int indexOfVar = expression.find(varName);
		while (expression.find(varName) != -1)
		{
			int index = expression.find(varName);
			string before = expression.substr(0, index);
			string after = expression.substr(index + varName.length());
			expression = before + varValue + after;
		}
		it++;
	}
	return expression;
}

void addVariable(string expression)
{
	int index = expression.find('=');
	Calculator cal;
	string varName = expression.substr(0, index);
	string valStr = expression.substr(index + 1);
	cal.infix = valStr;
	cal.calculate();
	valStr = cal.getResult();
	bool contains = false;
	for (int i = 0; i < varibles.size(); i++)
	{
		if (varibles.count(varName))
		{
			contains = true;
			break;
		}
	}
	if (contains)
	{
		int index = 0;
		for (int i = 0; i < varibles.size(); ++i)
		{
			if (varibles.count(varName))
			{
				index = i;
				break;
			}
		}
		// replace the value of the variable.
		varibles.erase(varName);
	}
	varibles.insert(pair<string, string>(varName, valStr));
}

bool containsCertainMathFunctions(string expression, string funName)
{
	return expression.find(funName) != -1;
}

string replaceAllMathFunctions(string expression)
{
	Calculator cal;
	if (expression == "nan")
	{
		return expression;
	}
	expression = replaceVar(expression);
	while (containsCertainMathFunctions(expression, "sqrt("))
	{
		int left = expression.find("sqrt(");
		int right = left;
		for (int i = left; i < expression.length(); i++)
		{
			if (expression[i] == ')')
			{
				right = i;
				break;
			}
		}

		string before = expression.substr(0, left);
		string after = expression.substr(right + 1);
		string previous1 = expression.substr(left + 4, right - left - 3);

		// CWTNumber value(solve(previous1).c_str());
		cal.infix = previous1;
		cal.calculate();
		string value = cal.getResult();

		string middle = to_string(sqrt(stod(value)));
		expression = before + middle + after;
	}
	while (containsCertainMathFunctions(expression, "pow("))
	{
		int left = expression.find("pow(");
		int right = left, comma = left;
		for (int i = left; i < expression.length(); i++)
		{
			if (expression[i] == ',')
			{
				comma = i;
			}
			else if (expression[i] == ')')
			{
				right = i;
				break;
			}
		}
		string before = expression.substr(0, left);
		string after = expression.substr(right + 1);

		string previous1 = expression.substr(left + 4, comma - left - 4);
		string previous2 = expression.substr(comma + 1, right - comma - 1);

		cal.infix = previous1;
		cal.calculate();
		string value1 = cal.getResult();
		cal.infix = previous2;
		cal.calculate();
		string value2 = cal.getResult();

		string middle = to_string(pow(stod(value1), stod(value2)));
		expression = before + middle + after;
	}
	while (containsCertainMathFunctions(expression, "abs("))
	{
		int left = expression.find("abs(");
		int right = left;
		for (int i = left; i < expression.length(); i++)
		{
			if (expression[i] == ')')
			{
				right = i;
				break;
			}
		}
		string before = expression.substr(0, left);
		string after = expression.substr(right + 1);

		string previous = expression.substr(left + 4, right - left - 4);

		cal.infix = previous;
		cal.calculate();
		string value = cal.getResult();

		double middle = abs(stod(value));

		if (middle < 0)
		{
			middle = (-1) * middle;
		}
		expression = before + to_string(middle) + after;
	}
	while (containsCertainMathFunctions(expression, "random()"))
	{
		int left = expression.find("random(");
		int right = left;
		for (int i = left; i < expression.length(); i++)
		{
			if (expression[i] == ')')
			{
				right = i;
				break;
			}
		}
		string before = expression.substr(0, left);
		string after = expression.substr(right + 1);

		string middle = to_string(rand());
		expression = before + middle + after;
	}
	while (containsCertainMathFunctions(expression, "exp("))
	{
		int left = expression.find("exp(");
		int right = left;
		for (int i = left; i < expression.length(); i++)
		{
			if (expression[i] == ')')
			{
				right = i;
				break;
			}
		}

		string before = expression.substr(0, left);
		string after = expression.substr(right + 1);
		string previous = expression.substr(left + 4, right - left - 4);

		string middle = to_string(exp(stod(previous)));
		expression = before + middle + after;
	}
	while (containsCertainMathFunctions(expression, "sin("))
	{
		int left = expression.find("sin(");
		int right = left;
		for (int i = left; i < expression.length(); i++)
		{
			if (expression[i] == ')')
			{
				right = i;
				break;
			}
		}
		string before = expression.substr(0, left);
		string after = expression.substr(right + 1);

		string previous = expression.substr(left + 4, right - left - 4);
		cal.infix = previous;
		cal.calculate();
		string value = cal.getResult();
		string middle = to_string(sin(stod(value)));
		expression = before + middle + after;
	}
	while (containsCertainMathFunctions(expression, "cos("))
	{
		int left = expression.find("cos(");
		int right = left;
		for (int i = left; i < expression.length(); i++)
		{
			if (expression[i] == ')')
			{
				right = i;
				break;
			}
		}
		string before = expression.substr(0, left);
		string after = expression.substr(right + 1);

		string previous = expression.substr(left + 4, right - left - 4);
		cal.infix = previous;
		cal.calculate();
		string value = cal.getResult();
		string middle = to_string(cos(stod(value)));
		expression = before + middle + after;
	}
	while (containsCertainMathFunctions(expression, "tan("))
	{
		int left = expression.find("tan(");
		int right = left;
		for (int i = left; i < expression.length(); i++)
		{
			if (expression[i] == ')')
			{
				right = i;
				break;
			}
		}
		string before = expression.substr(0, left);
		string after = expression.substr(right + 1);

		string previous = expression.substr(left + 4, right - left - 4);
		cal.infix = previous;
		cal.calculate();
		string value = cal.getResult();
		string middle = to_string(tan(stod(value)));
		expression = before + middle + after;
	}
	while (containsCertainMathFunctions(expression, "ceil("))
	{
		int left = expression.find("ceil(");
		int right = left;
		for (int i = left; i < expression.length(); i++)
		{
			if (expression[i] == ')')
			{
				right = i;
				break;
			}
		}

		string before = expression.substr(0, left);
		string after = expression.substr(right + 1);
		string previous1 = expression.substr(left + 5, right - left - 5);

		string middle = to_string(ceil(stod(previous1)));
		expression = before + middle + after;
	}
	while (containsCertainMathFunctions(expression, "floor("))
	{
		int left = expression.find("floor(");
		int right = left;
		for (int i = left; i < expression.length(); i++)
		{
			if (expression[i] == ')')
			{
				right = i;
				break;
			}
		}

		string before = expression.substr(0, left);
		string after = expression.substr(right + 1);
		string previous1 = expression.substr(left + 6, right - left - 6);

		string middle = to_string(floor(stod(previous1)));
		expression = before + middle + after;
	}
	while (containsCertainMathFunctions(expression, "log("))
	{
		int left = expression.find("log(");
		int right = left;
		for (int i = left; i < expression.length(); i++)
		{
			if (expression[i] == ')')
			{
				right = i;
				break;
			}
		}
		string before = expression.substr(0, left);
		string after = expression.substr(right + 1);

		string previous = expression.substr(left + 4, right - left - 4);
		string middle = to_string(log(stod(previous)));
		expression = before + middle + after;
	}
	return expression;
}