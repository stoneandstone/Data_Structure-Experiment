#pragma once

#include <iostream>
#include <string>
#include <map>

using namespace std;

class Student
	//节点类的定义和实现
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
		if (information.at("sex") != "男"&&information.at("sex") != "女")
		{
			cout << "性别输入有误\n";
			return false;
		}
		for (auto c : information.at("age"))
		{
			if (c<'0' || c>'9')
			{
				cout << "年龄输入有误\n";
				return false;
			}
		}
		return true;
	}

	void editStudentInformation(const string& index, const string& content)
	{
		if (index != "name"&&index != "sex"&&index != "age"&&index != "kind")
		{
			cout << "请输入合法的属性";
			return;
		}
		information.at(index) = content;
	}


private:
	map<string, string>information;
	
	Student* next;
};


Student::Student()
//分别代表了学生的五个属性 学号 姓名 性别 年龄 报考种类
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

