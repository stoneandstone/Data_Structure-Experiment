#pragma once

#include "minheap.h"
#include <vector>
#include <queue>


template <class T>
class HuffmanTree
{
public:
	//用vector构建Huffman树
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

	//合并两个节点成一个节点并返回新节点的指针
	T* merge(T& node_1, T& node_2)
	{
		T* parent = new T;
		parent->left = node_1.add;
		parent->right = node_2.add;
		parent->data = node_1.data + node_2.data;
		return parent;
	}

	//写入每个节点距离根节点的长度
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

	//计算带权路径长度
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
	//树的根节点
	T* root;
};

