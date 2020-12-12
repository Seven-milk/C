#include <iostream>
#include "ͨѶ¼����ϵͳ.h"
using namespace std;

#define Max 1000 // �곣���������ά��
struct Contacts {
	string name;
	int sex; // 1 �� 2 Ů
	int age;
	string phone;
	string address;
};

struct Address_contacts {
	Contacts contacts[Max];
	int size; // ����
};

void add_address(Address_contacts *address_contacts){
	string name;
	int sex; // 1 �� 2 Ů
	int age;
	string phone;
	string address;
	if (address_contacts->size == Max) {
		cout << "ͨѶ¼�������޷�������ӣ�" << endl;
		return;
	}
	else{
		cout << "����������: ";
		cin >> name;
		while (true) {
			cout << "�������Ա�: " << endl;
			cout << "�� -- 1" << endl;
			cout << "Ů -- 2" << endl;
			cin >> sex;
			if (sex == 1 || sex == 2) {
				break;
			}
			else {
				cout << "������������������" << endl;
			}
		}
		cout << "����������: ";
		cin >> age;
		cout << "������绰����: ";
		cin >> phone;
		cout << "�������ַ: ";
		cin >> address;
		address_contacts->contacts[address_contacts->size] = { name, sex, age, phone, address };
		address_contacts->size += 1;
		cout << "��ӳɹ���" << endl;
		system("pause");
		system("cls");
	}
}

void show_address(Address_contacts address_contacts) {
	for (int i = 0; i < address_contacts.size; i++) {
		cout << "����: " << address_contacts.contacts[i].name << " ";
		cout << "�Ա�: " << (address_contacts.contacts[i].sex == 1 ? "��" : "Ů" ) << " ";
		cout << "����: " << address_contacts.contacts[i].age << " ";
		cout << "�绰����: " << address_contacts.contacts[i].phone << " ";
		cout << "��ַ: " << address_contacts.contacts[i].address << " ";
		cout << endl;
	};
	system("pause");
	system("cls");
}

int Is_exist(Address_contacts address_contacts, string name_del) {
	int index_;
	for (int i = 0; i < address_contacts.size; i++) {
		if (address_contacts.contacts[i].name == name_del) {
			index_ = i;
			return index_;
		}
	}
	index_ = -1;
	return index_;
}

void Del_contacts(Address_contacts * address_contacts, int index_) {
	for (int i = index_; i < address_contacts->size; i++)
	{
		address_contacts->contacts[i] = address_contacts->contacts[i + 1]; //����ǰ�ƣ�ɾ������
	}
	address_contacts->size--;
}

void Modify_address(Address_contacts* address_contacts, int index_) {
	string name;
	int sex; // 1 �� 2 Ů
	int age;
	string phone;
	string address;
	cout << "����������: ";
	cin >> name;
	while (true) {
		cout << "�������Ա�: " << endl;
		cout << "�� -- 1" << endl;
		cout << "Ů -- 2" << endl;
		cin >> sex;
		if (sex == 1 || sex == 2) {
			break;
		}
		else {
			cout << "������������������" << endl;
		}
	}
	cout << "����������: ";
	cin >> age;
	cout << "������绰����: ";
	cin >> phone;
	cout << "�������ַ: ";
	cin >> address;
	address_contacts->contacts[index_] = { name, sex, age, phone, address };
	cout << "�޸ĳɹ���" << endl;
	system("pause");
	system("cls");
}

int main()
{
	int select = 0;
	Address_contacts address_contacts;
	address_contacts.size = 0; // ��ʼ��
	while (1) {
		showMenu();
		cin >> select;
		switch (select) {
		case 0:
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break; // �˳�ͨѶ¼
		case 1:
			add_address(&address_contacts);
			break; // �����ϵ��
		case 2:
			show_address(address_contacts);
			break; // ��ʾ��ϵ��
		case 3:
		{
			string name_del;
			int index_;
			cout << "������Ҫɾ��������: ";
			cin >> name_del;
			index_ = Is_exist(address_contacts, name_del);
			if (index_ == -1) {
				cout << "��������������ڣ�";
			}
			else {
				Del_contacts(&address_contacts, index_);
				cout << "ɾ���ɹ���" << endl;
			}
			system("pause");
			system("cls");
		}
			break; // ɾ����ϵ��
		case 4:
		{
			string name_del;
			int index_;
			cout << "������Ҫ���ҵ�����: ";
			cin >> name_del;
			index_ = Is_exist(address_contacts, name_del);
			if (index_ == -1) {
				cout << "��������������ڣ�";
			}
			else {
				cout << "����: " << address_contacts.contacts[index_].name << " ";
				cout << "�Ա�: " << (address_contacts.contacts[index_].sex == 1 ? "��" : "Ů") << " ";
				cout << "����: " << address_contacts.contacts[index_].age << " ";
				cout << "�绰����: " << address_contacts.contacts[index_].phone << " ";
				cout << "��ַ: " << address_contacts.contacts[index_].address << " ";
				cout << endl;
			}
			system("pause");
			system("cls");
		}
			break; // ������ϵ��
		case 5: 
		{
			string name_del;
			int index_;
			cout << "������Ҫ�޸ĵ�����: ";
			cin >> name_del;
			index_ = Is_exist(address_contacts, name_del);
			if (index_ == -1) {
				cout << "��������������ڣ�";
			}
			else {
				Modify_address(&address_contacts, index_);
			}
		}
			break; // �޸���ϵ��
		case 6:
			int yes_;
			while (true) {
				cout << "��ȷ���Ƿ����ͨѶ¼��0���񣩣�1���ǣ�" << endl;
				cin >> yes_;
				if (yes_ == 0){
					break;
				}
				else if (yes_ == 1) {
					address_contacts.size = 0;
					cout << "�����ɣ�" << endl;
					break;
				}
				else {
					cout << "������0��1" << endl;
				}
			}
			system("pause");
			system("cls");
			break; // ���ͨѶ¼
		}
	};
	

	system("pause");

	return 0;

}