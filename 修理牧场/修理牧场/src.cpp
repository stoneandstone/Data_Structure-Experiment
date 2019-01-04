#include <iostream>
#include "huffmanTree.h"

using namespace std;

class Node
{
public:

	bool operator>(const Node& obj)
	{
		return data > obj.data;
	}

	bool operator<(const Node& obj)
	{
		return data < obj.data;
	}

	bool operator<=(const Node& obj)
	{
		return data <= obj.data;
	}
	Node* left = nullptr;
	Node* right = nullptr;
	Node* add = this;

	int data;
	int length = 0;
};


int main()
{
	int num;
	cout << "请输入木头的数量" << endl;
	cin >> num;
	vector<Node>ivec(num);
	for (auto& r : ivec)
	{
		cin >> r.data;
		if (r.data < 0)
			return 0;
	}

	HuffmanTree<Node>huffmanTree(ivec);

	int sum = huffmanTree.calculateWPL();

	cout << sum;

	system("pause");
	return 0;
}