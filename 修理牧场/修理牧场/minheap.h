#pragma once

#include <vector>

using namespace std;

template <class T>
class MinHeap
{
public:
	//�����±�����
	T& operator[](const unsigned n)
	{
		return vec[n];
	}

	//��vector������С��
	MinHeap(vector<T>_vec)
	{
		//���ƶ�����
		vec = _vec;

		//�����һ�����ڵ㿪ʼ����
		int curPos = (vec.size() - 2) / 2;
		while (curPos >= 0)
		{
			//���µ����ɶ�
			siftDown(curPos, vec.size() - 1);

			//��ǰһ���ڵ��������
			curPos--;
		}
	}

	//��ȡ��Сֵ�����ò��Ƴ��ýڵ�
	bool remmoveMin(T& x)
	{
		if (!vec.size())		//�ѿգ�
			return false;
		x = vec[0];
		vec[0] = vec[vec.size() - 1];					//���Ԫ��������ڵ�
		
		auto eraseIt = vec.begin() + vec.size() - 1;	//ɾ�����һ��Ԫ��
		vec.erase(eraseIt);

		siftDown(0, vec.size() - 1);					//���µ���Ϊ��

		return true;
	}

	//����һ���µĽ��
	bool insert(const T& x)
	{
		vec.push_back(x);							//��Ԫ�ز�������ĩβ
		siftUp(vec.size() - 1);						//���ϵ���Ϊ��С��

		return true;
	}

	//��ȡ��ǰ��С�ѵ�����
	unsigned getSize()
	{
		return vec.size();
	}

private:
	//�»�������С��
	void siftDown(int start, int end)
	{
		if (!vec.size())
			return;
		int i = start, j = 2 * i + 1;		//j��i������Ůλ��
		T temp = vec[i];
		while (j <= end)
		{
			if (j<end&&vec[j]>vec[j + 1])	//��jָ����Ů��С��
				j++;

			if (temp <= vec[j])				//����Ҫ������
				break;
			else
			{
				vec[i] = vec[j];
				i = j;						//�»�
				j = 2 * j + 1;
			}
		}
		vec[i] = temp;
	}

	//���ϵ���Ϊ��С��
	void siftUp(int start)
	{
		int j = start, i = (j - 1) / 2;
		T temp = vec[j];
		while (j > 0)
		{
			if (vec[i] <= temp)		//���ڵ�ֵС��������
				break;
			else
			{
				vec[j] = vec[i];	//����
				j = i;
				i = (i - 1) / 2;
			}
		}
		vec[j] = temp;					//����
	}

	//��С�ѵ�����
	vector<T>vec;
};