#include <iostream>
#include "minspantree.h"

vector<int> createVertices()
{
	int num;
	cout << "请输入节点个数   ";
	cin >> num;
	vector<int>vertices(num);
	cout << "请输入各节点名称（节点是小写英文字母）" << endl;
	for (auto& v : vertices)
	{
		char input;
		do
		{
			cin >> input;
			if ('a' > input || 'z' < input)
			{
				cout << "重新输入" << input << endl;
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
	cout << "请输入边个数   ";
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
	cout << "**                         电网造价模拟系统                         **" << endl;
	cout << "**********************************************************************" << endl;

	cout << "**********************************************************************" << endl;
	cout << "                             创建电网节点                             " << endl;
	vector<int>vertices = createVertices();
	cout << "**********************************************************************" << endl;


	cout << "**********************************************************************" << endl;
	cout << "                             创建电网的边                             " << endl;
	vector<Edge>edges = creatEdge(vertices);

	cout << "**********************************************************************" << endl;
	cout << "                            构造最小生成树                            " << endl;

	MinSpanTree minSpanTree = MinSpanTree(vertices, edges);
	if (minSpanTree.isSuccced())
		cout << endl << "                               构造完成" << endl;
	else
	{
		cout << endl << "                               构造失败" << endl;
		system("pause");
		return 0;
	}
	cout << "**********************************************************************" << endl;
	cout << "                            输出最小生成树                            " << endl;
	minSpanTree.OutPutTree();
	cout << "**********************************************************************" << endl;
	system("pause");
	return 0;
}