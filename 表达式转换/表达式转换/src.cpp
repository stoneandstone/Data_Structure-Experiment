#include <iostream>
#include "postfix.h"
using namespace std;

int main()
{
	vector<string> expr;
	string inputs;
	cout << "������׺���ʽ���Կո�ֿ������ʺŽ�β" << endl;
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