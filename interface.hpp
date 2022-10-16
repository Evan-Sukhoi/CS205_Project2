#include <iostream>
using namespace std;

// Print help list
static inline void printHelpEnglish();
static inline void printWelcomeEnglish();
static inline void printHelpChinese();
static inline void printWelcomeChinese();

void printWelcomeEnglish()
{
	cout << "------------Simple multifunctional high precision calculator-----------" << endl;
	cout << "If you need help, please print help to get some information." << endl;
	cout << "If you need read about, please print /“about/” to get this information again." << endl;
	cout << "If you need exit, please press ctrl+C." << endl;
	cout << "如果需要显示中文，请输入Chinese" << endl;
	cout << "-----------------------------------------------------------------------" << endl;
	cout << "Please enjoy your calculation!" << endl;
}

void printWelcomeChinese()
{
	cout << "-----------------简 易 多 功 能 高 精 度 计 算 器-----------------" << endl;
	cout << "如果需要使用帮助，则请在输入help" << endl;
	cout << "如果需要阅读关于，则请在输入about" << endl;
	cout << "如果需要退出程序，则请在输入ctrl+C" << endl;
	cout << "If you need to show in English, please print English" << endl;
	cout << "---------------------------------------------------------------" << endl;
	cout << "请输入运算表达式或变量赋值：" << endl;
}

void printHelpEnglish()
{
	cout << "-----------------------------------------------------------------" << endl;
	cout << "This is the instruction to the calculator user." << endl;
	cout << "Author: Yuwei Li" << endl;
	cout << endl;
	cout << "0. The constant value in this calculator:" << endl;
	cout << "E=2.718281828459" << endl;
	cout << "PI=3.1415926535898" << endl;
	cout << endl;
	cout << "Supported functions:" << endl;
	cout << "1. Basic mathematical calculation: + - * /" << endl;
	cout << "example-1.1:" << endl;
	cout << "3*4" << endl;
	cout << "12" << endl;
	cout << "example-1.2:" << endl;
	cout << "3.45*4.32" << endl;
	cout << "14.904" << endl;
	cout << endl;

	cout << "2. calculation with brackets: ( )" << endl;
	cout << "example-2.1:" << endl;
	cout << "(2+5)*9.9" << endl;
	cout << "69.3" << endl;
	cout << "example-2.2:" << endl;
	cout << "(4.5+6.8)*1.2" << endl;
	cout << "13.56" << endl;
	cout << endl;

	cout << "3. Definition with single char variable: x, y, z" << endl;
	cout << "example-3.1:" << endl;
	cout << "x=3" << endl;
	cout << "y=6" << endl;
	cout << "x+2*y" << endl;
	cout << "21" << endl;
	cout << "example-3.2:" << endl;
	cout << "x=1" << endl;
	cout << "y=x*2" << endl;
	cout << "x=3" << endl;
	cout << "x+x*y" << endl;
	cout << "9" << endl;
	cout << endl;

	cout << "4. Some single math functions:" << endl;
	cout << "example-4.1:" << endl;
	cout << "sqrt(3)" << endl;
	cout << "1.732051" << endl;
	cout << "example-4.2:" << endl;
	cout << "pow(2.4,3)" << endl;
	cout << "13.824000" << endl;
	cout << "Due to time limit, only several functions are supported:" << endl;
	cout << "sqrt(a), pow(a,b), abs(a), exp(a),\n"
			"random(), sin(x), cos(x), tan(x), ceil(x), floor(x), log(x)"
		 << endl;

	cout << "This calculator is still being improved. Due to time limit, the calculator supports these functions." << endl;
	cout << "-----------------------------------------------------------------" << endl;
}

void printAboutChinese(){
    cout << "-----------------------------------------------------------------" << endl;
	cout << "关于本程序：" << endl;
	cout << "本计算器为用于南方科技大学2022秋季学期CS205(C/C++程序设计)课程的第二次项目。" << endl;
	cout << "课程教授：于仕琪" << endl;
	cout << "作者：李昱纬" << endl;
	cout << "版本：1.0" << endl;
    cout << endl;
	cout << "致谢：" << endl;
	cout << "本程序部分借鉴了YeeTone Wang的开源项目" << endl;
	cout << "链接：https://github.com/YeeTone/CS205-2020Fall/tree/main/CS205Assignment2" << endl;
    cout << "以及Whitemeen太白的博客";
    cout << "链接：https://blog.csdn.net/demo_yo/article/details/112340758" << endl;
    cout << "-----------------------------------------------------------------" << endl;
}

void printHelpChinese()
{
	cout << "-----------------------------------------------------------------" << endl;
	cout << "使用帮助：" << endl;
	cout << "固定常数:  E=2.718281828459" << endl;
    cout << "         PI=3.1415926535898" << endl;
	cout << endl; 
	cout << "功能: 1.基本运算：+ - * / ^ ！|" << endl;

	cout << "     2.含括号的运算：( )[ ]{ }" << endl;

	cout << "     3.自定义变量:" << endl;
	cout << "          示例:" << endl;
	cout << "          x=3" << endl;
	cout << "          y=6" << endl;
	cout << "          x+2*y" << endl;
	cout << "          15" << endl;

	cout << "      4.简单的数学函数:" << endl;
	cout << "        sqrt(a), pow(a,b), abs(a), exp(a), floor(x), log(x),\n"
			"        random(), sin(x), cos(x), tan(x), ceil(x)" << endl;
	cout << "          示例:" << endl;
	cout << "          sqrt(3)" << endl;
	cout << "          1.732051" << endl;
	cout << "          示例:" << endl;
	cout << "          pow(2.4,3)" << endl;
	cout << "          13.824000" << endl;
	cout << endl;

	cout << "祝您使用愉快！如有建议，欢迎提出:)" << endl;
	cout << "----------------------------------------------------------------------" << endl;
}
