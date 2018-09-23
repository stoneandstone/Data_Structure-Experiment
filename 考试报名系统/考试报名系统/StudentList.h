#pragma once

#include "Student.h"

class StudentList
{
public:
	StudentList();
	~StudentList();

	Student* searchStudentById(int input_id);

	void addStudent(Student& obj);

	void deleteStudentById(int id);

	void removeAllStudent(const Student& obj);

	void printAllStudent(const Student& printStudent);



	const Student* getListFirst()const;

private:
	Student* first;
	int number;
};

StudentList::StudentList()
{
}

StudentList::~StudentList()
{
}

inline Student* StudentList::searchStudentById(int input_id)
{
	Student*search = first;
	for (int i = 0; i < number; ++i)
	{
		if (search->id == input_id)
			return search;
		search = search->next;
	}
	return nullptr;
}

inline void StudentList::addStudent(Student & obj)
{
	Student* newStudent = new Student(obj);
	if (!newStudent)
	{
		cout << "�ڴ�����ʧ�ܣ�����ʧ��";
		return;
	}

	if (!first || obj.id < first->id)
		//�ڱ�ͷ����
	{
		newStudent->next = first;
		first = newStudent;
		number++;
		cout << "¼��ɹ�\n";
		return;
	}


	Student* insert = first;
	for (int i = 1; i < number; ++i)
	{
		if (insert->id < obj.id || obj.id < insert->next->id)
			break;
		if (i == number - 1)
			break;
	}

	if (insert->next == nullptr)
		//�ڱ�β����
	{
		insert->next = newStudent;
		number++;
		cout << "¼��ɹ�\n";
		return;
	}
	else
		//���������
	{
		newStudent->next = insert->next;
		insert->next = newStudent;
		number++;
		cout << "¼��ɹ�\n";
		return;
	}
}

inline void StudentList::deleteStudentById(int id)
{
	if (first->id == id)
		//ɾ��ͷ��
	{
		Student* temp = first;
		first = first->next;
		delete temp;
		number--;
		return;
	}
	Student* deleteStudent = first;
	for (int i = 0; i < number; ++i)
		//Ѱ�ұ�ɾ���ڵ��ǰһ���ڵ�ָ��
	{
		if (deleteStudent->next->id == id)
			break;
		
		if (!deleteStudent->next)
		{
			cout << "δ�ҵ��ÿ��ŵĿ���\n";
			return;
		}
		deleteStudent = deleteStudent->next;
	}
	if (deleteStudent->next->next == nullptr)
		//ɾ��β���ڵ�
	{
		delete deleteStudent->next;
		deleteStudent->next = nullptr;
		number--;
		return;
	}
	else
		//ɾ���м�ڵ�
	{
		Student* temp = deleteStudent->next;
		deleteStudent->next = deleteStudent->next->next;
		delete temp;
		number--;
		return;
	}
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
	if (printStudent.next)
		printAllStudent(*printStudent.next);
}

inline const Student * StudentList::getListFirst() const
{
	return first;
}

