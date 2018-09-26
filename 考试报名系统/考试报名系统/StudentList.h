#pragma once

#include "Student.h"
#include <vector>

class StudentList
{
public:
	StudentList();
	~StudentList();

	//��ѯ����ѧ���з���index����Ϊcontent��ѧ������������������ѧ��ȫ��������result��
	void searchAllStudent(string index, string content);

	//���һ��ѧ��
	void addStudent(Student& obj);

	//������ɾ��ѧ��
	void deleteStudent(string index, string content);

	//����������ѧ��
	void searchStudent(string index, string content);


	//����ѧ���Ŀ�����Ѱ��ѧ����������ص��޸�
	void editStudent(string id);

	void removeAllStudent(const Student& obj);

	void printAllStudent(const Student& printStudent);



	const Student* getListHead()const;
	
	vector<Student*>& getResult();

private:
	
	vector<Student*>result;
	Student* first;
	Student* headNode, *endNode;
	int number;
};

StudentList::StudentList()
{
	headNode = new Student;
	endNode = new Student;
	first = headNode;
	headNode->next = endNode;
	endNode->next = nullptr;
}

StudentList::~StudentList()
{
	removeAllStudent(*first);
}

inline void StudentList::searchAllStudent(string index, string content)
{
	Student* search = headNode;
	while (search != endNode)
	{
		if (search->information.at(index) == content)
			result.push_back(search);
		search = search->next;
	}
}

inline void StudentList::addStudent(Student & obj)
{
	Student* newStudent = new Student;
	*newStudent = obj;
	if (!newStudent)
	{
		cout << "�ڴ�����ʧ�ܣ�����ʧ��";
		return;
	}

	Student* insert = headNode;
	while (insert != endNode)
	{
		if (insert->information.at("id") == obj.information.at("id"))
		{
			cout << "��������ͬ�Ŀ��ţ�����ʧ��" << endl;
			return;
		}
		if (insert->information.at("id") < obj.information.at("id") && obj.information.at("id") < insert->next->information.at("id"))
			break;
		insert = insert->next;
	}
	newStudent->next = insert->next;
	insert->next = newStudent;
	cout << "����ɹ�" << endl;
}

inline void StudentList::deleteStudent(string index, string content)
{
	searchAllStudent(index, content);
	if (result.empty())
	{
		cout << "δ�ҵ���ؿ���" << endl;
		return;
	}

	cout << "���¿�������ɾ��\n";

	for (auto del_stu : result)
	{
		cout << *del_stu;
	}
	cout << "�Ƿ�ȷ���� Y or other command  ";
	string input;
	cin >> input;
	if (input != "Y")
	{ 
		cout << "��������\n";
		return;
	}
		
	for (auto del_stu : result)
	{
		Student* past_stu = headNode;
		while (past_stu != endNode)
			//Ѱ�ұ�ɾ���ڵ��ǰһ���ڵ�ָ��
		{
			if (past_stu->next->information.at("id") == del_stu->information.at("id"))
				break;
			past_stu = past_stu->next;
		}
		past_stu->next = del_stu->next;
		delete  del_stu;
	}
}

inline void StudentList::searchStudent(string index, string content)
{
	searchAllStudent(index, content);
	if (result.empty())
	{
		cout << "δ�ҵ���ؿ���\n";
		return;
	}
	cout << "���ҵ�" << result.size() << "����ؿ���\n";
	for (auto stu : result)
	{
		cout << *stu;
	}
}

inline void StudentList::editStudent(string id)
{
	searchAllStudent("id", id);
	cout << *result[0];
	string index, content;
	cout << "�������޸ĵ���Ŀ�����Ų��ɱ��޸ģ�\n";
	cin >> index;
	cout << "�޸�����Ϊ\n";
	cin >> content;
	result[0]->editStudentInformation(index, content);
}

inline void StudentList::removeAllStudent(const Student & obj)
{
	if (obj.next)
	{
		removeAllStudent(*obj.next);
	}

	delete &obj;
	return;
}

inline void StudentList::printAllStudent(const Student& printStudent)
{
	cout << printStudent;
	if (printStudent.next != endNode)
		printAllStudent(*printStudent.next);
}

inline const Student * StudentList::getListHead() const
{
	return headNode;
}

inline vector<Student*>& StudentList::getResult()
{
	return result;// TODO: �ڴ˴����� return ���
}

