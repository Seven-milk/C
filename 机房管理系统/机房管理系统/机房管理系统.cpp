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
		// 管理员菜单
		manager->operMenu();

		Manager* man = (Manager*)manager; // 父类强转为子类

		int select = 0;
		cin >> select;

		if (select == 1) // 添加账号
		{
			cout << "添加账号" << endl;
			man->addPerson();
		}
		else if (select == 2) // 查看账号
		{
			cout << "查看账号" << endl;
			man->showPerson();
		}
		else if (select == 3) // 查看机房
		{
			cout << "查看机房" << endl;
			man->showComputer();
		}
		else if (select == 4) // 清空预约
		{
			cout << "清空预约" << endl;
			man->cleanFile();
		}
		else
		{
			delete manager;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

void LoginIn(string fileName, int type)
{
	Identity* person = NULL; // 父类指针用于指向子类对象

	ifstream ifs; // 读文件，看是否有这样的人
	ifs.open(fileName, ios::in);

	// 文件不存在
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	};

	// 准备变量用于存储从文件读取的信息
	int id = 0;
	string name;
	string pwd;

	// 基于type判断成员类型，如果是学生或老师，需要输入学工号，如果是管理员，则不管
	if (type == 1) // 学生登录
	{
		cout << "请输入学号" << endl;
		cin >> id;
	}
	else if (type == 2) // 老师登录
	{
		cout << "请输入职工号" << endl;
		cin >> id;
	}

	// 不管什么类型，都需要用户名和密码才能登录
	cout << "请输入用户名：" << endl;
	cin >> name;

	cout << "请输入密码：" << endl;
	cin >> pwd;

	// 验证登录，如果成功进入对应接口，否则输出登录失败
	if (type == 1)
	{
		// 学生登录验证
		int fId;
		string fName;
		string fPwd;
		// 循环读取文件中的内容，直到读完，看是否有相同的用户名和密码
		while (ifs >> fId && ifs >> fName && ifs >> fPwd) // 将一行信息拆开读到fId/fName/fPwd中
		{
			// 测试
			// cout << fId << ":" << fName << "-" << fPwd << endl;
			if (id == fId && name == fName && pwd == fPwd)
			{
				cout << "学生验证登录成功！" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd); // 创建学生类，让父指针指向
				// 进入学生类子菜单

				return;
			}

		}
	}
	else if (type == 2)
	{
		// 老师登录验证
		int fId;
		string fName;
		string fPwd;
		// 循环读取文件中的内容，直到读完，看是否有相同的用户名和密码
		while (ifs >> fId && ifs >> fName && ifs >> fPwd) // 将一行信息拆开读到fId/fName/fPwd中
		{
			// 测试
			// cout << fId << ":" << fName << "-" << fPwd << endl;
			if (id == fId && name == fName && pwd == fPwd)
			{
				cout << "老师验证登录成功！" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd); // 创建老师类，让父指针指向
				// 进入老师类子菜单

				return;
			}
		}
	}
	else if(type == 3)
	{
		// 管理员登录验证
		string fName;
		string fPwd;
		// 循环读取文件中的内容，直到读完，看是否有相同的用户名和密码
		while (ifs >> fName && ifs >> fPwd) // 将一行信息拆开读到fId/fName/fPwd中
		{
			// 测试
			// cout << fId << ":" << fName << "-" << fPwd << endl;
			if (name == fName && pwd == fPwd)
			{
				cout << "管理员验证登录成功！" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd); // 创建管理员类，让父指针指向
				// 进入管理员类子菜单
				managerMenu(person);
				return;
			}

		}
	}
	cout << "验证登录失败！" << endl;
	system("pause");
	system("cls");
	return;
};

int main()
{
	int select;
	while(true)
	{
		cout << "=======================  欢迎来到机房预约系统 =======================" << endl;
		cout << endl << "请输入您的身份" << endl;
		cout << "\t\t ------------------------------- \n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|        1.学生代表             |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|        2.老    师             |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|        3.管 理 员             |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|        0.退    出             |\n";
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
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "输入有误，请重新输入" << endl;
			system("pause");
			system("cls");
			break;
		};
	}

	system("pause");
	return 0;
};