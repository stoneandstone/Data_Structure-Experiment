#pragma once

class Edge
{
public:
	Edge() = default;

	Edge(int _length, int _vertice_1, int _vertice_2) :length(_length), vertice_1(_vertice_1), vertice_2(_vertice_2) {};

	Edge(const Edge& obj)
	{
		length = obj.length;
		vertice_1 = obj.vertice_1;
		vertice_2 = obj.vertice_2;
	}

	bool operator>(const Edge& obj)
	{
		return length > obj.length;
	}

	bool operator<=(const Edge& obj)
	{
		return length <= obj.length;
	}

	int getLength()
	{
		return length;
	}

	int getVertice_1()
	{
		return vertice_1;
	}

	int getVertice_2()
	{
		return vertice_2;
	}

private:
	int length;
	int vertice_1;
	int vertice_2;
};

