#include <iostream>
#include <queue>

using namespace std;

int main()
{

	int num, curnum;
	cin >> num;


	queue<int>window_a, window_b;

	//输入各个顾客并分别调至对应的窗口
	for (int i = 0; i < num; ++i)
	{
		cin >> curnum;
		if (curnum % 2)
		//奇数号去A窗口，偶数号去B窗口
			window_a.push(curnum);
		else
			window_b.push(curnum);	
	}


	//处理业务过程，处理完所有顾客才会退出循环
	while (!window_a.empty() || !window_b.empty())
	{
		if (!window_a.empty())
		{
			for (int i = 1; i <= 2; ++i)
			{
				curnum = window_a.front();
				window_a.pop();
				cout << curnum << " ";
				if (window_a.empty())
					break;
			}
		}

		if (!window_b.empty())
		{
			curnum = window_b.front();
			window_b.pop();
			cout << curnum << " ";
		}
	}

	cout << '\b';



	return 0;
}