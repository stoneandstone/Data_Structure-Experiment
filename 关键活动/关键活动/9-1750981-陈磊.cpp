#include "graph.h"

int main()
{
	int verticeNum, edgeNum;
	cin >> verticeNum >> edgeNum;
	Graph graph(verticeNum, edgeNum);
	auto critical = graph.criticalActivity();


	for (auto a : critical)
	{
		cout << a << endl;
	}

	return 0;
}