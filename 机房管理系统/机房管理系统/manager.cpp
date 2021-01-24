#include "manager.h";

// 默认无参构造
Manager::Manager()
{
	//this->initVector();
};

// 有参构造
Manager::Manager(string name, string pwd)
{
	this->m_Name = name;
	this->m_Pwd = pwd;
	// 初始化容器，读取学生、老师信息
	this->initVector();
	// 初始化机房，读取机房信息
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	ComputerRoom c;
	while (ifs >> c.m_ComId && ifs >> c.m_MaxNum)
	{
		this->vCom.push_back(c);
	}
	// 测试
	//cout << "当前机房数量为：" << this->vCom.size() << endl;
	ifs.close();
};

// 菜单界面重写
void Manager::operMenu() 
{
	cout << "==========  欢迎管理员 " << this->m_Name << "登陆！ ==========" << endl;
	cout << "\t\t ------------------------------- \n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|        1.添加账号             |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|        2.查看账号             |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|        3.查看机房             |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|        4.清空预约             |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|        0.注销登录             |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t ------------------------------- \n";
	cout << "请选择您的操作：" << endl;
};

// 添加账号
void Manager::addPerson()
{
	cout << "请输入添加账号的类型" << endl;
	cout << "1.添加学生" << endl;
	cout << "2.添加老师" << endl;

	string fileName; // 要打开的文件名，根据类型不同而不同
	string tip; // 提示信息，根据类型不同而不同
	string errorTip;
	ofstream ofs;
	int select = 0;
	cin >> select;

	if (select == 1)
	{
		fileName = STUDENT_FILE;
		tip = "请输入学号：";
		errorTip = "学号重复，请重新输入";
	}
	else
	{
		fileName = TEACHER_FILE;
		tip = "请输入工号：";
		errorTip = "工号重复，请重新输入";
	}

	// 打开文件，append方式输入文件
	ofs.open(fileName, ios::out | ios::app);
	int id;
	string name;
	string pwd;
	cout << tip << endl;

	while(true)
	{
		cin >> id;
		bool ret = this->checkRepeat(id, select);
		if (ret) // 有重复,输出errortip，继续重新输入
		{
			cout << errorTip << endl;
		}
		else // 无重复，跳出循环
		{
			break;
		}
	}
	cout << "请输入姓名：" << endl;
	cin >> name;
	cout << "请输入密码：" << endl;
	cin >> pwd;

	// 写入文件
	ofs << id << " " << name << " " << pwd << endl;
	cout << "添加成功" << endl;

	system("pause");
	system("cls");
	ofs.close();

	// 重新初始化容器，将刚添加的账号及时更新到容器
	this->initVector();
};

// 打印学生
void printStudent(Student  &s)
{
	cout << "学号：" << s.m_Id << " 姓名：" << s.m_Name << " 密码：" << s.m_Pwd << endl;
};

// 打印老师
void printTeacher(Teacher &t)
{
	cout << " 工号：" << t.m_empId << " 姓名：" << t.m_Name << " 密码：" << t.m_Pwd << endl;
};

// 查看账号
void Manager::showPerson()
{
	cout << "请选择查看内容：" << endl;
	cout << "1.查看所有学生" << endl;
	cout << "2.查看所有老师" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		cout << "所有学生信息如下" << endl;
		for_each(this->vStu.begin(), this->vStu.end(), printStudent);
	}
	else
	{
		cout << "所有老师信息如下" << endl;
		for_each(this->vTea.begin(), this->vTea.end(), printTeacher);
	}
	system("pause");
	system("cls");
};

// 查看机房信息
void Manager::showComputer()
{
	cout << "机房信息如下：" << endl;
	for (vector<ComputerRoom>::iterator it = this->vCom.begin(); it != this->vCom.end(); it++)
	{
		cout << "机房编号：" << it->m_ComId << " " << "机房电脑数目" << it->m_MaxNum << endl;
	};
	system("pause");
	system("cls");
};

// 清空预约记录
void Manager::cleanFile()
{
	ofstream ofs(ORDER_FILE, ios::trunc); // 清空方式打开
	ofs.close();

	cout << "清空成功" << endl;
	system("pause");
	system("cls");
};

// 初始化容器
void Manager::initVector()
{
	// 清空容器
	this->vStu.clear();
	this->vTea.clear();

	// 读取学生文件信息
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件读取失败" << endl;
		return;
	};

	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd)
	{
		this->vStu.push_back(s);
	};
	// 测试
	// cout << "当前学生数量为: " << this->vStu.size() << endl;
	ifs.close();

	// 读取老师文件中信息
	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件读取失败" << endl;
		return;
	};

	Teacher t;
	while (ifs >> t.m_empId && ifs >> t.m_Name && ifs >> t.m_Pwd)
	{
		this->vTea.push_back(t);
	};
	// 测试
	// cout << "当前老师数量为: " << this->vTea.size() << endl;
	ifs.close();

};

// 检查重复
bool Manager::checkRepeat(int id, int type)
{
	if (type == 1) // 学生类
	{
		for (vector<Student>::iterator it = this->vStu.begin(); it != this->vStu.end(); it++)
		{
			if (id == it->m_Id)
			{
				return true;
			}
		};
	}
	else // 老师类
	{
		for (vector<Teacher>::iterator it = this->vTea.begin(); it != this->vTea.end(); it++)
		{
			if (id == it->m_empId)
			{
				return true;
			}
		};
	}
	return false; // 均不满足，即前面没有return回去，就return false
};