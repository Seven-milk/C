#include <iostream>
#include<string>
#include"workerManager.h"
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"

using namespace std;

void test01()
{
	Worker* worker = NULL;
	worker = new Employee(1, "����", 1);
	worker->showInfo();
	delete worker;

	worker = new Manager(2, "����", 2);
	worker->showInfo();
	delete worker;

	worker = new Boss(3, "����", 3);
	worker->showInfo();
	delete worker;
}

int main()
{
	WorkerManager wm;
	int choice;

	test01();
	while (true)
	{
		// չʾ�˵�
		wm.Show_Menu();
		cout << "����������ѡ��" << endl;
		cin >> choice;

		// ��֧
		switch (choice)
		{
		case 0: // �˳�ϵͳ
			wm.exitSystem();
			break;
		case 1: // ���ְ��
			break;
		case 2: // ��ʾְ��
			break;
		case 3: // ɾ��ְ��
			break;
		case 4: // �޸�ְ��
			break;
		case 5: // ����ְ��
			break;
		case 6: // ���������
			break;
		case 7: // ����ĵ�
			break;
		}
	}

	
	system("pause");//�����������

	return 0;//�˳�

}