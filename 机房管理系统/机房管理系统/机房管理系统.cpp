#include<iostream>;
using namespace std;
#include "globalFile.h"
#include "identity.h"
#include "student.h"
#include "teacher.h"
#include "manager.h"
#include<fstream>
#include<string>

void managerMenu(Identity*& manager)
{
	while (true)
	{
		// ����Ա�˵�
		manager->operMenu();

		Manager* man = (Manager*)manager; // ����ǿתΪ����

		int select = 0;
		cin >> select;

		if (select == 1) // ����˺�
		{
			cout << "����˺�" << endl;
			man->addPerson();
		}
		else if (select == 2) // �鿴�˺�
		{
			cout << "�鿴�˺�" << endl;
			man->showPerson();
		}
		else if (select == 3) // �鿴����
		{
			cout << "�鿴����" << endl;
			man->showComputer();
		}
		else if (select == 4) // ���ԤԼ
		{
			cout << "���ԤԼ" << endl;
			man->cleanFile();
		}
		else
		{
			delete manager;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

void LoginIn(string fileName, int type)
{
	Identity* person = NULL; // ����ָ������ָ���������

	ifstream ifs; // ���ļ������Ƿ�����������
	ifs.open(fileName, ios::in);

	// �ļ�������
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		ifs.close();
		return;
	};

	// ׼���������ڴ洢���ļ���ȡ����Ϣ
	int id = 0;
	string name;
	string pwd;

	// ����type�жϳ�Ա���ͣ������ѧ������ʦ����Ҫ����ѧ���ţ�����ǹ���Ա���򲻹�
	if (type == 1) // ѧ����¼
	{
		cout << "������ѧ��" << endl;
		cin >> id;
	}
	else if (type == 2) // ��ʦ��¼
	{
		cout << "������ְ����" << endl;
		cin >> id;
	}

	// ����ʲô���ͣ�����Ҫ�û�����������ܵ�¼
	cout << "�������û�����" << endl;
	cin >> name;

	cout << "���������룺" << endl;
	cin >> pwd;

	// ��֤��¼������ɹ������Ӧ�ӿڣ����������¼ʧ��
	if (type == 1)
	{
		// ѧ����¼��֤
		int fId;
		string fName;
		string fPwd;
		// ѭ����ȡ�ļ��е����ݣ�ֱ�����꣬���Ƿ�����ͬ���û���������
		while (ifs >> fId && ifs >> fName && ifs >> fPwd) // ��һ����Ϣ�𿪶���fId/fName/fPwd��
		{
			// ����
			// cout << fId << ":" << fName << "-" << fPwd << endl;
			if (id == fId && name == fName && pwd == fPwd)
			{
				cout << "ѧ����֤��¼�ɹ���" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd); // ����ѧ���࣬�ø�ָ��ָ��
				// ����ѧ�����Ӳ˵�

				return;
			}

		}
	}
	else if (type == 2)
	{
		// ��ʦ��¼��֤
		int fId;
		string fName;
		string fPwd;
		// ѭ����ȡ�ļ��е����ݣ�ֱ�����꣬���Ƿ�����ͬ���û���������
		while (ifs >> fId && ifs >> fName && ifs >> fPwd) // ��һ����Ϣ�𿪶���fId/fName/fPwd��
		{
			// ����
			// cout << fId << ":" << fName << "-" << fPwd << endl;
			if (id == fId && name == fName && pwd == fPwd)
			{
				cout << "��ʦ��֤��¼�ɹ���" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd); // ������ʦ�࣬�ø�ָ��ָ��
				// ������ʦ���Ӳ˵�

				return;
			}
		}
	}
	else if(type == 3)
	{
		// ����Ա��¼��֤
		string fName;
		string fPwd;
		// ѭ����ȡ�ļ��е����ݣ�ֱ�����꣬���Ƿ�����ͬ���û���������
		while (ifs >> fName && ifs >> fPwd) // ��һ����Ϣ�𿪶���fId/fName/fPwd��
		{
			// ����
			// cout << fId << ":" << fName << "-" << fPwd << endl;
			if (name == fName && pwd == fPwd)
			{
				cout << "����Ա��֤��¼�ɹ���" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd); // ��������Ա�࣬�ø�ָ��ָ��
				// �������Ա���Ӳ˵�
				managerMenu(person);
				return;
			}

		}
	}
	cout << "��֤��¼ʧ�ܣ�" << endl;
	system("pause");
	system("cls");
	return;
};

int main()
{
	int select;
	while(true)
	{
		cout << "=======================  ��ӭ��������ԤԼϵͳ =======================" << endl;
		cout << endl << "�������������" << endl;
		cout << "\t\t ------------------------------- \n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|        1.ѧ������             |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|        2.��    ʦ             |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|        3.�� �� Ա             |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|        0.��    ��             |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t ------------------------------- \n";


		cin >> select;
		switch (select)
		{
		case 1:
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2:
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3:
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0:
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "������������������" << endl;
			system("pause");
			system("cls");
			break;
		};
	}

	system("pause");
	return 0;
};