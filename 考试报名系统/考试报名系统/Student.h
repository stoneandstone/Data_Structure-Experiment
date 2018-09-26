#pragma once

#include <iostream>
#include <string>
#include <map>

using namespace std;

class Student
	//�ڵ���Ķ����ʵ��
{
public:
	Student();
	~Student();

	Student(const Student& obj)
	{
		information.at("id") = obj.information.at("id");
		information.at("name") = obj.information.at("name");
		information.at("sex") = obj.information.at("sex");
		information.at("age") = obj.information.at("age");
		information.at("kind") = obj.information.at("kind");
	}

	friend class StudentList;

	bool operator==(const Student& obj)
	{
		if (information.at("id")==obj.information.at("id")&& information.at("name") == obj.information.at("name")
			&& information.at("sex") == obj.information.at("sex")&& information.at("age") == obj.information.at("age")
			&& information.at("kind") == obj.information.at("kind"))

			return true;
		return false;
	}

	friend istream& operator>>(istream& input, Student& obj)
	{
		input >> obj.information.at("id") >> obj.information.at("name") >> obj.information.at("sex") 
			>> obj.information.at("age") >> obj.information.at("kind");
		return input;
	}

	friend ostream& operator<<(ostream& output, const Student& obj)
	{
		output << obj.information.at("id") << " " << obj.information.at("name") << " " << obj.information.at("sex") << " "
			<< obj.information.at("age") << " " << obj.information.at("kind") << endl;
		return output;
	}

	bool checkStudent()
	{
		if (information.at("sex") != "��"&&information.at("sex") != "Ů")
		{
			cout << "�Ա���������\n";
			return false;
		}
		for (auto c : information.at("age"))
		{
			if (c<'0' || c>'9')
			{
				cout << "������������\n";
				return false;
			}
		}
		return true;
	}

	void editStudentInformation(const string& index, const string& content)
	{
		if (index != "name"&&index != "sex"&&index != "age"&&index != "kind")
		{
			cout << "������Ϸ�������";
			return;
		}
		information.at(index) = content;
	}


private:
	map<string, string>information;
	
	Student* next;
};


Student::Student()
//�ֱ������ѧ����������� ѧ�� ���� �Ա� ���� ��������
{
	information.insert(make_pair("id",""));
	information.insert(make_pair("name", ""));
	information.insert(make_pair("sex", ""));
	information.insert(make_pair("age", "")); 
	information.insert(make_pair("kind", ""));
}

Student::~Student()
{
}

