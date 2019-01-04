#pragma once

#include <vector>

using namespace std;

template <class T>
class MinHeap
{
public:
	//重载下表运算
	T& operator[](const unsigned n)
	{
		return vec[n];
	}

	//用数组构造最小堆
	MinHeap(vector<T>_vec)
	{
		vec = _vec;
		curSize = vec.size();

		int curPos = (curSize - 2) / 2;
		while (curPos >= 0)
		{
			siftDown(curPos, curSize - 1);
			curPos--;
		}
	}

	//获取最小节点并删除
	bool remmoveMin(T& x)
	{
		if (!curSize)
			return false;
		x = vec[0];
		vec[0] = vec[curSize - 1];
		curSize--;
		vec.erase(vec.end() - 1);

		siftDown(0, curSize - 1);

		return true;
	}

	//插入一个新节点
	bool insert(const T& x)
	{
		vec.push_back(x);
		siftUp(curSize);
		curSize++;
		return true;
	}

	//判断堆空
	bool empty()
	{
		return vec.empty();
	}
private:
	void siftDown(int start, int end)
	{
		if (!vec.size())
			return;
		int i = start, j = 2 * i + 1;
		T temp = vec[i];
		while (j <= end)
		{
			if (j<end&&vec[j]>vec[j + 1])
				j++;

			if (temp <= vec[j])
				break;
			else
			{
				vec[i] = vec[j];
				i = j;
				j = 2 * j + 1;
			}
		}
		vec[i] = temp;
	}

	void siftUp(int start)
	{
		int j = start, i = (j - 1) / 2;
		T temp = vec[j];
		while (j > 0)
		{
			if (vec[i] <= temp)
				break;
			else
			{
				vec[j] = vec[i];
				j = i;
				i = (i - 1) / 2;
			}
		}
		vec[j] = temp;
	}

	int curSize;
	vector<T>vec;
};