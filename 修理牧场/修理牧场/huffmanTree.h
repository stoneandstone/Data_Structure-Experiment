#pragma once

#include "minheap.h"
#include <vector>
#include <queue>


template <class T>
class HuffmanTree
{
public:
	//��vector����Huffman��
	HuffmanTree<T>(vector<T> tvec)
	{
		MinHeap<T> minHeap(tvec);
		T first, second;
		T* parent = nullptr;
		while (minHeap.getSize() > 1)
		{
			minHeap.remmoveMin(first);
			minHeap.remmoveMin(second);
			parent = merge(first, second);
			minHeap.insert(*parent);
		}

		root = parent;
		writrLength();
	}

	//�ϲ������ڵ��һ���ڵ㲢�����½ڵ��ָ��
	T* merge(T& node_1, T& node_2)
	{
		T* parent = new T;
		parent->left = node_1.add;
		parent->right = node_2.add;
		parent->data = node_1.data + node_2.data;
		return parent;
	}

	//д��ÿ���ڵ������ڵ�ĳ���
	void writrLength()
	{
		T t = *root;
		queue<T> q;
		q.push(t);
		while (!q.empty())
		{
			T cur = q.front();
			q.pop();
			if (cur.left)
			{
				cur.left->length = cur.length + 1;
				q.push(*(cur.left));
			}
			if (cur.right)
			{
				cur.right->length = cur.length + 1;
				q.push(*(cur.right));
			}
		}
	}

	//�����Ȩ·������
	int calculateWPL()
	{
		int wpl = 0;

		T t = *root;
		
		queue<T> q;
		q.push(t);
		while (!q.empty())
		{
			T cur = q.front();
			q.pop();
			if (!cur.left && !cur.right)
			{
				wpl += cur.data*cur.length;
			}
			if (cur.left)
			{
				q.push(*(cur.left));
			}
			if (cur.right)
			{
				q.push(*(cur.right));
			}
		}
		return wpl;
	}

private:
	//���ĸ��ڵ�
	T* root;
};

