#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int num;
	cout << "请输入木头的数量" << endl;
	cin >> num;
	vector<int>ivec(num);
	for (auto& r : ivec)
	{
		cin >> r;
	}

	unsigned sum = 0;
	while (ivec.size() != 1)
	{
		sort(ivec.begin(), ivec.end(), [](int a, int b) {return a > b; });
		int temp = *(ivec.end() - 1) + *(ivec.end() - 2);
		sum += temp;
		//ivec.erase(ivec.end()-1);
		ivec.pop_back();
		ivec.at(ivec.size() - 1) = temp;
	}

	cout << sum;

	system("pause");
	return 0;
}