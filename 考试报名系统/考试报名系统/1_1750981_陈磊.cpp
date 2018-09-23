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
		cin >> input_student;
		if (input_student.checkStudent())
		{
			cout << "学生成绩录入成功，还有 " << firstNum - i - 1 << " 人等待录入\n";
		}
	}
	cout << "录入完成\n";
	cout << "请输入指令接下来要完成的操作：\ninsert:插入数据   delete:删除数据 exit:退出程序\n";
	string order;

	cin >> order;
	while (order != "exit")
	{
		if (order == "insert")
		{
			cin >> input_student;
			if (input_student.checkStudent())
			{
				studentList.addStudent(input_student);
			}
		}

		else if (order == "delete")
		{
			cout << "检索方式 考号：id 姓名：name\n";
			string order_delete;
			cin >> order_delete;
			if (order_delete == "id")
			{
				int input_id;
				cin >> input_id;
				studentList.deleteStudentById(input_id);
			}
		}
		else if (order == "search")
		{
			cout << "检索方式 考号：id 姓名";
			string order_search;
			cin >> order_search;
			if (order_search == "id")
			{

			}
			
		}
		else if (order == "edit")
		{
			cout << "检索方式 考号：id 姓名";
			string order_edit;
			cin >> order_edit;
			if (order_edit == "id")
			{

			}

		}
		else if(order=="overview")
		{
		}

		studentList.printAllStudent(*studentList.getListFirst());
		cout << "请输入接下来要完成的操作：\ninsert:插入数据   delete:删除数据 exit:退出程序\n";
		cin >> order;
	}

	return 0;
}