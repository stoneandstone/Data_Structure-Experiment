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

	int data;		//��ö��������Ķ�������
	int length;		//�߳���
	Vertice* next;	//��һ������
};

class Graph
{
public:
	//����ͼ������ͨ�����캯������ʱ��������ݹ���
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

	//Ѱ�ҹؼ�����㷨
	vector<string> criticalActivity()
	{
		vector<string>result;
		vector<int>Ve(vertices.size(), 0);				//�¼������翪ʼʱ��
		vector<int>Vl(vertices.size(), INT_MAX);		//�¼�����ٿ�ʼʱ��

		auto topo = Topo();

		if (topo.empty())
		{
			result.push_back(to_string(0));
			return result;
		}

		//����Ve
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
		//����Vl
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

	//�������е㹹����������
	vector<int>Topo()
	{
		vector<int>topo(verticeNum + 1, 0);
		for (int i = 1; i <= verticeNum; ++i)
		{
			//��¼��һ�����ж�������
			vector<int>inDegree(verticeNum + 1, 0);
			for (int j = 1; j <= verticeNum; j++)
			{
				if (topo[j] != 0)//����õ������������У��������õ�
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
		for (int l = 1; l <= verticeNum; l++)	//�ж��Ƿ����е㶼��������
		{
			if (topo[l] == 0)
				return vector<int>();
		}
		return topo;
	}

	int verticeNum;
	vector<Vertice*> vertices;	//�ڽӱ�洢ͼ

	int edgeNum;
};