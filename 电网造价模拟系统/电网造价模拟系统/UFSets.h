#pragma once

#include <vector>

using namespace std;

class UFSets
{
public:
	UFSets() = default;

	UFSets(int n)
	{
		parent = vector<int>(n, -1);
	}

	//��ѯx��������ͨ����
	int find(int x)
	{
		while (parent[x] >= 0)
		{
			x = parent[x];
		}
		return x;
	}

	//�ϲ�������ͨ����
	void setUnion(int root1, int root2)
	{
		parent[root1] += parent[root2];
		parent[root2] = root1;
	}

private:
	vector<int> parent;
};
