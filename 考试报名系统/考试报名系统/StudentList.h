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

	void searchStudent(string index, string content);


	//����ѧ���Ŀ�����Ѱ��ѧ����������ص��޸�
	void editStudent(string id);

	void removeAllStudent(const Student& obj);

	void printAllStudent(const Student& printStudent);



	const Student* getListFirst()const;
	
	vector<Student*>& getResult();

private:
	
	vector<Student*>result;
	Student* first;
	int number;
};

StudentList::StudentList()
{
}

StudentList::~StudentList()
{
	removeAllStudent(*first);
}

inline void StudentList::searchAllStudent(string index, string content)
{
	Student* search = first;
	for (int i = 0; i < number; ++i)
	{
		if (search->information.at(index) == content)
			result.push_back(search);
		if (search->next == nullptr)
			break;
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

	if (!first || obj.information.at("id") < first->information.at("id"))
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
		if (insert->information.at("id") < obj.information.at("id") || obj.information.at("id") < insert->next->information.at("id"))
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

inline void StudentList::deleteStudent(string index, string content)
{
	searchAllStudent(index, content);
	if (result.empty())
	{
		cout << "δ�ҵ���ؿ���";
		return;
	}

	cout << "���¿�������ɾ��\n";

	for (auto del_stu : result)
	{
		cout << *del_stu;
	}
	cout << "�Ƿ�ȷ���� Y or N  ";
	string input;
	cin >> input;
	if (input == "N")
	{ 
		cout << "��������\n";
		return;
	}
		
	for (auto del_stu : result)
	{
		if (first->information.at("id") == del_stu->information.at("id"))
			//ɾ��ͷ��
		{
			Student* temp = first;
			first = first->next;
			delete temp;
			number--;
			return;
		}
		Student* past_stu = first;
		for (int i = 0; i < number; ++i)
			//Ѱ�ұ�ɾ���ڵ��ǰһ���ڵ�ָ��
		{
			if (past_stu->next->information.at("id") == del_stu->information.at("id"))
				break;

			if (!past_stu->next)
			{
				cout << "δ�ҵ��ÿ���\n";
				return;
			}
			past_stu = past_stu->next;
		}
		if (past_stu->next->next == nullptr)
			//ɾ��β���ڵ�
		{
			delete past_stu->next;
			past_stu->next = nullptr;
			number--;
			return;
		}
		else
			//ɾ���м�ڵ�
		{
			Student* temp = past_stu->next;
			past_stu->next = past_stu->next->next;
			delete temp;
			number--;
			return;
		}
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
	if (printStudent.next)
		printAllStudent(*printStudent.next);
}

inline const Student * StudentList::getListFirst() const
{
	return first;
}

inline vector<Student*>& StudentList::getResult()
{
	return result;// TODO: �ڴ˴����� return ���
}

