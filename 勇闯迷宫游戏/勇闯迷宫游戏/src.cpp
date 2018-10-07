#include <iostream>
#include <stack>
#include <string>
#include <memory>
#include <assert.h>

using namespace std;

class Offset
{
public:
	int x, y;
	string dir;
};

class Node
{
public:
	int x;
	int y;
	int dir;
};

void createMaze(int** &maze, int** &mark, int&row, int& col)
{
	cout << "�������Թ�������������" << endl;
	cin >> row >> col;
	maze = new int*[row];
	assert(maze == nullptr);
	mark = new int*[row];
	assert(mark == nullptr);
	for (int i = 0; i < row; ++i)
	{
		maze[i] = new int[col];
		assert(maze[i] == nullptr);
		mark[i] = new int[col];
		assert(mark[i] == nullptr);
	}
	for (int i1 = 0; i1 < row; ++i1)
	{
		cout << "�������" << i1 + 1 << "���Թ� ��"<< col<<"�����֣�0����·,1����Χǽ��"<< endl;
		for (int i2 = 0; i2 < col; ++i2)
		{
			cin >> maze[i1][i2];
		}
	}
	cout << "��������Թ�Ϊ" << endl;
	for (int i1 = 0; i1 < row; ++i1)
	{
		for (int i2 = 0; i2 < col; ++i2)
		{
			cout << maze[i1][i2] << " ";
		}
		cout << endl;
	}
}

void seekPath(int beginx, int beginy, int endx, int endy, stack<Node>&path)
{
	 
}

int main()
{
	int** maze, **mark;
	int row, col;
	createMaze(maze, mark, row, col);
	Offset move[8] = { {-1,0,"N"} ,{-1,1,"NE"},{0,1,"E"},{1,1,"SE"},{1,0,"S"},{1,-1,"SW"},{0,-1,"W"},{-1,-1,"NW"} };

	int beginx, beginy, endx, endy;
	do
	{
		cin >> beginx >> beginy >> endx >> endy;
	} while (!maze[beginx][beginy] && !maze[endx][endy]);

	stack<Node>path;

	return 0;
}