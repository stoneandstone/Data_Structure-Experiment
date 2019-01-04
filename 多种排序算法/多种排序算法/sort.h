#pragma once

#include <iostream>
#include <vector>
#include <ctime>
#include <random>

using namespace std;

//template<class Type>
//class XXSort
//{
//public:
//	//构造函数，内部实现XX排序
//	XXSort(vector<Type>_ivec) :ivec(_ivec)
//	{
//		auto start = clock();
//		///此处实现XX排序
//		auto end = clock();
//		time = end - start;
//	}
//
//	//输出排序所需要的时间和交换次数
//	void outputMess()
//	{
//		cout << "冒泡排序" << endl;
//		cout << "运行时间: " << time << "ms" << endl;
//		cout << "交换次数: " << swapTimes << endl;
//	}
//
//private:
//	//XXXXX排序所需要的私有函数
//	vector<Type>ivec;
//	clock_t time;
//	long long swapTimes;
//};

template<class Type>
class BubbleSort
{
public:
	BubbleSort(vector<Type>_ivec) :ivec(_ivec)
	{
		auto start = clock();
		for (unsigned i = 0; i < ivec.size() - 1; ++i)
		{
			for (unsigned j = 0; j < ivec.size() - i - 1; ++j)
			{
				if (ivec[j] > ivec[j + 1])
				{
					swap(ivec[j], ivec[j + 1]);
					++swapTimes;
				}
			}
		}
		auto end = clock();
		time = end - start;
	}

	void outputMess()
	{
		cout << "冒泡排序" << endl;
		cout << "运行时间: " << time << "ms" << endl;
		cout << "交换次数: " << swapTimes << endl;
	}

private:
	vector<Type>ivec;
	clock_t time;
	long long swapTimes;
};

template<class Type>
class SelectionSort
{
public:
	SelectionSort(vector<Type>_ivec) :ivec(_ivec)
	{
		auto start = clock();
		for (unsigned i = 0; i < ivec.size(); ++i)
		{
			int cur_min = i;//记录最小值的下标
			for (unsigned j = i + 1; j < ivec.size(); ++j)
			{
				//需要更新最小值
				if (ivec[cur_min] > ivec[j])
				{
					cur_min = j;
				}
			}
			swap(ivec[cur_min], ivec[i]);
			swapTimes++;
		}
		auto end = clock();
		time = end - start;
	}

	void outputMess()
	{
		cout << "选择排序" << endl;
		cout << "运行时间: " << time << "ms" << endl;
		cout << "交换次数: " << swapTimes << endl;
	}

private:
	vector<Type>ivec;
	clock_t time;
	long long swapTimes;
};

template<class Type>
class DirectlyInsertSort
{
public:
	DirectlyInsertSort(vector<Type>_ivec) :ivec(_ivec)
	{
		auto start = clock();
		for (unsigned i = 1; i < ivec.size(); ++i)
		{
			if (ivec[i - 1] < ivec[i])
				continue;

			Type temp = ivec[i];
			int add = 0;
			for (int j = i - 1; j >= 1; j--)
			{
				if (temp >= ivec[j - 1])
				{
					add = j;
					break;
				}
			}

			for (int i2 = i - 1; i2 >= add; i2--)
			{
				ivec[i2 + 1] = ivec[i2];
				++swapTimes;
			}
			ivec[add] = temp;
		}
		auto end = clock();
		time = end - start;
	}

	void outputMess()
	{
		cout << "直接插入排序" << endl;
		cout << "运行时间: " << time << "ms" << endl;
		cout << "交换次数: " << swapTimes << endl;
	}

private:
	vector<Type>ivec;
	clock_t time;
	long long swapTimes;
};

template<class Type>
class ShellSort
{
public:
	ShellSort(vector<Type>_ivec) :ivec(_ivec)
	{
		auto start = clock();
		for (int gap = ivec.size() / 2; gap > 0; gap /= 2)
		{
			for (unsigned i = gap; i < ivec.size(); ++i)
			{
				int j = i;
				while (j - gap >= 0 && ivec[j - gap] > ivec[j])
				{
					swap(ivec[j - gap], ivec[j]);
					++swapTimes;
					j -= gap;
				}
			}
		}
		auto end = clock();
		time = end - start;
	}

	void outputMess()
	{
		cout << "希尔排序" << endl;
		cout << "运行时间: " << time << "ms" << endl;
		cout << "交换次数: " << swapTimes << endl;
	}

private:
	vector<Type>ivec;
	clock_t time;
	long long swapTimes;
};

template<class Type>
class QuickSort
{
public:

	QuickSort(vector<Type>_ivec) :ivec(_ivec)
	{
		auto start = clock();
		Sort(0, ivec.size() - 1);
		auto end = clock();
		time = end - start;
	}

	void outputMess()
	{
		cout << "快速排序" << endl;
		cout << "运行时间: " << time << "ms" << endl;
		cout << "交换次数: " << swapTimes << endl;
	}

private:

	void Sort(const int left, const int right)
		//在left和right递归进行排序
	{
		if (left < right)
		{
			int pivotpos = Partition(left, right);
			Sort(left, pivotpos - 1);
			Sort(pivotpos + 1, right);
		}
	}

	int Partition(const int low, const int high)
	{
		int pivotPos = low;
		Type pivot = ivec[low];
		for (int i = low + 1; i <= high; i++)
		{
			if (ivec[i] < pivot&&++pivotPos != i)
			{
				swap(ivec[pivotPos], ivec[i]);
				swapTimes++;
			}
		}
		swap(ivec[low], ivec[pivotPos]);
		swapTimes++;

		return pivotPos;
	}


	vector<Type>ivec;
	clock_t time;
	int swapTimes;
};

template<class Type>
class HeapSort
{
public:
	HeapSort(vector<Type>_ivec) :ivec(_ivec)
	{
		auto start = clock();
		//调整成堆
		int curSize = ivec.size();
		int curPos = (curSize - 2) / 2;

		while (curPos >= 0)
		{
			siftDown(curPos, curSize - 1);
			curPos--;
		}


		for (int i = ivec.size() - 1; i > 0; --i)
		{

			//交换0和i
			swap(ivec[0], ivec[i]);
			swapTimes++;

			siftDown(0, i - 1);
		}

		auto end = clock();
		time = end - start;
	}

	void outputMess()
	{
		cout << "堆排序" << endl;
		cout << "运行时间: " << time << "ms" << endl;
		cout << "交换次数: " << swapTimes << endl;
	}

private:
	void siftDown(int start, int end)
	{
		int i = start, j = 2 * i + 1;
		Type temp = ivec[i];
		while (j <= end)
		{
			if (j < end&&ivec[j] < ivec[j + 1])
				j++;

			if (temp >= ivec[j])
				break;
			else
			{
				ivec[i] = ivec[j];
				swapTimes++;
				i = j;
				j = 2 * j + 1;
			}
		}
		ivec[i] = temp;
		swapTimes++;
	}


	vector<Type>ivec;
	clock_t time;
	int swapTimes;
};

template<class Type>
class MergeSort
{
public:
	MergeSort(vector<Type>_ivec) :ivec(_ivec)
	{
		auto start = clock();

		msort(0, ivec.size() - 1);

		auto end = clock();
		time = end - start;
	}

	void outputMess()
	{
		cout << "归并排序" << endl;
		cout << "运行时间: " << time << "ms" << endl;
		cout << "比较次数: " << compareTimes << endl;
	}

private:

	void msort(int left, int right)
	{
		if (left >= right)
			return;
		int mid = (left + right) / 2;
		msort(left, mid);
		msort(mid + 1, right);

		merge(left, mid, right);
	}
	void merge(int left, int mid, int right)
	{
		vector<Type>temp(ivec);
		int s1 = left, s2 = mid + 1, t = left;
		while (s1 <= mid && s2 <= right)
		{
			if (temp[s1] <= temp[s2])
			{
				ivec[t] = temp[s1];
				t++; s1++;
			}
			else
			{
				ivec[t] = temp[s2];
				t++; s2++;
			}
			compareTimes++;
		}
		while (s1 <= mid)
		{
			ivec[t] = temp[s1];
			t++; s1++;
		}
		while (s2 <= right)
		{
			ivec[t] = temp[s2];
			t++; s2++;
		}
	}

	vector<Type>ivec;
	clock_t time;
	int compareTimes;
};

template<class Type>
class RadixSort
{
public:
	RadixSort(vector<Type>_ivec,int _radix) :ivec(_ivec),radix(_radix)
	{
		auto start = clock();

		class Node
		{
		public:
			Type data;
			int link;
		};

		vector<Type> front(radix, -1), rear(radix, -1);
		vector<Node>nvec(ivec.size());
		for (int i = 0; i < ivec.size(); i++)
		{
			nvec[i].data = ivec[i];
			nvec[i].link = i + 1;
		}
		//插入尾节点，data-1代表尾，link代表头节点
		nvec.push_back({ -1,0 });

		Type max = ivec[0];
		for (auto i : ivec)
		{
			if (i > max)
				max = i;
		}
		int d = ceil(log(max) / log(radix));
		int current = 0;
		int i, j, k, last;
		for (i = d; i >= 1; i--)
		{
			front = vector<Type>(radix, -1);

			while (current != ivec.size())
			{
				k = static_cast<int>(nvec[current].data / pow(radix, d - i)) % radix;
				if (front[k] == -1)
					front[k] = current;
				else
					nvec[rear[k]].link = current;

				rear[k] = current;
				current = nvec[current].link;
			}
			j = 0;
			while (front[j] == -1)
			{
				j++;
			}
			//新链表头 
			nvec[ivec.size()].link = current = front[j];
			last = rear[j];
			for (k = j + 1; k < radix; k++)
			{
				if (front[k] != -1)
				{
					nvec[last].link = front[k];
					last = rear[k];
				}
			}
			nvec[last].link = ivec.size();
		}

		current = nvec[ivec.size()].link;
		for (auto&i : ivec)
		{
			i = nvec[current].data;
			current = nvec[current].link;
		}

		auto end = clock();
		time = end - start;
	}

	void outputMess()
	{
		cout << "基数排序" << endl;
		cout << "运行时间: " << time << "ms" << endl;
		cout << "交换次数: " << swapTimes << endl;
	}

private:
	vector<Type>ivec;
	clock_t time;
	int swapTimes;
	int radix;
};