#include <iostream>
#include "Person.h"

void init(Person*& ancestor)
{
	cout << "���Ƚ���һ������" << endl;
	cout << "���������ȵ�������" << endl;


	string inputName;
	cin >> inputName;

	ancestor = new Person(inputName);
	ancestor->setAncestor(ancestor);
	cout << "���ȵ�������" << ancestor->getName() << endl;
	cout << "���������ȵĶ�Ů��" << endl;
	int inputNum;
	cin >> inputNum;
	cout << "����������" << ancestor->getName() << "��Ů������" << endl;
	for (int i = 1; i <= inputNum; ++i)
	{
		cin >> inputName;
		if (ancestor->addChild(inputName))
			cout << "��ӳɹ�" << endl;
		else
			cout << "���ʧ��" << endl;
	}
	cout << "ϵͳ��ʼ�����" << endl;
}

void completeFamily(Person*& ancestor)
{
	string inputName;
	int inputNum;
	cout << "������Ҫ�����ļ�ͥ��Ա����" << endl;
	cin >> inputName;
	auto curPerson = ancestor->searchPerson(inputName);
	if (!curPerson)
	{
		cout << "�������,��������" << endl;
		return;
	}

	cout << "��Ů����";
	cin >> inputNum;
	for (int i = 1; i <= inputNum; ++i)
	{
		cout << "������Ů������";
		cin >> inputName;
		curPerson->addChild(inputName);
	}

	cout << curPerson->getName() << "����Ů��";
	for (auto curChild : curPerson->getChild())
	{
		cout << curChild->getName() << "  ";
	}
}

void addOnePerson(Person*& ancestor)
{
	string inputName;
	int inputNum;
	cout << "������Ҫ�����ļ�ͥ��Ա����" << endl;
	cin >> inputName;
	auto curPerson = ancestor->searchPerson(inputName);
	if (!curPerson)
	{
		cout << "�������";
		return;
	}

	cout << "������Ů������";
	cin >> inputName;
	curPerson->addChild(inputName);

	cout << curPerson->getName() << "����Ů��";
	for (auto curChild : curPerson->getChild())
	{
		cout << curChild->getName() << "  ";
	}
}

void deleteFamily(Person*& ancestor)
{
	string inputName;
	int inputNum;
	cout << "������Ҫ�����ļ�ͥ��Ա����" << endl;
	cin >> inputName;
	auto curPerson = ancestor->searchPerson(inputName);
	if (!curPerson)
	{
		cout << "�������";
		return;
	}

	curPerson->releaseFamily();
}

void editName(Person*& ancestor)
{
	string inputName;
	cout << "������Ҫ�����ļ�ͥ��Ա����" << endl;
	cin >> inputName;
	auto curPerson = ancestor->searchPerson(inputName);
	if (!curPerson)
	{
		cout << "�������";
		return;
	}

	string newName;
	cout << curPerson->getName() << "����������";
	cin >> newName;
	if (ancestor->searchPerson(newName))
	{
		cout << "�����ظ����޸�ʧ��";
		return;
	}
	cout << curPerson->getName() << "���ֳɹ��޸�Ϊ";
	curPerson->setName(newName);
	cout << curPerson->getName() << endl;
	return;
}

int main()
{


	cout << "**                         ���׹���ϵͳ                         **" << endl;
	cout << "==================================================================" << endl;
	cout << "**                      ��ѡ��Ҫִ�еĲ���                      **" << endl;
	cout << "**                         A --- ���Ƽ���                       **" << endl;
	cout << "**                         B --- ��Ӽ�ͥ��Ա                   **" << endl;
	cout << "**                         C --- ��ɢ�ֲ���ͥ                   **" << endl;
	cout << "**                         D --- ���ļ�ͥ��Ա����               **" << endl;
	cout << "**                         E --- �˳�����                       **" << endl;

	Person* ancestor = nullptr;
	init(ancestor);
	string inputOperate;
	
	do
	{

		cout << endl << endl << "����������Ҫ���еĲ�����";
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