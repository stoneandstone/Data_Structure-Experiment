#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <stack>

using namespace std;

class PostFix
{
public:
	//构造函数通过中缀表达式来构造后缀表达式
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

				if (icp(*c) > isp(top_op))		//新输入操作符优先级高
				{
					oper.push(*c);				//进栈
					c++;						//处理下一个元素
				}
				else if (icp(*c) < isp(top_op))	//新输入操作符优先级低
				{
					postfix.push_back(oper.top());
					oper.pop();					//退栈
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

	//输出构造完成后的后缀表达式
	void output()
	{
		for (auto r : postfix)
		{
			cout << r << " ";
		}
	}

private:

	//栈内优先级数，（最高，一出现直接进栈
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

	//栈外优先级数
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

	//后缀表达式
	vector<string>postfix;
};