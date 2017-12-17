// Calculate.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "CALC.h"
int main()
{
	Calculator c;
	string ini;
	while (1)
	{
		cout << "输入要计算的表达式(以字母Q结束程序)：" << endl;
		cin >> ini;
		if (ini.length() == 1 && ini[0] == 'Q')
			break;
		c.calculate(ini);
		c.display();
	}
	return 0;
}

