#pragma once

#include <iostream>
#include <string>

using namespace std;

class Student
{
public:
	Student() = default;
	~Student();
	friend class StudentList;

	Student(Student* p, int num, string na, string se, int ag, string ki, Student* n)
		:id(num),name(na),sex(se),age(ag),kind(ki),next(n) {}

	Student(const Student& obj)
	{
		id = obj.id;
		name = obj.name;
		sex = obj.sex;
		age = obj.age;
		kind = obj.kind;
	}

	bool operator==(const Student& obj)
	{
		if (id == obj.id&&name == obj.name&&sex == obj.sex&&age == obj.age&&kind == obj.kind)
			return true;
		return false;
	}

	friend istream& operator>>(istream& input, Student& obj)
	{
		input >> obj.id >> obj.name >> obj.sex >> obj.age >> obj.kind;
		return input;
	}

	friend ostream& operator<<(ostream& output, const Student& obj)
	{
		output << obj.id << " " << obj.name << " " << obj.sex << " " << obj.age << " " << obj.kind << endl;
		return output;
	}

	bool checkStudent()
	{
		return true;
	}

	const int getStudentId()const
	{
		return id;
	}
	const string getStudentName()const
	{
		return name;
	}
	const string getStudentSex()const
	{
		return sex;
	}
	const int getStudentAge()const
	{
		return age;
	}
	const string getStudentKind()const
	{
		return kind;
	}

	void setStudentId(const int input_id)
	{
		id = input_id;
	}
	void setStudentName(const string input_name)
	{
		name = input_name;
	}
	void setStudentSex(const string input_sex)
	{
		sex = input_sex;
	}
	void setStudentAge(const int input_age)
	{
		age = input_age;
	}
	void setStudentKind(const string input_kind)
	{
		kind = input_kind;
	}

private:
	int id;
	string name;
	string sex;
	int age;
	string kind;
	Student* next;
};


Student::~Student()
{
}

