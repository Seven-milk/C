#include "workerManager.h" // ����ͷ�ļ�


WorkerManager::WorkerManager()
{
	// ��ʼ������:ȥ�·���ʼ��
	//this->m_EmpNum = 0;
	//this->m_EmpArray = NULL;

	// �ж��ļ��Ƿ���ڣ����г�ʼ��
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	// �ļ�������
	if (!ifs.is_open())
	{
		//cout << "�ļ�������" << endl; // �������
		this->m_EmpNum = 0; // ��ʼ������Ϊ0
		this->m_EmpArray = NULL; // ��ʼ������Ϊ��
		this->m_FileIsEmpty = true; // �ļ������ڣ���ʼ��Ϊtrue
		ifs.close();
		return;
	}

	// �ļ����ڣ�����û�м�¼
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//cout << "�ļ�Ϊ��" << endl; // �������
		this->m_EmpNum = 0; // ��ʼ������Ϊ0
		this->m_EmpArray = NULL; // ��ʼ������Ϊ��
		this->m_FileIsEmpty = true; // �ļ����ڵ�û�м�¼����ʼ��Ϊtrue
		ifs.close();
		return;
	}

	// �ļ����ڣ��м�¼����ȡ����
	int num = this->get_EmpNum();
	// cout << "����Ϊ:" << num << endl; // ���Դ���
	this->m_EmpNum = num; // ���³�Ա����

	// �ļ����ڣ��м�¼����ʼ������
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	init_Emp(); // ���ú����������ļ���ʼ������

	// ����
	/*for (int i = 0; i < m_EmpNum; i++)
	{
		cout << "ְ����:" << this->m_EmpArray[i]->m_Id;
		cout << "����:" << this->m_EmpArray[i]->m_Name;
		cout << "���ű��:" << this->m_EmpArray[i]->m_DeptId << endl;
	}*/
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

		// ��������
		this->save();
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

void WorkerManager::save()
{
	ofstream ofs; // ����������
	ofs.open(FILENAME, ios::out); // ���
	
	// ѭ������worker*�����飬����ÿһ��worker�����ָ�루��������Ԫ�أ�ȡ���������ԣ�д��ofs����
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptId << endl;
	};
	
	ofs.close();
}

int WorkerManager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;

	int num = 0;

	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		// ��¼����
		num++;
	};

	ifs.close();
	return num;
}

void WorkerManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;

	int index = 0;

	// ѭ����ȡ�ļ������ݣ�����ʼ����Ա��������
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		Worker* worker = NULL;

		// ���ݲ�ͬ���ʹ�����ͬԱ������
		switch (dId) {
		case 1: // ��ͨԱ��
			worker = new Employee(id, name, dId);
			break;
		case2: // ����
			worker = new Manager(id, name, dId);
			break;
		case 3: // �ϰ�
			worker = new Boss(id, name, dId);
			break;
		}
		// ��ŵ�����
		this->m_EmpArray[index] = worker;
		index++;
	}
}

void WorkerManager::Show_Emp()
{
	//ifstream ifs;
	//ifs.open(FILENAME, ios::in);
	//char ch;
	//ifs >> ch;
	//// �ļ������ڻ�Ϊ��
	//if (ifs.is_open() && !ifs.eof())
	//{
	//	this->m_FileIsEmpty = false;
	//}
	//else
	//{
	//	this->m_FileIsEmpty = true;
	//}

	if (this->m_FileIsEmpty)
	{
		// ���Ϊ��
		cout << "�ļ������ڻ�Ϊ�գ������" << endl;
	}
	else 
	{
		// ��Ϊ�գ���ʾ��Ϣ
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			// ���ö�̬���ýӿ�
			this->m_EmpArray[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}

int WorkerManager::IsExist(int id)
{
	int index = -1;
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_Id == id)
		{
			index = i;
			break;
		}
	}
	return index;
}

void WorkerManager::Del_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ�Ϊ�գ�" << endl;
	}
	else
	{
		int id;
		cout << "������Ҫɾ����Ա��id:";
		cin >> id;
		int index = this->IsExist(id);
		if (index != -1) // �ҵ����ݣ�ɾ��index������������
		{
			// ����ǰ��
			for (int i = index; i < this->m_EmpNum - 1; i++) // m_EmpNum - 1Ϊ���������һ��λ��
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--; // ������һ
			this->save(); // ���浽�ļ�
			cout << "ɾ���ɹ���" << endl;
		}
		else
		{
			cout << "�����Ա����Ų����ڣ�" << endl;
		}
	}

	// �����������
	system("pause");
	system("cls");

}

WorkerManager::~WorkerManager()
{
	if (this->m_EmpArray != NULL)
	{
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
};