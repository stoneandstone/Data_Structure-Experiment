#pragma once

#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;

class Person
{
public:

	//��ѯ����Ϊname�ĳ�Ա
	Person* searchPerson(string name)
	{
		queue<Person*> searchQueue;
		searchQueue.push(ancestor);
		while (!searchQueue.empty())
		{
			Person* curPerson = searchQueue.front();
			searchQueue.pop();
			if (curPerson->name == name)
				return curPerson;

			for (auto curChild : curPerson->child)
				searchQueue.push(curChild);
		}

		return nullptr;
	}

	//���һ����Ů
	Person* addChild(string name)
	{
		if (searchPerson(name))
		{
			cout << "�������������";
			return nullptr;
		}

		Person* newPerson = new Person(name);
		newPerson->ancestor = ancestor;
		newPerson->parent = this;

		child.push_back(newPerson);
	}

	//��ɢ�ó�Ա�ļ�ͥ
	void releaseFamily()
	{
		while (!child.empty())
		{
			auto deleteChild = child.begin();
			(*deleteChild)->releaseFamily();
		}
		

		for (auto delChild = parent->child.begin(); delChild != parent->child.end(); delChild++)
		{
			if ((*delChild)->name == name)
			{
				parent->child.erase(delChild);
				break;
			}	
		}

		cout << name << "��ɾ��" << endl;
		delete this;
	}

	//��Ա�Ĺ��캯��
	Person(string _name)
	{
		name = _name;

	}

	//���øó�Ա������
	void setAncestor(Person* a)
	{
		ancestor = a;
	}

	//��ȡ�ó�Ա������
	string getName()
	{
		return name;
	}

	//��ȡ�ó�Ա��Ů
	vector<Person*>& getChild()
	{
		return child;
	}

	//���øó�Ա������
	void setName(string inputName)
	{
		if (searchPerson(inputName))
		{
			cout << "�޸�ʧ�ܣ������ظ�";
			return;
		}
		name = inputName;
	}

private:

	string name;				//��Ա������	
	Person* parent;				//��Ա���ڵ�ָ��
	vector<Person*>child;		//��Ա����Ů��

	Person* ancestor;			//�ü�ͥ������
};
