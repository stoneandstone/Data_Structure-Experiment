#include "StudentList.h"

int main()
{
	cout << "首次建立考生信息系统\n";

	StudentList studentList;
	int firstNum;
	cout << "请输入首次录入考生数量\n";
	cin >> firstNum;

	Student input_student;
	for (int i = 0; i < firstNum; ++i)
	{
		cout << "请按照 学号 姓名 性别 年龄 报考种类 为格式输入考生信息" << endl;
		cin >> input_student;
		if (input_student.checkStudent())
		{
			studentList.addStudent(input_student);
			cout << "学生成绩录入成功，还有 " << firstNum - i - 1 << " 人等待录入\n";
		}
	}
	cout << "录入完成\n";
	cout << "请输入指令接下来要完成的操作\n insert:插入数据\n delete:删除数据\n edit:修改数据\n search:查询相关考生\n count:查看所有考生\n exit:退出程序\n";
	string order;

	cin >> order;
	while (order != "exit")
	{
		if (order == "insert")
		{
			cout << "请按照 学号 姓名 性别 年龄 报考种类 为格式输入考生信息" << endl;
			cin >> input_student;
			if (input_student.checkStudent())
			{
				studentList.addStudent(input_student);
			}
		}
		else if (order == "delete")
		{
			cout << "检索方式 考号：id 姓名：name 性别：sex 年龄：age 报考种类：kind\n";
			string index, content;
			cin >> index;
			cout << "删除对象的内容为\n";
			cin >> content;
			studentList.deleteStudent(index, content);
		}
		else if (order == "search")
		{
			cout << "检索方式 考号：id 姓名：name 性别：sex 年龄：age 报考种类：kind\n";
			string index, content;
			cin >> index;
			cout << "对象对应内容为\n";
			cin >> content;
			studentList.searchStudent(index, content);
		}
		else if (order == "edit")
		{
			cout << "请输入该考生考号\n";
			string id;
			cin >> id;
			studentList.editStudent(id);
		}
		else if(order=="count")
		{
			cout << "所有考生如下\n";
		}
		else
		{
			cout << "请输入合法的指令\n";
			cin >> order;
			continue;
		}

		studentList.printAllStudent(*studentList.getListHead());
		studentList.getResult().clear();
		cout << "请输入指令接下来要完成的操作\n insert:插入数据\n delete:删除数据\n edit:修改数据\n search:查询相关考生\n count:查看所有考生\n exit:退出程序\n";
		cin >> order;
	}

	return 0;
}