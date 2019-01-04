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

	//移除所有学生
	void removeAllStudent(const Student& obj);

	//输出所有学生的数据
	void printAllStudent(const Student& printStudent);

	//获取链表头指针
	const Student* getListHead()const;
	
	//获取操作的结果数组
	vector<Student*>& getResult();

private:
	//所选取操作后存储结果
	vector<Student*>result;

	//链表的头指针,这是一个空结点，不存放学生的数据
	Student* first;
};

StudentList::StudentList()
{
	first = new Student;
	first->next = nullptr;
}

StudentList::~StudentList()
{
	removeAllStudent(*first);
}

inline void StudentList::searchAllStudent(string index, string content)
{
	Student* search = first;
	while (true)
	{
		if (search->information.at(index) == content)
			result.push_back(search);
		if (search->next == nullptr)
			break;
		search = search->next;
	};
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

	Student* insert = first;
	while (insert->next != nullptr)
	{
		if (insert->next->information.at("id") == obj.information.at("id"))
		{
			cout << "不能有相同的考号，插入失败" << endl;
			return;
		}
		if (insert->next->information.at("id") > obj.information.at("id"))
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
		//被删除结点的前一个指针
		Student* past_stu = first;

		do
		{
			if (past_stu->next->information.at("id") == del_stu->information.at("id"))
				break;
			past_stu = past_stu->next;
		} while (past_stu->next != nullptr);

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
	if (printStudent.next != nullptr)
		printAllStudent(*printStudent.next);
}

inline const Student * StudentList::getListHead() const
{
	return first;
}

inline vector<Student*>& StudentList::getResult()
{
	return result;// TODO: 在此处插入 return 语句
}

