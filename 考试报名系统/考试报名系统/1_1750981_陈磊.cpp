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
		cout << "�밴�� ѧ�� ���� �Ա� ���� �������� Ϊ��ʽ���뿼����Ϣ" << endl;
		cin >> input_student;
		if (input_student.checkStudent())
		{
			studentList.addStudent(input_student);
			cout << "ѧ���ɼ�¼��ɹ������� " << firstNum - i - 1 << " �˵ȴ�¼��\n";
		}
	}
	cout << "¼�����\n";
	cout << "������ָ�������Ҫ��ɵĲ�����\ninsert:��������   delete:ɾ������ edit:�޸����� overview:�鿴���п��� exit:�˳�����\n";
	string order;

	cin >> order;
	while (order != "exit")
	{
		if (order == "insert")
		{
			cout << "�밴�� ѧ�� ���� �Ա� ���� �������� Ϊ��ʽ���뿼����Ϣ" << endl;
			cin >> input_student;
			if (input_student.checkStudent())
			{
				studentList.addStudent(input_student);
			}
		}
		else if (order == "delete")
		{
			cout << "������ʽ ���ţ�id ������name �Ա�sex ���䣺age �������ࣺkind\n";
			string index, content;
			cin >> index;
			cout << "ɾ�����������Ϊ\n";
			cin >> content;
			studentList.deleteStudent(index, content);
		}
		else if (order == "search")
		{
			cout << "������ʽ ���ţ�id ������name �Ա�sex ���䣺age �������ࣺkind\n";
			string index, content;
			cin >> index;
			cout << "�����Ӧ����Ϊ\n";
			cin >> content;
			studentList.searchStudent(index, content);
		}
		else if (order == "edit")
		{
			cout << "������ÿ�������\n";
			string id;
			cin >> id;
			studentList.editStudent(id);
		}
		else if(order=="count")
		{
			cout << "���п�������\n";
		}
		else
		{
			cout << "������Ϸ���ָ��\n";
			continue;
		}

		studentList.printAllStudent(*studentList.getListHead());
		studentList.getResult().clear();
		cout << "������ָ�������Ҫ��ɵĲ�����\ninsert:��������   delete:ɾ������ edit:�޸����� count:ͳ�� exit:�˳�����\n";
		cin >> order;
	}

	return 0;
}