#include <iostream>
#include "postfix.h"
using namespace std;

int main()
{
	vector<string> expr;
	string inputs;
	cout << "输入中缀表达式，以空格分开，以问号结尾" << endl;
	while (true)
	{
		cin >> inputs;
		if (inputs == "?")
			break;
		expr.push_back(inputs);
	}
	
	PostFix postFix(expr);
	postFix.output();

	system("pause");
}