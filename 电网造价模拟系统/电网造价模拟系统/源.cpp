#include <iostream>
#include "minspantree.h"

vector<int> createVertices()
{
	int num;
	cout << "������ڵ����   ";
	cin >> num;
	vector<int>vertices(num);
	cout << "��������ڵ����ƣ��ڵ���СдӢ����ĸ��" << endl;
	for (auto& v : vertices)
	{
		char input;
		do
		{
			cin >> input;
			if ('a' > input || 'z' < input)
			{
				cout << "��������" << input << endl;
				continue;
			}
			v = input - 'a';
			break;
		} while (true);
	}

	return vertices;
}

vector<Edge> creatEdge(vector<int>vertices)
{
	int num;
	cout << "������߸���   ";
	cin >> num;
	vector<Edge>edges(num);
	for (auto& e : edges)
	{
		char node_1, node_2;
		int length;
		do
		{
			cin >> node_1 >> node_2 >> length;
			bool IsNode_1 = false, IsNode_2 = false;
			for (auto v : vertices)
			{
				if (v == node_1 - 'a')
					IsNode_1 = true;
				if (v == node_2 - 'a')
					IsNode_2 = true;
			}
			if (node_1 == node_2)
				IsNode_1 = IsNode_2 = false;
			if (IsNode_1&&IsNode_2)
				break;
		} while (true);

		e = Edge(length, node_1 - 'a', node_2 - 'a');
	}

	return edges;
}

int main()
{
	cout << "**********************************************************************" << endl;
	cout << "**                         �������ģ��ϵͳ                         **" << endl;
	cout << "**********************************************************************" << endl;

	cout << "**********************************************************************" << endl;
	cout << "                             ���������ڵ�                             " << endl;
	vector<int>vertices = createVertices();
	cout << "**********************************************************************" << endl;


	cout << "**********************************************************************" << endl;
	cout << "                             ���������ı�                             " << endl;
	vector<Edge>edges = creatEdge(vertices);

	cout << "**********************************************************************" << endl;
	cout << "                            ������С������                            " << endl;

	MinSpanTree minSpanTree = MinSpanTree(vertices, edges);
	if (minSpanTree.isSuccced())
		cout << endl << "                               �������" << endl;
	else
	{
		cout << endl << "                               ����ʧ��" << endl;
		system("pause");
		return 0;
	}
	cout << "**********************************************************************" << endl;
	cout << "                            �����С������                            " << endl;
	minSpanTree.OutPutTree();
	cout << "**********************************************************************" << endl;
	system("pause");
	return 0;
}