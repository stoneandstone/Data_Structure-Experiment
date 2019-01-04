#pragma once

#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;

class Person
{
public:

	//查询姓名为name的成员
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

	//添加一个子女
	Person* addChild(string name)
	{
		if (searchPerson(name))
		{
			cout << "重名，不能添加";
			return nullptr;
		}

		Person* newPerson = new Person(name);
		newPerson->ancestor = ancestor;
		newPerson->parent = this;

		child.push_back(newPerson);
	}

	//解散该成员的家庭
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

		cout << name << "被删除" << endl;
		delete this;
	}

	//成员的构造函数
	Person(string _name)
	{
		name = _name;

	}

	//设置该成员的祖先
	void setAncestor(Person* a)
	{
		ancestor = a;
	}

	//获取该成员的姓名
	string getName()
	{
		return name;
	}

	//获取该成员子女
	vector<Person*>& getChild()
	{
		return child;
	}

	//设置该成员的姓名
	void setName(string inputName)
	{
		if (searchPerson(inputName))
		{
			cout << "修改失败，名字重复";
			return;
		}
		name = inputName;
	}

private:

	string name;				//成员的姓名	
	Person* parent;				//成员父节点指针
	vector<Person*>child;		//成员的子女们

	Person* ancestor;			//该家庭的祖先
};
