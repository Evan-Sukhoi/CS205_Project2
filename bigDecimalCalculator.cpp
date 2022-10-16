#include <bits/stdc++.h>
#include "bigDecimalCalculator.hpp"
using namespace std;

// double add(string num1,string num2);
// double minus(string num1,string num2);

int point(string &num1, string &num2)
{
	//查找小数点
	int dot1 = num1.find('.');
	int dot2 = num2.find('.');
	//删除小数点，并将dot改为小数点后的位数
	if (dot1 != string::npos)
	{
		num1.erase(dot1, 1);
		dot1 = num1.length() - dot1;
	}
	else
	{
		dot1 = 0;
	}
	if (dot2 != string::npos)
	{
		num2.erase(dot2, 1);
		dot2 = num2.length() - dot2;
	}
	else
	{
		dot2 = 0;
	}
	//补齐小数点后面的0
	if (dot1 > dot2)
	{
		num2.append(dot1 - dot2, '0');
	}
	else if (dot1 < dot2)
	{
		num1.append(dot2 - dot1, '0');
	}
	//计算较大的小数点位置
	return dot1 > dot2 ? dot1 : dot2;
}

string Add(string num1, string num2)
{
	bool negative = false;
	if (num1[0] == '-')
	{
		if (num2[0] == '-')
		{
			num1.erase(0, 1);
			num2.erase(0, 1);
			negative = true; //(-a) + (-b) = - (a + b)
		}
		else
		{
			num1.erase(0, 1);
			return Minus(num2, num1); //(-a) + b = b - a
		}
	}
	else if (num2[0] == '-')
	{
		num2.erase(0, 1);
		return Minus(num1, num2); // a + (-b) = a - b
	}

	int dot = point(num1, num2);

	//分别获取位数并将每一位存入整形数组中
	int n = num1.length(), m = num2.length(); // length()函数用于获取存储字符串长度
	int max = (m > n ? m : n) + 1;			  //两个数相加  位数不会超过较大的数的位数+1
	int a[max], b[max], c[max];				  //每一位都初始化为0
	// int a[max]={0},b[max]={0},c[max]={0};//每一位都初始化为0
	int i, j;
	for (i = 0; i < max; i++) //初始化
		a[i] = 0;
	for (i = 0; i < max; i++) //初始化
		b[i] = 0;
	for (i = 0; i < max; i++) //初始化
		c[i] = 0;

	//翻转存储到int数组a中
	for (i = 0, j = n - 1; i < n; i++, j--)
		a[i] = num1[j] - '0';
	for (i = 0, j = m - 1; i < m; i++, j--)
		b[i] = num2[j] - '0';

	/*********上面都是利用数组储存大数,下面开始模拟大数加法*************/

	for (i = 0; i < max; i++)
	{
		c[i] += a[i] + b[i];
		if (c[i] >= 10)
		{				   //进位处理
			c[i + 1] += 1; //进10位
			c[i] %= 10;	   //留下个位
		}
	}

	i = max - 1;
	while (c[i] == 0 && i != 0) //去除答案数组c中高位上的0
		i--;

	string result = "";
	if (negative)
		result.append("-");
	while (i >= 0)
	{ // c[i]是从高位向前看第一个不为0的数
		result += to_string(c[i--]);
		//小数点
		if (i == dot - 1 && dot != 0)
			result += ".";
	}

	return result;
}

string Minus(string num1, string num2)
{
	if (num1[0] == '-')
	{
		if (num2[0] == '-')
		{
			num1.erase(0, 1);
			num2.erase(0, 1);
			return Minus(num2, num1); //(-a) - (-b) = b-a
		}
		else
		{
			num2.insert(0, "-");
			return Add(num1, num2); //(-a) - b = (-a) + (-b)
		}
	}
	else if (num2[0] == '-')
	{
		num2.erase(0, 1);
		return Add(num1, num2); // a - (-b) = a + b
	}

	while (num1[0] == '0') //去除num1中最高有效位前的0
		num1.erase(0, 1);

	while (num2[0] == '0') //去除num2中最高有效位前的0
		num2.erase(0, 1);

	int dot = point(num1, num2);

	//分别获取位数并将每一位存入整形数组中
	int n = num1.length(), m = num2.length();
	int max = m > n ? m : n;	//两个数相减  位数不会超过较大的数的位数
	int a[max], b[max], c[max]; //每一位都要初始化为0
	bool negative = false;

	//将位数较大的数放在第一个 我们始终用绝对值较大的数减去绝对值较小的数
	if (n < m)
	{
		string temp = num1;
		num1 = num2;
		num2 = temp;
		int tmp = n;
		n = m;
		m = tmp;
		negative = true;
	} //两个数长度一样，这个时候，需要判断哪个数更大，如果被减数小于减数，那么结果是负数，同时两个字符串交换顺序，大的数减小的数
	else if (num1.size() == num2.size())
	{
		int len = num1.size();
		for (int i = 0; i < len; ++i)
		{
			if (num1[i] == num2[i])
				continue;
			if (num1[i] > num2[i])
				break;
			if (num1[i] < num2[i])
			{
				string temp = num1;
				num1 = num2;
				num2 = temp;
				negative = true;
			}
		}
	}

	// int a[max]={0},b[max]={0},c[max]={0};//每一位都初始化为0 不这样做的理由同上
	int i, j;
	for (i = 0; i < max; i++) //初始化
		a[i] = 0;
	for (i = 0; i < max; i++) //初始化
		b[i] = 0;
	for (i = 0; i < max; i++) //初始化
		c[i] = 0;

	// num1 - n位 - 将num1字符串存储的大数翻转存储(a[0]存储个位,a[1]存储十位)到int数组a中
	for (i = 0, j = n - 1; i < n; i++, j--)
		a[i] = num1[j] - '0';
	// num2 - m位
	for (i = 0, j = m - 1; i < m; i++, j--)
		b[i] = num2[j] - '0';

	/********以上都是在存储大数,以下开始模拟减法*********/

	for (i = 0; i < max; i++)
	{
		//处理借位
		if (a[i] < b[i])
		{
			a[i] += 10;
			a[i + 1]--;
		}

		c[i] = a[i] - b[i];
	}

	i = max - 1;
	while (c[i] == 0 && i != 0 && i > dot) //去除答案数组c中高位上的0
		i--;

	string result = "";
	if (negative)
		result.append("-");

	while (i >= 0)
	{
		result += to_string(c[i--]);
		//小数点
		if (i == dot - 1 && i != -1)
			result += ".";
	}

	return result;
}

// High precision multiplication
string Mul(string num1, string num2)
{
	//判断结果正负
	bool negative = false;
	if (num1[0] == '-')
	{
		if (num2[0] == '-')
		{
			num1.erase(0, 1);
			num2.erase(0, 1);
			negative = false; // -a * -b = a * b
		}
		else
		{
			num1.erase(0, 1); // -a * b = -(a * b)
			negative = true;
		}
	}
	else if (num2[0] == '-')
	{
		num2.erase(0, 1);
		negative = true; // a * -b = -(a * b)
	}

	//查找小数点
	int dot1 = num1.find('.');
	int dot2 = num2.find('.');
	//删除小数点，并将dot改为小数点后的位数
	if (dot1 != string::npos)
	{
		num1.erase(dot1, 1);
		dot1 = num1.length() - dot1;
	}
	else
	{
		dot1 = 0;
	}
	if (dot2 != string::npos)
	{
		num2.erase(dot2, 1);
		dot2 = num2.length() - dot2;
	}
	else
	{
		dot2 = 0;
	}
	//计算结果的小数点后的位数
	int dot = dot1 + dot2;

	while (num1[0] == '0') //去除num1中最高有效位前的0
		num1.erase(0, 1);

	while (num2[0] == '0') //去除num2中最高有效位前的0
		num2.erase(0, 1);

	int n = num1.length(), m = num2.length();
	int a[n], b[m]; //定义两个整形数组用于待会存储这两个大数的每一位

	int i, j;
	//用整形数组从低位到高位存储这两个大数
	for (i = 0, j = n - 1; i < n; i++, j--)
		a[i] = num1[j] - '0';
	for (i = 0, j = m - 1; i < m; i++, j--)
		b[i] = num2[j] - '0';

	/*******到此为止以上都是大数的保存,下面将模拟大数乘法的运算***********/

	//定义第三个数组来存储结果
	int c[3000] = {0};
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
		{
			c[i + j] += a[i] * b[j];
		}

	//处理进位的情况
	for (i = 0; i < n + m; i++)
	{
		if (c[i] >= 10)
		{
			c[i + 1] += c[i] / 10;
			c[i] %= 10;
		}
	}

	i = m + n;
	while (c[i] == 0 && i != 0 && i > dot) //去除答案数组c中高位上的0
		i--;

	string result = "";
	if (negative)
		result.append("-");

	while (i >= 0)
	{
		result += to_string(c[i--]);
		//小数点
		if (i == dot - 1 && i != -1)
			result += ".";
	}
	return result;
}

int substract(int a[], int b[], int n, int m);

string Division(string num1, string num2)
{
	//判断结果正负
	bool negative = false;
	if (num1[0] == '-')
	{
		if (num2[0] == '-')
		{
			num1.erase(0, 1);
			num2.erase(0, 1);
			negative = false; // -a / -b = a / b
		}
		else
		{
			num1.erase(0, 1); // -a / b = -(a / b)
			negative = true;
		}
	}
	else if (num2[0] == '-')
	{
		num2.erase(0, 1);
		negative = true; // a / -b = -(a / b)
	}

	//查找小数点
	int dot1 = num1.find('.');
	int dot2 = num2.find('.');
	//删除小数点，并将dot改为小数点后的位数
	if (dot1 != string::npos)
	{
		num1.erase(dot1, 1);
		dot1 = num1.length() - dot1;
	}
	else
	{
		dot1 = 0;
	}
	if (dot2 != string::npos)
	{
		num2.erase(dot2, 1);
		dot2 = num2.length() - dot2;
	}
	else
	{
		dot2 = 0;
	}
	//计算结果的小数点后的位数
	int dot = abs(dot1 - dot2 + 3);

	//在num1后添加3个0，实现高精度除法运算
	for (int i = 0; i < 3; i++)
		num1 += "0";

	while (num2[0] == '0') //去除num2中最高有效位前的0
		num2.erase(0, 1);


	int n = num1.length(), m = num2.length();
	int c[10001];

	if (n < m)
		return 0; //除不尽

	int diff = n - m;

	//定义两个数组去翻转存储这两个大数.a[]除数，b[]被除数，c[]商
	int a[n] = {0}, b[n] = {0}, i, j;
	for (i = 0, j = n - 1; j >= 0; i++, j--)
		a[i] = num1[j] - '0';
	for (i = diff, j = m - 1; j >= 0; i++, j--) //注意这里b的存储方式是将b扩大了10^diff倍
		b[i] = num2[j] - '0';

	for (i = 0; i < n; i++) //数组c全部初始化为0
		c[i] = 0;

	int temp; //接收substract 函数返回参数
	m = n;
	for (i = 0; i <= diff; i++)
		while ((temp = substract(a, b + i, n, m - i)) >= 0) // b+i相当于b/(i^10)
		{
			n = temp;
			c[diff - i]++; 
		}

	//计算长度
	for (i = diff; c[i] == 0 && i >= 0; i--);
	int lenc = i + 1;

	i = lenc;
	while (c[i] == 0 && i != 0 && i > dot) //去除答案数组c中高位上的0
		i--;

	string result = "";
	if (negative)
		result.append("-");

	while (i >= 0)
	{
		result += to_string(c[i--]);
		//小数点
		if (i == dot - 1 && i != -1)
			result += ".";
	}
	return result;
}

/*
 参数:
	a[] 减数
	b[] 被减数
	n 减数长度
	m 被减数长度
  返回值:
	结果的长度
	>
*/
int substract(int a[], int b[], int n, int m)
{	//判断 a > b
	if (n < m)
		return -1;
	int i;
	if (n == m)						 
		for (i = n - 1; i >= 0; i--)
		{
			if (a[i] > b[i]) 
				break;
			else if (a[i] < b[i])
				return -1; 
		}

	for (i = 0; i <= n - 1; i++)
	{
		a[i] -= b[i];
		if (a[i] < 0)
		{
			a[i + 1]--;
			a[i] += 10;
		}
	}

	for (i = n - 1; i >= 0; i--) // 查找结果的最高位
	{
		if (a[i])			//最高位第一个不为0
			return (i + 1); //得到位数并返回
	}
	return 0; //两数相等的时候返回0
}
