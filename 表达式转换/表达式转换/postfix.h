#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <stack>

using namespace std;

class PostFix
{
public:
	//���캯��ͨ����׺���ʽ�������׺���ʽ
	PostFix(vector<string>infix)
	{
		infix.push_back("#");
		stack<string>oper;
		oper.push("#");

		auto c = infix.begin();
		while (!oper.empty() && c != infix.end())
		{
			int num = atoi(c->c_str());
			if (num)
			{
				postfix.push_back(to_string(num));
				c++;
			}
			else
			{
				auto top_op = oper.top();

				if (icp(*c) > isp(top_op))		//��������������ȼ���
				{
					oper.push(*c);				//��ջ
					c++;						//������һ��Ԫ��
				}
				else if (icp(*c) < isp(top_op))	//��������������ȼ���
				{
					postfix.push_back(oper.top());
					oper.pop();					//��ջ
				}
				else if (icp(*c) == isp(top_op))
				{

					oper.pop();
					if (top_op == "(")
						c++;
				}

			}
		}
	}

	//���������ɺ�ĺ�׺���ʽ
	void output()
	{
		for (auto r : postfix)
		{
			cout << r << " ";
		}
	}

private:

	//ջ�����ȼ���������ߣ�һ����ֱ�ӽ�ջ
	int isp(const string& op)
	{
		if (op == "#")
			return 0;
		else if (op == "+" || op == "-")
			return 3;
		else if (op == "*" || op == "/" || op == "%")
			return 5;
		else if (op == "(")
			return 1;
		else if (op == ")")
			return 6;

	}

	//ջ�����ȼ���
	int icp(const string& op)
	{
		if (op == "#")
			return 0;
		else if (op == "+" || op == "-")
			return 2;
		else if (op == "*" || op == "/" || op == "%")
			return 4;
		else if (op == "(")
			return 6;
		else if (op == ")")
			return 1;
	}

	//��׺���ʽ
	vector<string>postfix;
};