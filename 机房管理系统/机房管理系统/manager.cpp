#include "manager.h";

// Ĭ���޲ι���
Manager::Manager()
{
	//this->initVector();
};

// �вι���
Manager::Manager(string name, string pwd)
{
	this->m_Name = name;
	this->m_Pwd = pwd;
	// ��ʼ����������ȡѧ������ʦ��Ϣ
	this->initVector();
	// ��ʼ����������ȡ������Ϣ
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	ComputerRoom c;
	while (ifs >> c.m_ComId && ifs >> c.m_MaxNum)
	{
		this->vCom.push_back(c);
	}
	// ����
	//cout << "��ǰ��������Ϊ��" << this->vCom.size() << endl;
	ifs.close();
};

// �˵�������д
void Manager::operMenu() 
{
	cout << "==========  ��ӭ����Ա " << this->m_Name << "��½�� ==========" << endl;
	cout << "\t\t ------------------------------- \n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|        1.����˺�             |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|        2.�鿴�˺�             |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|        3.�鿴����             |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|        4.���ԤԼ             |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|        0.ע����¼             |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t ------------------------------- \n";
	cout << "��ѡ�����Ĳ�����" << endl;
};

// ����˺�
void Manager::addPerson()
{
	cout << "����������˺ŵ�����" << endl;
	cout << "1.���ѧ��" << endl;
	cout << "2.�����ʦ" << endl;

	string fileName; // Ҫ�򿪵��ļ������������Ͳ�ͬ����ͬ
	string tip; // ��ʾ��Ϣ���������Ͳ�ͬ����ͬ
	string errorTip;
	ofstream ofs;
	int select = 0;
	cin >> select;

	if (select == 1)
	{
		fileName = STUDENT_FILE;
		tip = "������ѧ�ţ�";
		errorTip = "ѧ���ظ�������������";
	}
	else
	{
		fileName = TEACHER_FILE;
		tip = "�����빤�ţ�";
		errorTip = "�����ظ�������������";
	}

	// ���ļ���append��ʽ�����ļ�
	ofs.open(fileName, ios::out | ios::app);
	int id;
	string name;
	string pwd;
	cout << tip << endl;

	while(true)
	{
		cin >> id;
		bool ret = this->checkRepeat(id, select);
		if (ret) // ���ظ�,���errortip��������������
		{
			cout << errorTip << endl;
		}
		else // ���ظ�������ѭ��
		{
			break;
		}
	}
	cout << "������������" << endl;
	cin >> name;
	cout << "���������룺" << endl;
	cin >> pwd;

	// д���ļ�
	ofs << id << " " << name << " " << pwd << endl;
	cout << "��ӳɹ�" << endl;

	system("pause");
	system("cls");
	ofs.close();

	// ���³�ʼ��������������ӵ��˺ż�ʱ���µ�����
	this->initVector();
};

// ��ӡѧ��
void printStudent(Student  &s)
{
	cout << "ѧ�ţ�" << s.m_Id << " ������" << s.m_Name << " ���룺" << s.m_Pwd << endl;
};

// ��ӡ��ʦ
void printTeacher(Teacher &t)
{
	cout << " ���ţ�" << t.m_empId << " ������" << t.m_Name << " ���룺" << t.m_Pwd << endl;
};

// �鿴�˺�
void Manager::showPerson()
{
	cout << "��ѡ��鿴���ݣ�" << endl;
	cout << "1.�鿴����ѧ��" << endl;
	cout << "2.�鿴������ʦ" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		cout << "����ѧ����Ϣ����" << endl;
		for_each(this->vStu.begin(), this->vStu.end(), printStudent);
	}
	else
	{
		cout << "������ʦ��Ϣ����" << endl;
		for_each(this->vTea.begin(), this->vTea.end(), printTeacher);
	}
	system("pause");
	system("cls");
};

// �鿴������Ϣ
void Manager::showComputer()
{
	cout << "������Ϣ���£�" << endl;
	for (vector<ComputerRoom>::iterator it = this->vCom.begin(); it != this->vCom.end(); it++)
	{
		cout << "������ţ�" << it->m_ComId << " " << "����������Ŀ" << it->m_MaxNum << endl;
	};
	system("pause");
	system("cls");
};

// ���ԤԼ��¼
void Manager::cleanFile()
{
	ofstream ofs(ORDER_FILE, ios::trunc); // ��շ�ʽ��
	ofs.close();

	cout << "��ճɹ�" << endl;
	system("pause");
	system("cls");
};

// ��ʼ������
void Manager::initVector()
{
	// �������
	this->vStu.clear();
	this->vTea.clear();

	// ��ȡѧ���ļ���Ϣ
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ȡʧ��" << endl;
		return;
	};

	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd)
	{
		this->vStu.push_back(s);
	};
	// ����
	// cout << "��ǰѧ������Ϊ: " << this->vStu.size() << endl;
	ifs.close();

	// ��ȡ��ʦ�ļ�����Ϣ
	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ȡʧ��" << endl;
		return;
	};

	Teacher t;
	while (ifs >> t.m_empId && ifs >> t.m_Name && ifs >> t.m_Pwd)
	{
		this->vTea.push_back(t);
	};
	// ����
	// cout << "��ǰ��ʦ����Ϊ: " << this->vTea.size() << endl;
	ifs.close();

};

// ����ظ�
bool Manager::checkRepeat(int id, int type)
{
	if (type == 1) // ѧ����
	{
		for (vector<Student>::iterator it = this->vStu.begin(); it != this->vStu.end(); it++)
		{
			if (id == it->m_Id)
			{
				return true;
			}
		};
	}
	else // ��ʦ��
	{
		for (vector<Teacher>::iterator it = this->vTea.begin(); it != this->vTea.end(); it++)
		{
			if (id == it->m_empId)
			{
				return true;
			}
		};
	}
	return false; // �������㣬��ǰ��û��return��ȥ����return false
};