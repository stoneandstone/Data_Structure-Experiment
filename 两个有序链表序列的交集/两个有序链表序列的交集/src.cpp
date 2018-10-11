#include <iostream>
#include <list>

using namespace std;

void solve(list<int>& s1, list<int>& s2, list<int>& ans)
{
	auto it1 = s1.begin(), it2 = s2.begin();

	while (*it1 != -1 && *it2 != -1)
		//当有一个链表检索至链表尾，结束循环
	{
		if (*it1 == *it2)
			//两结点值相等，将结果存入ans，同时递增两个迭代器
		{
			ans.push_back(*it1);
			it1++; it2++;
			continue;
		}

		//两结点值不相等，递增值小的迭代器
		else if (*it1 < *it2)
		{
			it1++;
			continue;
		}
		else
		{
			it2++;
			continue;
		}
	}

}

int main()
{
	list<int>s1, s2, ans;
	int input;
	//读取两链表值
	do
	{
		cin >> input;
		s1.push_back(input);
	} while (input != -1);
	
	do
	{
		cin >> input;
		s2.push_back(input);
	} while (input != -1);

	solve(s1, s2, ans);

	if (ans.empty())
		//没有相等的元素
		cout << "NULL";
	else
	{
		for (auto num : ans)
		{
			cout << num;

			//输出最后一位数字时，不输出多余的空格
			if (num != *ans.rbegin())
				cout << " ";
		}
	}

	system("pause");
	return 0;
}