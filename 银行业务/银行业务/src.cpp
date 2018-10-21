#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int num, curnum;
	cin >> num;


	queue<int>windowa, windowb;
	for (int i = 0; i < num; ++i)
	{
		cin >> curnum;
		if (curnum % 2)
			//奇数号去A窗口，偶数号去B窗口
		{
			windowa.push(curnum);
		}
		else
		{
			windowb.push(curnum);	
		}
	}
	while (!windowa.empty() || !windowb.empty())
	{
		if (!windowa.empty())
		{
			for (int i = 1; i <= 2; ++i)
			{
				curnum = windowa.front();
				windowa.pop();
				cout << curnum << " ";
				if (windowa.empty())
					break;
			}
		}

		if (!windowb.empty())
		{
			curnum = windowb.front();
			windowb.pop();
			cout << curnum;
			if (windowb.empty())
				break;
			cout << " ";
		}
	}

	while (!windowa.empty())
	{
		curnum = windowa.front();
		windowa.pop();
		cout << " " << curnum;
	}

	system("pause");
	return 0;
}