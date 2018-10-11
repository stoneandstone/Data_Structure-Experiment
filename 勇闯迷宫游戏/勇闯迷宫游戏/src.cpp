#include <iostream>
#include <vector>
#include <assert.h>

using namespace std;

int** maze;
int row, col;


class Node
{
public:
	int row;
	int col;

	friend istream& operator>>(istream& input, Node& obj)
	{
		input >> obj.row >> obj.col;
		return input;
	}
	bool operator==(const Node& obj)
	{
		return (row==obj.row&&col==obj.col);
	}
};  

Node beginNode, endNode;
Node turn[8] = { {0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1} };
vector<Node>path;

void createMaze()
{
	cout << "�������Թ�������������" << endl;
	cin >> row >> col;
	maze = new int*[row];
	assert(maze);
	for (int i = 0; i < row; ++i)
	{
		maze[i] = new int[col];
		assert(maze[i]);
	}
	for (int i1 = 0; i1 < row; ++i1)
	{
		cout << "�������" << i1  << "���Թ� ��"<< col<<"�����֣�0����·,1����Χǽ��"<< endl;
		for (int i2 = 0; i2 < col; ++i2)
		{
			cin >> maze[i1][i2];
		}
	}
	cout << "��������Թ�Ϊ" << endl;
	cout << "        ";
	for (int i = 0; i < col; ++i)
	{
		cout << "��" << i << "�� ";
	}
	cout << endl;
	for (int i1 = 0; i1 < row; ++i1)
	{
		cout << "��" << i1 << "��     ";
		for (int i2 = 0; i2 < col; ++i2)
		{
			cout << maze[i1][i2] << "     ";
		}
		cout << endl;
	}


	do
	{
		cout << "�������Թ��������յ� �����������������Կո�ֿ�" << endl;
		cin >> beginNode >> endNode;
		if (endNode.row<0 || endNode.col<0 || endNode.row>row || endNode.col>col)
			continue;
		if (beginNode.row<0 || beginNode.col<0 || beginNode.row>row || beginNode.col>col)
			continue;

	} while (maze[beginNode.row][beginNode.col] && maze[endNode.row][endNode.col]);
	int a;
}

bool findNode(const Node& obj)
{
	for (auto n : path)
	{
		if (n == obj)
			return true;
	}
	return false;
}

void outputPath()
{
	static int count = 1;
	cout << "��" << count << "��·����" << endl;
	for (auto node : path)
	{
		cout << "(" << node.row << "," << node.col << ")";
		if (!(node == *path.rbegin()))
		{
			cout << "----->";
		}
	}
	count++;
}

void seekPath(Node& past)
{
	static bool isFind = false;
	if (isFind)
		return;
	if (past == endNode)
	{
		outputPath();
		path.erase(path.end() - 1);
		return;
	 }
	for (int i = 0; i < 8; ++i)
	{
		Node cur;
		cur.row = past.row + turn[i].row;
		cur.col = past.col + turn[i].col;
		if (cur.row >= 0 && cur.row < row&&cur.col >=0 && cur.col < col)
		{
			if (maze[cur.row][cur.col] == 0&&!findNode(cur))
			{
				path.push_back(cur);
				seekPath(cur);
			}
		}
	}
	path.erase(path.end() - 1);
}



int main()
{
	createMaze();
	path.push_back(beginNode);
	seekPath(beginNode);
	
	system("pause");
	return 0; 
}