// Calculate.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "CALC.h"
int main()
{
	Calculator c;
	string ini;
	while (1)
	{
		cout << "����Ҫ����ı��ʽ(����ĸQ��������)��" << endl;
		cin >> ini;
		if (ini.length() == 1 && ini[0] == 'Q')
			break;
		c.calculate(ini);
		c.display();
	}
	return 0;
}

