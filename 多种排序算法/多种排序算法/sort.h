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
//	//���캯�����ڲ�ʵ��XX����
//	XXSort(vector<Type>_ivec) :ivec(_ivec)
//	{
//		auto start = clock();
//		///�˴�ʵ��XX����
//		auto end = clock();
//		time = end - start;
//	}
//
//	//�����������Ҫ��ʱ��ͽ�������
//	void outputMess()
//	{
//		cout << "ð������" << endl;
//		cout << "����ʱ��: " << time << "ms" << endl;
//		cout << "��������: " << swapTimes << endl;
//	}
//
//private:
//	//XXXXX��������Ҫ��˽�к���
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
		cout << "ð������" << endl;
		cout << "����ʱ��: " << time << "ms" << endl;
		cout << "��������: " << swapTimes << endl;
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
			int cur_min = i;//��¼��Сֵ���±�
			for (unsigned j = i + 1; j < ivec.size(); ++j)
			{
				//��Ҫ������Сֵ
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
		cout << "ѡ������" << endl;
		cout << "����ʱ��: " << time << "ms" << endl;
		cout << "��������: " << swapTimes << endl;
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
		cout << "ֱ�Ӳ�������" << endl;
		cout << "����ʱ��: " << time << "ms" << endl;
		cout << "��������: " << swapTimes << endl;
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
		cout << "ϣ������" << endl;
		cout << "����ʱ��: " << time << "ms" << endl;
		cout << "��������: " << swapTimes << endl;
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
		cout << "��������" << endl;
		cout << "����ʱ��: " << time << "ms" << endl;
		cout << "��������: " << swapTimes << endl;
	}

private:

	void Sort(const int left, const int right)
		//��left��right�ݹ��������
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
		//�����ɶ�
		int curSize = ivec.size();
		int curPos = (curSize - 2) / 2;

		while (curPos >= 0)
		{
			siftDown(curPos, curSize - 1);
			curPos--;
		}


		for (int i = ivec.size() - 1; i > 0; --i)
		{

			//����0��i
			swap(ivec[0], ivec[i]);
			swapTimes++;

			siftDown(0, i - 1);
		}

		auto end = clock();
		time = end - start;
	}

	void outputMess()
	{
		cout << "������" << endl;
		cout << "����ʱ��: " << time << "ms" << endl;
		cout << "��������: " << swapTimes << endl;
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
		cout << "�鲢����" << endl;
		cout << "����ʱ��: " << time << "ms" << endl;
		cout << "�Ƚϴ���: " << compareTimes << endl;
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
		//����β�ڵ㣬data-1����β��link����ͷ�ڵ�
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
			//������ͷ 
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
		cout << "��������" << endl;
		cout << "����ʱ��: " << time << "ms" << endl;
		cout << "��������: " << swapTimes << endl;
	}

private:
	vector<Type>ivec;
	clock_t time;
	int swapTimes;
	int radix;
};