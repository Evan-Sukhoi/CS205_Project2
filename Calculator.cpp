// Calculator.cpp: 实现文件
#include <stack>
#include <vector>
#include <string>
#include <cmath>
#include "Calculator.hpp"
#include "bigDecimalCalculator.hpp"
using namespace std;

//绝对值符号个数的奇偶性
enum ABS_ODEVITY
{
	ABS_ODD = 1,
	ABS_EVEN = 2,
};

//算术符号优先权等级
enum PRIO_LV
{
	PRIO_LV0 = 0,
	PRIO_LV1 = 1,
	PRIO_LV2 = 2,
	PRIO_LV3 = 3,
	PRIO_LV4 = 4,
};

Calculator::Calculator()
{ //构造函数，初始化成员变量

	operatorSym = "支持运算符：+, - , *, /, %（百分号）, ^（幂次方）, | |（绝对值），！（阶乘）。其他符号：( ) [ ] { }";
	result = 0.0;
}

string clearEmptySpace(string expression){
    string cleared;
    for (int i = 0; i < expression.length(); ++i) {
        if(expression[i]!=' '){
            cleared+=expression[i];
        }
    }
    return cleared;
}

bool checkUnknownVar(string expression){
    for (int i = 0; i < expression.length(); ++i) {
        if(!(isdigit(expression[i])||expression[i]=='.'
        ||expression[i]=='+'||expression[i]=='-'||expression[i]=='*'||expression[i]=='/'
        ||expression[i]=='('||expression[i]==')')){
            return false;
        }
    }
    return true;
}

void addZero(string &stdInfix){
	for (size_t i = 0; i < stdInfix.size(); i++)
	{ // string.size()返回size_type类型，避免下标运算时的类型溢出
		if (stdInfix[i] == '-' || stdInfix[i] == '+')
		{ //-x转换为0-x，+x转化为0+x
			if (i == 0)
			{
				stdInfix.insert(0, 1, '0');
			}
			else if (stdInfix[i - 1] == '(')
			{
				stdInfix.insert(i, 1, '0');
			}
		}
	}
}

//表达式自定义标准格式化
void Calculator::getFormat()
{

	stdInfix = infix;

	//去除表达式中的空格
	stdInfix = clearEmptySpace(stdInfix);
	
	//检查表达式中是否有未知变量
	if(!checkUnknownVar(stdInfix)){
	    result = "表达式中含有未知变量";
	    return;
	}

	//实现正负数 将输入初始位和括号里面的负数前面加上0
	addZero(stdInfix);
}

//获取算术符号优先级
int Calculator::getPrior(char c)
{

	if (c == '+' || c == '-')
	{
		return PRIO_LV1;
	}
	else if (c == '*' || c == '/')
	{
		return PRIO_LV2;
	}
	else if (c == '%' || c == '^')
	{
		return PRIO_LV3;
	}
	else if (c == '！')
	{
		return PRIO_LV4;
	}
	else
	{
		return PRIO_LV0;
	}
	// else { cout << c << 非法符号！ << endl; }
}

//中缀表达式转换后缀表达式
void Calculator::getPostfix()
{

	int absNumeber = ABS_ODD; //绝对值符号个数的奇偶性
	string tmp;

	// for (int i = 0; i < stdInfix.length(); i++) {
	for (size_t i = 0; i < stdInfix.size(); i++)
	{ // string.size()返回size_type类型，避免下标运算时的类型溢出
		tmp = "";
		switch (stdInfix[i])
		{

		//运算符
		case '+':
		case '-':
		case '*':
		case '/':
		case '%':
		case '^':
		case '!':
			//符号栈为空或遇到左括号时，直接入栈
			if (symStack.empty() || symStack.top() == '(' || symStack.top() == '[' || symStack.top() == '{' || (symStack.top() == '|' && absNumeber == ABS_ODD))
			{
				symStack.push(stdInfix[i]);
			}
			//放入栈中的运算符优先级大于等于当前运算符优先级时，将栈中运算符弹出，放入后缀表达式中
			else
			{
				while (!symStack.empty() && (getPrior(symStack.top()) >= getPrior(stdInfix[i])))
				{
					tmp += symStack.top();
					postfix.push_back(tmp);
					symStack.pop();
					tmp = "";
				}
				symStack.push(stdInfix[i]);
			}
			break;
		case '|':
			if (absNumeber == ABS_ODD)
			{
				symStack.push(stdInfix[i]);
				absNumeber = ABS_EVEN;
			}
			else
			{
				while (!symStack.empty() && symStack.top() != '|')
				{
					tmp += symStack.top();
					postfix.push_back(tmp);
					symStack.pop();
					tmp = "";
				}
				if (!symStack.empty() && symStack.top() == '|')
				{
					tmp += symStack.top();
					postfix.push_back(tmp); //左绝对值符号'|'加入后缀表达式，用于绝对值的检测计算
					symStack.pop();
					absNumeber = ABS_ODD;
				}
			}
			break;
		case '(':
		case '[':
		case '{':
			symStack.push(stdInfix[i]);
			break;
		case ')':
			while (!symStack.empty() && symStack.top() != '(')
			{
				tmp += symStack.top();
				postfix.push_back(tmp);
				symStack.pop();
				tmp = "";
			}
			if (!symStack.empty() && symStack.top() == '(')
			{
				symStack.pop(); //将左括号出栈丢弃
			}
			break;
		case ']':
			while (!symStack.empty() && symStack.top() != '[')
			{
				tmp += symStack.top();
				postfix.push_back(tmp);
				symStack.pop();
				tmp = "";
			}
			if (!symStack.empty() && symStack.top() == '[')
			{
				symStack.pop(); //将左括号出栈丢弃
			}
			break;
		case '}':
			while (!symStack.empty() && symStack.top() != '{')
			{
				tmp += symStack.top();
				postfix.push_back(tmp);
				symStack.pop();
				tmp = "";
			}
			if (!symStack.empty() && symStack.top() == '{')
			{
				symStack.pop(); //将左括号出栈丢弃
			}
			break;
		default:
			if ((stdInfix[i] >= '0' && stdInfix[i] <= '9'))
			{
				tmp += stdInfix[i];
				while (i + 1 < stdInfix.length() && (stdInfix[i + 1] >= '0' && stdInfix[i + 1] <= '9' || stdInfix[i + 1] == '.'))
				{ //小数处理

					tmp += stdInfix[i + 1]; //是连续的数字，则追加
					i++;
				}
				if (tmp[tmp.length() - 1] == '.')
				{
					tmp += '0'; //将x.做x.0处理
				}
				postfix.push_back(tmp);
			}
			break;
		} // end switch
	}	  // end for

	// if(!symStack.empty()) {
	while (!symStack.empty())
	{ //将栈中剩余符号加入后缀表达式
		tmp = "";
		tmp += symStack.top();
		postfix.push_back(tmp);
		symStack.pop();
	}
}

//计算后缀表达式
void Calculator::calResult()
{

	string tmp;
	double number = 0;
	string op1 = "", op2 = "";
	double op1n = 0;
	double op2n = 0;

	for (int i = 0; i < postfix.size(); i++)
	{
		tmp = postfix[i];
		if (tmp[0] >= '0' && tmp[0] <= '9')
		{
			number = atof(tmp.c_str());
			figStack.push(tmp.c_str());
		}
		else if (postfix[i] == "+")
		{
			if (!figStack.empty())
			{
				op2 = figStack.top();
				figStack.pop();
			}
			if (!figStack.empty())
			{
				op1 = figStack.top();
				figStack.pop();
			}
			figStack.push(Add(op1, op2));
		}
		else if (postfix[i] == "-")
		{
			if (!figStack.empty())
			{
				op2 = figStack.top();
				figStack.pop();
			}
			if (!figStack.empty())
			{
				op1 = figStack.top();
				figStack.pop();
			}
			figStack.push(Minus(op1, op2));
		}
		else if (postfix[i] == "*")
		{
			if (!figStack.empty())
			{
				op2 = figStack.top();
				figStack.pop();
			}
			if (!figStack.empty())
			{
				op1 = figStack.top();
				figStack.pop();
			}
			figStack.push(Mul(op1, op2));
		}
		else if (postfix[i] == "/")
		{
			if (!figStack.empty())
			{
				op2 = figStack.top();
				figStack.pop();
			}
			if (!figStack.empty())
			{
				op1 = figStack.top();
				figStack.pop();
			}
			if (op2 != "0")
				op2n = stod(op2);
			if (op2n == 0)
				result = "非法输入！除数不能为0";
			else
				figStack.push(Division(op1, op2));
		}
		else if (postfix[i] == "%")
		{
			if (!figStack.empty())
			{
				op2 = figStack.top();
				figStack.pop();
			}
			if (!figStack.empty())
			{
				op1 = figStack.top();
				figStack.pop();
			}
			if (op2 != "0")
				op2n = stod(op2);
			if (op1 != "0")
				op1n = stod(op1);
			figStack.push(to_string(fmod(op1n, op2n))); //可进行小数求余
		}
		else if (postfix[i] == "^")
		{
			if (!figStack.empty())
			{
				op2 = figStack.top();
				figStack.pop();
			}
			if (!figStack.empty())
			{
				op1 = figStack.top();
				figStack.pop();
			}
			if (op2 != "0")
				op2n = stod(op2);
			if (op1 != "0")
				op1n = stod(op1);
			figStack.push(to_string(pow(op1n, op2n)));
		}
		else if (postfix[i] == "|")
		{
			if (!figStack.empty())
			{
				op1 = figStack.top();
				figStack.pop();
			}
			double op1n = 0;
			if (op1 != "0")
				op1n = stod(op1);
			figStack.push(to_string(abs(op1n)));
		}
		else if (postfix[i] == "!")
		{
			if (!figStack.empty())
			{
				op1 = figStack.top();
				figStack.pop();
			}
			if (op1 != "0")
				op1n = stod(op1);
			if (op1n > 0)
			{
				//阶乘数应大于；为小数时(转化为整数求阶)
				double factorial = 1;
				for (int i = 1; i <= op1n; ++i)
				{
					factorial *= i;
				}
				op1 = to_string(factorial);
			}
			figStack.push(op1);
		}
	} // end for
	if (!figStack.empty())
	{
		result = figStack.top();
	}
}

//计算方法
void Calculator::calculate()
{
	getFormat();  //表达式自定义标准格式化
	getPostfix(); //后缀表达式转换
	calResult();  //获取算术结果
}

//获取结果
string Calculator::getResult()
{
	return result;
}
