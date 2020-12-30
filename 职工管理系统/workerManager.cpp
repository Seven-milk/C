#include "workerManager.h" // 包含头文件


WorkerManager::WorkerManager()
{
	// 初始化人数
	this->m_EmpNum = 0;
	this->m_EmpArray = NULL;
};

void WorkerManager::Show_Menu()
{
	cout << "******************************" << endl;
	cout << "***  欢迎使用职工管理系统  ***" << endl;
	cout << "*****  0.推出管理程序 ********" << endl;
	cout << "*****  1.增加职工信息 ********" << endl;
	cout << "*****  2.显示职工信息 ********" << endl;
	cout << "*****  3.删除离职职工 ********" << endl;
	cout << "*****  4.修改职工信息 ********" << endl;
	cout << "*****  5.查找职工信息 ********" << endl;
	cout << "*****  6.按照编号排序 ********" << endl;
	cout << "*****  7.清空所有文档 ********" << endl;
	cout << "******************************" << endl;
};

void WorkerManager::exitSystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}

void WorkerManager::Add_Emp()
{
	cout << "请输入增加员工数量:" << endl;
	int addNum = 0;
	cin >> addNum;

	if (addNum > 0)
	{
		// 计算新空间大小
		int newSize = this->m_EmpNum + addNum;

		// 开辟新空间
		Worker** newSpace = new Worker * [newSize];

		// 如果原来的数组不为空，将原空间下的内容存放到新空间下
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}
		
		// 输入新数据
		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int dSelect;

			cout << "请输入数据第" << i + 1 << "个职工编号:" << endl;
			cin >> id;
			cout << "请输入数据第" << i + 1 << "个职工姓名:" << endl;
			cin >> name;
			cout << "请选择该职工岗位:" << endl;
			cout << "1.普通职工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
			cin >> dSelect;
		

		// 根据不同的职工类型，创建不同的worker子类

		Worker* worker = NULL; // 创建一个Worker指针(worker)来存放地址
		switch (dSelect)
		{
		case 1: // 普通员工
			worker = new Employee(id, name, 1);
			break;
		
		case 2: // 经理
			worker = new Manager(id, name, 2);
			break;
		
		case 3: // 老板
			worker = new Boss(id, name, 3);
			break;
		}

		// 将创建的职工保存到数组中
		newSpace[this->m_EmpNum + i] = worker;

		// 释放原有空间
		delete[] this->m_EmpArray;

		// 更改原有空间指向
		this->m_EmpArray = newSpace;

		// 更新个数
		this->m_EmpNum = newSize;

		// 提示信息
		cout << "完成添加" << addNum << "个员工！" << endl;

		};

	}
	else
	{
		cout << "输入有误" << endl;
	}

	// 按任意键后清屏，回到上级目录
	system("pause");
	system("cls");
}

WorkerManager::~WorkerManager(){};