#include "StudentList.h"

int main()
{
	cout << "�״ν���������Ϣϵͳ\n";

	StudentList studentList;
	int firstNum;
	cout << "�������״�¼�뿼������\n";
	cin >> firstNum;

	Student input_student;
	for (int i = 0; i < firstNum; ++i)
	{
		cin >> input_student;
		if (input_student.checkStudent())
		{
			cout << "ѧ���ɼ�¼��ɹ������� " << firstNum - i - 1 << " �˵ȴ�¼��\n";
		}
	}
	cout << "¼�����\n";
	cout << "������ָ�������Ҫ��ɵĲ�����\ninsert:��������   delete:ɾ������ exit:�˳�����\n";
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
			cout << "������ʽ ���ţ�id ������name\n";
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
			cout << "������ʽ ���ţ�id ����";
			string order_search;
			cin >> order_search;
			if (order_search == "id")
			{

			}
			
		}
		else if (order == "edit")
		{
			cout << "������ʽ ���ţ�id ����";
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
		cout << "�����������Ҫ��ɵĲ�����\ninsert:��������   delete:ɾ������ exit:�˳�����\n";
		cin >> order;
	}

	return 0;
}