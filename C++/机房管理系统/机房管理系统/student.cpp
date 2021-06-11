#include "student.h"

// Ĭ�Ϲ���
Student::Student() 
{

};

// �вι���
Student::Student(int id, string name, string pwd)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_Pwd = pwd;

	// ��ȡ������Ϣ
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);

	ComputerRoom c;
	while (ifs >> c.m_ComId && ifs >> c.m_MaxNum)
	{
		this->vCom.push_back(c);
	}
	ifs.close();
};

// �˵�����
void Student::operMenu()
{
	cout << "==========  ��ӭѧ������ " << this->m_Name << "��½�� ==========" << endl;
	cout << "\t\t ------------------------------- \n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|        1.����ԤԼ             |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|        2.�鿴�ҵ�ԤԼ         |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|        3.�鿴����ԤԼ         |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|        4.ȡ��ԤԼ             |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|        0.ע����¼             |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t ------------------------------- \n";
	cout << "��ѡ�����Ĳ�����" << endl;
};

// ����ԤԼ
void Student::applyOrder()
{
	// ����ʱ��date���ж�ʱ��������ȷ���
	cout << "��������ʱ��Ϊ��һ������" << endl;
	cout << "����������ԤԼ��ʱ�䣺" << endl;
	cout << "1.��һ" << endl;
	cout << "2.�ܶ�" << endl;
	cout << "3.����" << endl;
	cout << "4.����" << endl;
	cout << "5.����" << endl;
	int date = 0;
	int interval = 0;
	int room = 0;
	
	while (true)
	{
		cin >> date;
		if (date >= 1 && date <= 5)
		{
			break;
		}
		cout << "�����������������" << endl;
	}

	// ����ʱ���interval���ж�ʱ���������ȷ���
	cout << "������ԤԼ��ʱ���" << endl;
	cout << "1.����" << endl;
	cout << "2.����" << endl;
	
	while (true)
	{
		cin >> interval;
		if (interval >= 1 && interval <= 2)
		{
			break;
		}
		cout << "�����������������" << endl;
	}

	// �������room���ж�������ȷ���
	cout << "��ѡ�����" << endl;
	cout << "1�Ż�������" << this->vCom[0].m_MaxNum << endl;
	cout << "2�Ż�������" << this->vCom[1].m_MaxNum << endl;
	cout << "3�Ż�������" << this->vCom[2].m_MaxNum << endl;

	while (true)
	{
		cin >> room;
		if (room >= 1 && room <= 3)
		{
			break;
		}
		cout << "�����������������" << endl;
	}

	cout << "ԤԼ�ɹ�������У�" << endl;

	// ��ԤԼ��Ϣ�����ļ�ORDER_FILE��append��ʽ����
	ofstream ofs(ORDER_FILE, ios::app);
	ofs << "date:" << date << " ";
	ofs << "interval:" << interval << " ";
	ofs << "stuId:" << this->m_Id << " ";
	ofs << "stuName:" << this->m_Name << " ";
	ofs << "roomId:" << room << " ";
	ofs << "status:" << 1 << endl;
	ofs.close();
	system("pause");
	system("cls");
};

// �鿴�Լ�ԤԼ
void Student::showMyOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < of.m_Size; i++)
	{
		// ֻ��ʾ��������Ϣ���ж��Ƿ�Ϊ����
		if (atoi(of.m_orderData[i]["stuId"].c_str()) == this->m_Id) // ��stuIdתΪ������m_Id�����ж�
		{
			cout << "ԤԼ���ڣ� ��" << of.m_orderData[i]["date"];
			cout << "ʱ�Σ�" << (of.m_orderData[i]["interval"] == "1" ? "����" : "����");  // ��Ԫ�������ת������
			cout << "������" << of.m_orderData[i]["roomId"];
			string status = "״̬��"; // 0 ȡ����ԤԼ�� 1 ����У� 2 ��ԤԼ�� -1 ԤԼʧ��
			if (of.m_orderData[i]["status"] == "1")
			{
				status += "�����";
			}
			else if (of.m_orderData[i]["status"] == "2")
			{
				status += "��ԤԼ";
			}
			else if (of.m_orderData[i]["status"] == "-1")
			{
				status += "ԤԼʧ��";
			}
			else
			{
				status += "ԤԼ��ȡ��";
			}
			cout << status << endl;
		}
	}
	system("pause");
	system("cls");
};

// �鿴����ԤԼ
void Student::showAllOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < of.m_Size; i++)
	{
		cout << i + 1 << "��";
		cout << "ԤԼ���ڣ���" << of.m_orderData[i]["date"];
		cout << " ʱ�Σ�" << (of.m_orderData[i]["interval"] == "1" ? "����" : "����");  // ��Ԫ�������ת������
		cout << " ѧ�ţ�" << of.m_orderData[i]["stuId"];
		cout << " ������" << of.m_orderData[i]["stuName"];
		cout << " ������" << of.m_orderData[i]["roomId"];
		string status = " ״̬��"; // 0 ȡ����ԤԼ�� 1 ����У� 2 ��ԤԼ�� -1 ԤԼʧ��
		if (of.m_orderData[i]["status"] == "1")
		{
			status += "�����";
		}
		else if (of.m_orderData[i]["status"] == "2")
		{
			status += "��ԤԼ";
		}
		else if (of.m_orderData[i]["status"] == "-1")
		{
			status += "ԤԼʧ��";
		}
		else
		{
			status += "ԤԼ��ȡ��";
		}
		cout << status << endl;

	}
	system("pause");
	system("cls");
};

// ȡ��ԤԼ
void Student::cancelOrder()
{
	OrderFile of;
	// �ж��Ƿ�Ϊ��
	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "����л�ԤԼ�ɹ��ļ�¼����ȡ����������ȡ���ļ�¼" << endl;

	vector<int>v; // �ݴ��Լ�����ԤԼ����m_orderData���ǵڼ����������ж�����
	int index = 1;
	for (int i = 0; i < of.m_Size; i++) 
	{
		// �������м�¼���ҵ��Լ���
		if (atoi(of.m_orderData[i]["stuId"].c_str()) == this->m_Id)
		{
			// ���Լ���¼��m_orderData�е���������v����
			v.push_back(i);

			// ����Լ�ԤԼ����Ϣ
			cout << index++ << "��";
			cout << " ԤԼ���ڣ���" << of.m_orderData[i]["date"];
			cout << " ʱ�Σ�" << (of.m_orderData[i]["interval"] == "1" ? "����" : "����");
			cout << " ������" << of.m_orderData[i]["roomId"];
			string status = " ״̬��"; // 0 ȡ����ԤԼ��1 ����У�2 ��ԤԼ��-1 ԤԼʧ��
			if (of.m_orderData[i]["status"] == "1")
			{
				status += "�����";
			}
			else if (of.m_orderData[i]["status"] == "2")
			{
				status += "��ԤԼ";
			}
			cout << status << endl;
		}
	}

	// ȡ��ԤԼ����ʾ��˳��index->select����ԭ���е�index->v[select-1]
	cout << "������Ҫȡ���ļ�¼��0��ʾ����" << endl;
	int select = 0;
	while (true)
	{
		cin >> select;
		if (select >= 0 && select <= v.size())
		{
			if (select == 0)
			{
				break;
			}
			else
			{
				of.m_orderData[v[select - 1]]["status"] = "0";
				// cout << of.m_orderData[v[select - 1]]["status"]; // ����
				of.updateOrder();
				cout << "��ȡ��ԤԼ" << endl;
				break;
			}
		}
		// ������Χ����������
		cout << "������������������" << endl;
	}
	system("pause");
	system("cls");
};