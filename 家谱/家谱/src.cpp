#include <iostream>
#include "Person.h"

void init(Person*& ancestor)
{
	cout << "首先建立一个家谱" << endl;
	cout << "请输入祖先的姓名：" << endl;


	string inputName;
	cin >> inputName;

	ancestor = new Person(inputName);
	ancestor->setAncestor(ancestor);
	cout << "祖先的姓名是" << ancestor->getName() << endl;
	cout << "请输入祖先的儿女数" << endl;
	int inputNum;
	cin >> inputNum;
	cout << "请依次输入" << ancestor->getName() << "子女的姓名" << endl;
	for (int i = 1; i <= inputNum; ++i)
	{
		cin >> inputName;
		if (ancestor->addChild(inputName))
			cout << "添加成功" << endl;
		else
			cout << "添加失败" << endl;
	}
	cout << "系统初始化完成" << endl;
}

void completeFamily(Person*& ancestor)
{
	string inputName;
	int inputNum;
	cout << "请输入要操作的家庭成员姓名" << endl;
	cin >> inputName;
	auto curPerson = ancestor->searchPerson(inputName);
	if (!curPerson)
	{
		cout << "冇这个人,操作结束" << endl;
		return;
	}

	cout << "子女个数";
	cin >> inputNum;
	for (int i = 1; i <= inputNum; ++i)
	{
		cout << "输入子女的名字";
		cin >> inputName;
		curPerson->addChild(inputName);
	}

	cout << curPerson->getName() << "的子女有";
	for (auto curChild : curPerson->getChild())
	{
		cout << curChild->getName() << "  ";
	}
}

void addOnePerson(Person*& ancestor)
{
	string inputName;
	int inputNum;
	cout << "请输入要操作的家庭成员姓名" << endl;
	cin >> inputName;
	auto curPerson = ancestor->searchPerson(inputName);
	if (!curPerson)
	{
		cout << "冇这个人";
		return;
	}

	cout << "输入子女的名字";
	cin >> inputName;
	curPerson->addChild(inputName);

	cout << curPerson->getName() << "的子女有";
	for (auto curChild : curPerson->getChild())
	{
		cout << curChild->getName() << "  ";
	}
}

void deleteFamily(Person*& ancestor)
{
	string inputName;
	int inputNum;
	cout << "请输入要操作的家庭成员姓名" << endl;
	cin >> inputName;
	auto curPerson = ancestor->searchPerson(inputName);
	if (!curPerson)
	{
		cout << "冇这个人";
		return;
	}

	curPerson->releaseFamily();
}

void editName(Person*& ancestor)
{
	string inputName;
	cout << "请输入要操作的家庭成员姓名" << endl;
	cin >> inputName;
	auto curPerson = ancestor->searchPerson(inputName);
	if (!curPerson)
	{
		cout << "冇这个人";
		return;
	}

	string newName;
	cout << curPerson->getName() << "的新名字是";
	cin >> newName;
	if (ancestor->searchPerson(newName))
	{
		cout << "名字重复，修改失败";
		return;
	}
	cout << curPerson->getName() << "名字成功修改为";
	curPerson->setName(newName);
	cout << curPerson->getName() << endl;
	return;
}

int main()
{


	cout << "**                         家谱管理系统                         **" << endl;
	cout << "==================================================================" << endl;
	cout << "**                      请选择要执行的操作                      **" << endl;
	cout << "**                         A --- 完善家谱                       **" << endl;
	cout << "**                         B --- 添加家庭成员                   **" << endl;
	cout << "**                         C --- 解散局部家庭                   **" << endl;
	cout << "**                         D --- 更改家庭成员姓名               **" << endl;
	cout << "**                         E --- 退出程序                       **" << endl;

	Person* ancestor = nullptr;
	init(ancestor);
	string inputOperate;
	
	do
	{

		cout << endl << endl << "请输入你需要进行的操作码";
		cin >> inputOperate;

		if (inputOperate == "A")
			completeFamily(ancestor);
		else if (inputOperate == "B")
			addOnePerson(ancestor);
		else if (inputOperate == "C")
			deleteFamily(ancestor);
		else if (inputOperate == "D")
			editName(ancestor);

	} while (inputOperate != "E");
	
	ancestor->releaseFamily();

	return 0;
}