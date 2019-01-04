#pragma once

#include <vector>

using namespace std;

template <class T>
class MinHeap
{
public:
	//重载下标运算
	T& operator[](const unsigned n)
	{
		return vec[n];
	}

	//用vector构造最小堆
	MinHeap(vector<T>_vec)
	{
		//复制堆数组
		vec = _vec;

		//从最后一个父节点开始调整
		int curPos = (vec.size() - 2) / 2;
		while (curPos >= 0)
		{
			//向下调整成堆
			siftDown(curPos, vec.size() - 1);

			//往前一个节点继续调整
			curPos--;
		}
	}

	//获取最小值的引用并移除该节点
	bool remmoveMin(T& x)
	{
		if (!vec.size())		//堆空？
			return false;
		x = vec[0];
		vec[0] = vec[vec.size() - 1];					//最后元素填补到根节点
		
		auto eraseIt = vec.begin() + vec.size() - 1;	//删除最后一个元素
		vec.erase(eraseIt);

		siftDown(0, vec.size() - 1);					//重新调整为堆

		return true;
	}

	//插入一个新的结点
	bool insert(const T& x)
	{
		vec.push_back(x);							//新元素插入数组末尾
		siftUp(vec.size() - 1);						//向上调整为最小堆

		return true;
	}

	//获取当前最小堆的容量
	unsigned getSize()
	{
		return vec.size();
	}

private:
	//下滑调整最小堆
	void siftDown(int start, int end)
	{
		if (!vec.size())
			return;
		int i = start, j = 2 * i + 1;		//j是i的左子女位置
		T temp = vec[i];
		while (j <= end)
		{
			if (j<end&&vec[j]>vec[j + 1])	//让j指向子女中小者
				j++;

			if (temp <= vec[j])				//不需要调整了
				break;
			else
			{
				vec[i] = vec[j];
				i = j;						//下滑
				j = 2 * j + 1;
			}
		}
		vec[i] = temp;
	}

	//向上调整为最小堆
	void siftUp(int start)
	{
		int j = start, i = (j - 1) / 2;
		T temp = vec[j];
		while (j > 0)
		{
			if (vec[i] <= temp)		//父节点值小，不调整
				break;
			else
			{
				vec[j] = vec[i];	//调整
				j = i;
				i = (i - 1) / 2;
			}
		}
		vec[j] = temp;					//回送
	}

	//最小堆的内容
	vector<T>vec;
};