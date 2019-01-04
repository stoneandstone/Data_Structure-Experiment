#pragma once

#include <iostream>
#include <vector>
#include <assert.h>
#include <string>

using namespace std;

class Vertice
{
public:
	Vertice() :data(0), length(0), next(nullptr) {}
	Vertice(int _data, int _length, Vertice* _v = nullptr) :data(_data), length(_length), next(_v) {}

	void release()
	{
		if (next)
			next->release();

		delete this;
	}

	int data;		//与该顶点相连的顶点名字
	int length;		//边长度
	Vertice* next;	//下一个顶点
};

class Graph
{
public:
	//构造图的数据通过构造函数运行时读入的数据构造
	Graph(int _verticeNum, int _edgeNum) :verticeNum(_verticeNum), edgeNum(_edgeNum)
	{
		vertices = vector<Vertice*>(verticeNum + 1);

		for (auto& v : vertices)
		{
			v = new Vertice;
			assert(v);
		}

		for (int i = 0; i < edgeNum; ++i)
		{
			int node_1, node_2, inputLength;
			cin >> node_1 >> node_2 >> inputLength;
			auto newVer = new Vertice(node_2, inputLength, vertices[node_1]->next);
			vertices[node_1]->next = newVer;
		}

	}

	~Graph()
	{
		for (auto v : vertices)
		{
			if (v->next)
			{
				v->next->release();
			}
		}
	}

	//寻找关键活动的算法
	vector<string> criticalActivity()
	{
		vector<string>result;
		vector<int>Ve(vertices.size(), 0);				//事件的最早开始时间
		vector<int>Vl(vertices.size(), INT_MAX);		//事件的最迟开始时间

		auto topo = Topo();

		if (topo.empty())
		{
			result.push_back(to_string(0));
			return result;
		}

		//计算Ve
		for (int i = 1; i <= verticeNum; i++)
		{
			int curV = topo[i];
			Vertice* temp = vertices[curV]->next;
			if (!temp)
				continue;
			while (true)
			{
				if (Ve[temp->data] < Ve[curV] + temp->length)
					Ve[temp->data] = Ve[curV] + temp->length;
				temp = temp->next;
				if (temp == nullptr)
					break;
			}
		}

		result.push_back(to_string(Ve[verticeNum]));

		Vl[verticeNum] = Ve[verticeNum];
		//计算Vl
		for (int i = verticeNum; i >= 1; i--)
		{
			int curV = topo[i];
			Vertice* temp = vertices[curV]->next;
			if (!temp)
				continue;
			while (true)
			{
				if (Vl[temp->data] - temp->length < Vl[curV])
					Vl[curV] = Vl[temp->data] - temp->length;
				temp = temp->next;
				if (temp == nullptr)
					break;;
			}
		}

		for (int curV = 1; curV <= verticeNum; curV++)
		{
			Vertice* temp = vertices[curV]->next;
			if (!temp)
				continue;
			while (true)
			{
				int ae = Ve[curV];
				int al = Vl[temp->data] - temp->length;
				if (ae == al)
				{
					result.push_back(to_string(curV) + "->" + to_string(temp->data));
				}
				temp = temp->next;
				if (temp == nullptr)
					break;;
			}
		}
		return result;
	}

private:

	//对于所有点构造拓扑序列
	vector<int>Topo()
	{
		vector<int>topo(verticeNum + 1, 0);
		for (int i = 1; i <= verticeNum; ++i)
		{
			//记录这一轮所有顶点的入度
			vector<int>inDegree(verticeNum + 1, 0);
			for (int j = 1; j <= verticeNum; j++)
			{
				if (topo[j] != 0)//假如该点在拓扑序列中，就跳过该点
					continue;
				Vertice* temp = vertices[j]->next;
				if (!temp)
					continue;
				while (true)
				{
					inDegree[temp->data]++;
					temp = temp->next;
					if (temp == nullptr)
						break;;
				}
			}
			for (int k = 1; k <= verticeNum; k++)
			{
				if (inDegree[k] == 0 && topo[k] == 0)
				{
					topo[k] = i;
					break;
				}
			}
		}
		for (int l = 1; l <= verticeNum; l++)	//判断是否所有点都在序列中
		{
			if (topo[l] == 0)
				return vector<int>();
		}
		return topo;
	}

	int verticeNum;
	vector<Vertice*> vertices;	//邻接表存储图

	int edgeNum;
};