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

	//按条件查找学生
	void searchStudent(string index, string content);


	//根据学生的考号来寻找学生并进行相关的修改
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
		cout << "内存申请失败，插入失败";
		return;
	}

	Student* insert = headNode;
	while (insert != endNode)
	{
		if (insert->information.at("id") == obj.information.at("id"))
		{
			cout << "不能有相同的考号，插入失败" << endl;
			return;
		}
		if (insert->information.at("id") < obj.information.at("id") && obj.information.at("id") < insert->next->information.at("id"))
			break;
		insert = insert->next;
	}
	newStudent->next = insert->next;
	insert->next = newStudent;
	cout << "插入成功" << endl;
}

inline void StudentList::deleteStudent(string index, string content)
{
	searchAllStudent(index, content);
	if (result.empty())
	{
		cout << "未找到相关考生" << endl;
		return;
	}

	cout << "以下考生将被删除\n";

	for (auto del_stu : result)
	{
		cout << *del_stu;
	}
	cout << "是否确定？ Y or other command  ";
	string input;
	cin >> input;
	if (input != "Y")
	{ 
		cout << "撤销操作\n";
		return;
	}
		
	for (auto del_stu : result)
	{
		Student* past_stu = headNode;
		while (past_stu != endNode)
			//寻找被删除节点的前一个节点指针
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
	if (printStudent.next != endNode)
		printAllStudent(*printStudent.next);
}

inline const Student * StudentList::getListHead() const
{
	return headNode;
}

inline vector<Student*>& StudentList::getResult()
{
	return result;// TODO: 在此处插入 return 语句
}

