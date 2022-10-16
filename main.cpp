#include <iostream>
#include "Calculator.hpp"
#include "map"
#include "string"
#include "math.h"
#include "interface.hpp"
#include "varible.hpp"

using namespace std;

int main()
{
	varibles.insert(pair<string, string>("E", "2.7182818284"));
	varibles.insert(pair<string, string>("PI", "3.1415926535"));

	printWelcomeChinese();
	string input;
	bool isEnglish = true;

	while (getline(cin, input))
	{
		if (input == "Chinese")
		{
			isEnglish = false;
			cout << "中文设置成功！" << endl;
			continue;
		}
		else if (input == "English")
		{
			isEnglish = true;
			cout << "English is set successfully!" << endl;
			continue;
		}

		if (input == "help")
		{
			if (isEnglish)
				printHelpEnglish();
			else
				printHelpChinese();
			continue;
		}
		else if (input == "welcome")
		{
			if (isEnglish)
				printWelcomeEnglish();
			else
				printWelcomeChinese();
			continue;
		}else if(input=="about"){
				printAboutChinese();
			continue;
		}

		try
		{
			if (isAssigning(input))
			{
				addVariable(input);
				cout << "变量添加成功！" << input << endl;
				continue;
			}
		}
		catch (exception e1)
		{
			if (isEnglish)
				cerr << "The variable name is not valid!" << endl;
			else
				cerr << "变量名不合法！" << endl;

			continue;
		}

		input = replaceAllMathFunctions(input);
		input = replaceVar(input);

		Calculator cal;
		cal.infix = input;
		cal.calculate();
		cout << cal.getResult() << endl;
	}
	return 0;
}
