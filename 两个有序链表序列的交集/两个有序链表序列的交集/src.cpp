#include <iostream>
#include <list>

using namespace std;

int main()
{
	list<int>s1, s2, ans;
	int input;
	//��ȡ������ֵ
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

	auto it1 = s1.begin(), it2 = s2.begin();

	while (*it1 != -1 && *it2 != -1)
	{
		if (*it1 == *it2)
			//�����ֵ��ȣ����������ans��ͬʱ��������������
		{
			ans.push_back(*it1);
			it1++; it2++;
			continue;
		}

		//�����ֵ����ȣ�����ֵС�ĵ�����
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
		//û����ȵ�Ԫ��
		cout << "NULL";
	else
	{
		for (auto num : ans)
		{
			cout << num << " ";
		}
	}

	system("pause");
	return 0;
}