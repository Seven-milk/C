#include <iostream>
#include "通讯录管理系统.h"
using namespace std;

#define Max 1000 // 宏常量方便后期维护
struct Contacts {
	string name;
	int sex; // 1 男 2 女
	int age;
	string phone;
	string address;
};

struct Address_contacts {
	Contacts contacts[Max];
	int size; // 人数
};

void add_address(Address_contacts *address_contacts){
	string name;
	int sex; // 1 男 2 女
	int age;
	string phone;
	string address;
	if (address_contacts->size == Max) {
		cout << "通讯录已满，无法继续添加！" << endl;
		return;
	}
	else{
		cout << "请输入姓名: ";
		cin >> name;
		while (true) {
			cout << "请输入性别: " << endl;
			cout << "男 -- 1" << endl;
			cout << "女 -- 2" << endl;
			cin >> sex;
			if (sex == 1 || sex == 2) {
				break;
			}
			else {
				cout << "输入有误！请重新输入" << endl;
			}
		}
		cout << "请输入年龄: ";
		cin >> age;
		cout << "请输入电话号码: ";
		cin >> phone;
		cout << "请输入地址: ";
		cin >> address;
		address_contacts->contacts[address_contacts->size] = { name, sex, age, phone, address };
		address_contacts->size += 1;
		cout << "添加成功！" << endl;
		system("pause");
		system("cls");
	}
}

void show_address(Address_contacts address_contacts) {
	for (int i = 0; i < address_contacts.size; i++) {
		cout << "姓名: " << address_contacts.contacts[i].name << " ";
		cout << "性别: " << (address_contacts.contacts[i].sex == 1 ? "男" : "女" ) << " ";
		cout << "年龄: " << address_contacts.contacts[i].age << " ";
		cout << "电话号码: " << address_contacts.contacts[i].phone << " ";
		cout << "地址: " << address_contacts.contacts[i].address << " ";
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
		address_contacts->contacts[i] = address_contacts->contacts[i + 1]; //数据前移，删除数据
	}
	address_contacts->size--;
}

void Modify_address(Address_contacts* address_contacts, int index_) {
	string name;
	int sex; // 1 男 2 女
	int age;
	string phone;
	string address;
	cout << "请输入姓名: ";
	cin >> name;
	while (true) {
		cout << "请输入性别: " << endl;
		cout << "男 -- 1" << endl;
		cout << "女 -- 2" << endl;
		cin >> sex;
		if (sex == 1 || sex == 2) {
			break;
		}
		else {
			cout << "输入有误！请重新输入" << endl;
		}
	}
	cout << "请输入年龄: ";
	cin >> age;
	cout << "请输入电话号码: ";
	cin >> phone;
	cout << "请输入地址: ";
	cin >> address;
	address_contacts->contacts[index_] = { name, sex, age, phone, address };
	cout << "修改成功！" << endl;
	system("pause");
	system("cls");
}

int main()
{
	int select = 0;
	Address_contacts address_contacts;
	address_contacts.size = 0; // 初始化
	while (1) {
		showMenu();
		cin >> select;
		switch (select) {
		case 0:
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break; // 退出通讯录
		case 1:
			add_address(&address_contacts);
			break; // 添加联系人
		case 2:
			show_address(address_contacts);
			break; // 显示联系人
		case 3:
		{
			string name_del;
			int index_;
			cout << "请输入要删除的人名: ";
			cin >> name_del;
			index_ = Is_exist(address_contacts, name_del);
			if (index_ == -1) {
				cout << "输入的人名不存在！";
			}
			else {
				Del_contacts(&address_contacts, index_);
				cout << "删除成功！" << endl;
			}
			system("pause");
			system("cls");
		}
			break; // 删除联系人
		case 4:
		{
			string name_del;
			int index_;
			cout << "请输入要查找的人名: ";
			cin >> name_del;
			index_ = Is_exist(address_contacts, name_del);
			if (index_ == -1) {
				cout << "输入的人名不存在！";
			}
			else {
				cout << "姓名: " << address_contacts.contacts[index_].name << " ";
				cout << "性别: " << (address_contacts.contacts[index_].sex == 1 ? "男" : "女") << " ";
				cout << "年龄: " << address_contacts.contacts[index_].age << " ";
				cout << "电话号码: " << address_contacts.contacts[index_].phone << " ";
				cout << "地址: " << address_contacts.contacts[index_].address << " ";
				cout << endl;
			}
			system("pause");
			system("cls");
		}
			break; // 查找联系人
		case 5: 
		{
			string name_del;
			int index_;
			cout << "请输入要修改的人名: ";
			cin >> name_del;
			index_ = Is_exist(address_contacts, name_del);
			if (index_ == -1) {
				cout << "输入的人名不存在！";
			}
			else {
				Modify_address(&address_contacts, index_);
			}
		}
			break; // 修改联系人
		case 6:
			int yes_;
			while (true) {
				cout << "请确认是否清空通讯录：0（否）；1（是）" << endl;
				cin >> yes_;
				if (yes_ == 0){
					break;
				}
				else if (yes_ == 1) {
					address_contacts.size = 0;
					cout << "清空完成！" << endl;
					break;
				}
				else {
					cout << "请输入0或1" << endl;
				}
			}
			system("pause");
			system("cls");
			break; // 清除通讯录
		}
	};
	

	system("pause");

	return 0;

}