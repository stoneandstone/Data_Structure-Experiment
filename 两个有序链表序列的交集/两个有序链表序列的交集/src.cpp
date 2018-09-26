#include <iostream>
#include <list>

using namespace std;

int main()
{
	list<int>s1, s2, ans;
	int input;
	cin >> input;
	while (input != -1);
	{
		s1.push_back(input);
		cin >> input;
	}
	cin >> input;
	while (input != -1);
	{
		s2.push_back(input);
		cin >> input;
	}
	auto it1 = s1.begin(), it2 = s2.begin();
	while (it1 != s1.end() || it2 != s2.end())
	{
		if (*it1 == *it2)
		{
			ans.push_back(*it1);
			it1++; it2++;
			continue;
		}
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

	if (ans.empty())
		cout << "NULL";
	else
	{
		for (auto num : ans)
		{
			cout << num;
		}
	}

	system("pausa");
	return 0;
}