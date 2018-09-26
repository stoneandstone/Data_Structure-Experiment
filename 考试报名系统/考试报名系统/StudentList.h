#pragma once

#include "Student.h"
#include <vector>

class StudentList
{
public:
	StudentList();
	~StudentList();

	//查询所有学生中符合index属性为content的学生，并将符合条件的学生全部储存在result里
	void searchAllStudent(string index, string content);

	//添加一个学生
	void addStudent(Student& obj);

	//按条件删除学生
	void deleteStudent(string index, string content);

	void searchStudent(string index, string content);


	//根据学生的考号来寻找学生并进行相关的修改
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
		cout << "内存申请失败，插入失败";
		return;
	}

	if (!first || obj.information.at("id") < first->information.at("id"))
		//在表头插入
	{
		newStudent->next = first;
		first = newStudent;
		number++;
		cout << "录入成功\n";
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
		//在表尾插入
	{
		insert->next = newStudent;
		number++;
		cout << "录入成功\n";
		return;
	}
	else
		//表中央插入
	{
		newStudent->next = insert->next;
		insert->next = newStudent;
		number++;
		cout << "录入成功\n";
		return;
	}
}

inline void StudentList::deleteStudent(string index, string content)
{
	searchAllStudent(index, content);
	if (result.empty())
	{
		cout << "未找到相关考生";
		return;
	}

	cout << "以下考生将被删除\n";

	for (auto del_stu : result)
	{
		cout << *del_stu;
	}
	cout << "是否确定？ Y or N  ";
	string input;
	cin >> input;
	if (input == "N")
	{ 
		cout << "撤销操作\n";
		return;
	}
		
	for (auto del_stu : result)
	{
		if (first->information.at("id") == del_stu->information.at("id"))
			//删除头部
		{
			Student* temp = first;
			first = first->next;
			delete temp;
			number--;
			return;
		}
		Student* past_stu = first;
		for (int i = 0; i < number; ++i)
			//寻找被删除节点的前一个节点指针
		{
			if (past_stu->next->information.at("id") == del_stu->information.at("id"))
				break;

			if (!past_stu->next)
			{
				cout << "未找到该考生\n";
				return;
			}
			past_stu = past_stu->next;
		}
		if (past_stu->next->next == nullptr)
			//删除尾部节点
		{
			delete past_stu->next;
			past_stu->next = nullptr;
			number--;
			return;
		}
		else
			//删除中间节点
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
		cout << "未找到相关考生\n";
		return;
	}
	cout << "共找到" << result.size() << "名相关考生\n";
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
	cout << "请输入修改的项目（考号不可被修改）\n";
	cin >> index;
	cout << "修改内容为\n";
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
	return result;// TODO: 在此处插入 return 语句
}

