#include "workerManager.h" // ����ͷ�ļ�


WorkerManager::WorkerManager()
{
	// ��ʼ������
	this->m_EmpNum = 0;
	this->m_EmpArray = NULL;
};

void WorkerManager::Show_Menu()
{
	cout << "******************************" << endl;
	cout << "***  ��ӭʹ��ְ������ϵͳ  ***" << endl;
	cout << "*****  0.�Ƴ�������� ********" << endl;
	cout << "*****  1.����ְ����Ϣ ********" << endl;
	cout << "*****  2.��ʾְ����Ϣ ********" << endl;
	cout << "*****  3.ɾ����ְְ�� ********" << endl;
	cout << "*****  4.�޸�ְ����Ϣ ********" << endl;
	cout << "*****  5.����ְ����Ϣ ********" << endl;
	cout << "*****  6.���ձ������ ********" << endl;
	cout << "*****  7.��������ĵ� ********" << endl;
	cout << "******************************" << endl;
};

void WorkerManager::exitSystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}

void WorkerManager::Add_Emp()
{
	cout << "����������Ա������:" << endl;
	int addNum = 0;
	cin >> addNum;

	if (addNum > 0)
	{
		// �����¿ռ��С
		int newSize = this->m_EmpNum + addNum;

		// �����¿ռ�
		Worker** newSpace = new Worker * [newSize];

		// ���ԭ�������鲻Ϊ�գ���ԭ�ռ��µ����ݴ�ŵ��¿ռ���
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}
		
		// ����������
		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int dSelect;

			cout << "���������ݵ�" << i + 1 << "��ְ�����:" << endl;
			cin >> id;
			cout << "���������ݵ�" << i + 1 << "��ְ������:" << endl;
			cin >> name;
			cout << "��ѡ���ְ����λ:" << endl;
			cout << "1.��ְͨ��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;
			cin >> dSelect;
		

		// ���ݲ�ͬ��ְ�����ͣ�������ͬ��worker����

		Worker* worker = NULL; // ����һ��Workerָ��(worker)����ŵ�ַ
		switch (dSelect)
		{
		case 1: // ��ͨԱ��
			worker = new Employee(id, name, 1);
			break;
		
		case 2: // ����
			worker = new Manager(id, name, 2);
			break;
		
		case 3: // �ϰ�
			worker = new Boss(id, name, 3);
			break;
		}

		// ��������ְ�����浽������
		newSpace[this->m_EmpNum + i] = worker;

		// �ͷ�ԭ�пռ�
		delete[] this->m_EmpArray;

		// ����ԭ�пռ�ָ��
		this->m_EmpArray = newSpace;

		// ���¸���
		this->m_EmpNum = newSize;

		// ��ʾ��Ϣ
		cout << "������" << addNum << "��Ա����" << endl;

		};

	}
	else
	{
		cout << "��������" << endl;
	}

	// ����������������ص��ϼ�Ŀ¼
	system("pause");
	system("cls");
}

WorkerManager::~WorkerManager(){};