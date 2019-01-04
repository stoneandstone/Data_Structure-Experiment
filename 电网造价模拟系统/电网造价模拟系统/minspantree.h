#pragma once

#include <vector>
#include "edge.h"
#include "minheap.h"
#include "UFSets.h"

using namespace std;

class MinSpanTree
{
public:
	friend class Edge;

	MinSpanTree(vector<int>&nodes,vector<Edge>&allEdges)
	{
		edgeSize = nodes.size() - 1;
		MinHeap<Edge>minEdge(allEdges);
		UFSets ufSet(26);

		while (edges.size() < edgeSize && !minEdge.empty())
		{
			Edge curEdge;
			minEdge.remmoveMin(curEdge);
			auto v1 = ufSet.find(curEdge.getVertice_1());
			auto v2 = ufSet.find(curEdge.getVertice_2());
			if (v1 == -1 || v2 == -1 || v1 != v2)
			{
				ufSet.setUnion(v1, v2);
				edges.push_back(curEdge);
			}
		}
		if (edges.size() != edgeSize)
			succeed = false;
		else
		{
			succeed = true;
		}

	}

	//判断最小生成树是否构建完成
	bool isSuccced()
	{
		return succeed;
	}

	//输出最小生成树
	void OutPutTree()
	{
		for (auto e : edges)
		{
			char v1 = e.getVertice_1() + 'a', v2 = e.getVertice_2() + 'a';

			cout << v1 << " - " << e.getLength() << " - " << v2 << endl;
		}
	}

private:
	int edgeSize;
	bool succeed;
	vector<Edge>edges;
};