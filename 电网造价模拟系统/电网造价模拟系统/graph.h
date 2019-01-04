#pragma once

#include <iostream>
#include <vector>

using namespace std;

class Edge
{
public:
	Edge(int _length, char _node_1, char _node_2) :length(_length), node_1(_node_1), node_2(_node_2) {};

	friend istream& operator>>(istream& is, Edge& side)
	{
		is >> side.node_1 >> side.node_2 >> side.length;
	}

private:
	int length;
	char node_1, node_2;
};
