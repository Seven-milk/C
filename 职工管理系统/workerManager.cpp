#include "workerManager.h" // 包含头文件


WorkerManager::WorkerManager()
{
	// 初始化人数:去下方初始化
	//this->m_EmpNum = 0;
	//this->m_EmpArray = NULL;

	// 判断文件是否存在，进行初始化
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	// 文件不存在
	if (!ifs.is_open())
	{
		//cout << "文件不存在" << endl; // 测试输出
		this->m_EmpNum = 0; // 初始化人数为0
		this->m_EmpArray = NULL; // 初始化数组为空
		this->m_FileIsEmpty = true; // 文件不存在，初始化为true
		ifs.close();
		return;
	}

	// 文件存在，并且没有记录
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//cout << "文件为空" << endl; // 测试输出
		this->m_EmpNum = 0; // 初始化人数为0
		this->m_EmpArray = NULL; // 初始化数组为空
		this->m_FileIsEmpty = true; // 文件存在但没有记录，初始化为true
		ifs.close();
		return;
	}

	// 文件存在，有记录，获取人数
	int num = this->get_EmpNum();
	// cout << "人数为:" << num << endl; // 测试代码
	this->m_EmpNum = num; // 更新成员属性

	// 文件存在，有记录，初始化数组
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	init_Emp(); // 调用函数，根据文件初始化数组

	// 测试
	/*for (int i = 0; i < m_EmpNum; i++)
	{
		cout << "职工号:" << this->m_EmpArray[i]->m_Id;
		cout << "名称:" << this->m_EmpArray[i]->m_Name;
		cout << "部门编号:" << this->m_EmpArray[i]->m_DeptId << endl;
	}*/
};

void WorkerManager::Show_Menu()
{
	cout << "******************************" << endl;
	cout << "***  欢迎使用职工管理系统  ***" << endl;
	cout << "*****  0.退出管理程序 ********" << endl;
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
		}
		// 释放原有空间
		delete[] this->m_EmpArray;

		// 更改原有空间指向
		this->m_EmpArray = newSpace;

		// 更新个数
		this->m_EmpNum = newSize;

		// 提示信息
		cout << "完成添加" << addNum << "个员工！" << endl;
		// 保存数据
		this->save();
	}
	else
	{
		cout << "输入有误" << endl;
	}

	// 按任意键后清屏，回到上级目录
	system("pause");
	system("cls");
}

void WorkerManager::save()
{
	ofstream ofs; // 创建流对象
	ofs.open(FILENAME, ios::out); // 输出
	
	// 循环储存worker*的数组，对于每一个worker对象的指针（就是数组元素）取其三个属性，写入ofs对象
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
		// 记录人数
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

	// 循环读取文件中数据，并初始化到员工数组中
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		Worker* worker = NULL;

		// 根据不同类型创建不同员工对象
		switch (dId) {
		case 1: // 普通员工
			worker = new Employee(id, name, dId);
			break;
		case 2: // 经理
			worker = new Manager(id, name, dId);
			break;
		case 3: // 老板
			worker = new Boss(id, name, dId);
			break;
		}
		// 存放到数组
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
	//// 文件不存在或为空
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
		// 如果为空
		cout << "文件不存在或为空，请添加" << endl;
		// 任意键清屏
		system("pause");
		system("cls");
	}
	else 
	{
		// 不为空，显示信息
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			// 利用多态调用接口
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
		cout << "文件为空！" << endl;
		// 任意键清屏
		system("pause");
		system("cls");
	}
	else
	{
		int id;
		cout << "请输入要删除的员工id:";
		cin >> id;
		int index = this->IsExist(id);
		if (index != -1) // 找到数据，删除index处的数组数据
		{
			// 数据前移
			for (int i = index; i < this->m_EmpNum - 1; i++) // m_EmpNum - 1为数组中最后一个位置
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--; // 人数减一
			this->save(); // 保存到文件
			cout << "删除成功！" << endl;
		}
		else
		{
			cout << "输入的员工编号不存在！" << endl;
		}
	}

	// 按任意键清屏
	system("pause");
	system("cls");

}

void WorkerManager::Mod_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
		// 任意键清屏
		system("pause");
		system("cls");
	}
	else
	{
		cout << "请输入职工编号" << endl;
		int id;
		cin >> id;

		int ret = this->IsExist(id);
		if (ret != -1)
		{
			// 找到原来的员工，删除
			delete this->m_EmpArray[ret];
			// 新建员工信息

			cout << "查到:" << id << "号员工，请输出新职工号:" << endl;
			int newId;
			cin >> newId;

			cout << "请输入新姓名:" << endl;
			string newName;
			cin >> newName;

			cout << "请输入岗位:" << endl;
			cout << "1.普通职工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;

			int dSelect;
			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect)
			{
				case 1:
					worker = new Employee(newId, newName, dSelect);
					break;
				case 2:
					worker = new Manager(newId, newName, dSelect);
					break;
				case 3:
					worker = new Boss(newId, newName, dSelect);
					break;
			}

			this->m_EmpArray[ret] = worker;
			cout << "修改成功" << this->m_EmpArray[ret]->m_DeptId << endl;
			this->save();

		}
		else 
		{
			cout << "查无此人！" << endl;
		}
	}
	// 任意键清屏
	system("pause");
	system("cls");
}

void WorkerManager::Find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
		// 任意键清屏
		system("pause");
		system("cls");
	}
	else
	{
		cout << "请输入查找方式:" << endl;
		cout << "1.按照职工编号查找" << endl;
		cout << "2.按照职工姓名查找" << endl;

		int select = 0;
		cin >> select;

		if (select == 1)
		{
			int id;
			cout << "请输入要查找的职工编号:" << endl;
			cin >> id;
			
			int ret = IsExist(id);
			if (ret != -1)
			{
				cout << "查找成功，该职工信息如下:" << endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else
			{
				cout << "查无此人!" << endl;
			}
		}
		else if (select == 2)
		{
			string name;
			cout << "请输入要照抄的职工姓名:" << endl;
			cin >> name;

			bool flag = false; // 查找标志
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i]->m_Name == name)
				{
					cout << "查找成功，信息如下:" << endl;
					flag = true;
					this->m_EmpArray[i]->showInfo();
				}
			}
			if (flag == false)
			{
				cout << "查无此人！" << endl;
			}
		}
		else
		{
			cout << "输入错误" << endl;
		}
	}

	// 任意键清屏
	system("pause");
	system("cls");
}

void WorkerManager::Sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
		// 任意键清屏
		system("pause");
		system("cls");
	}
	else
	{
		cout << "请选择排序方式:" << endl;
		cout << "1.按职工号进行升序" << endl;
		cout << "2.按职工号进行降序" << endl;

		int select = 0;
		cin >> select;

		for (int i = 0; i < this->m_EmpNum; i++)
		{
			int minOrMax = i;
			for (int j = i + 1; j < this->m_EmpNum; j++)
			{
				if (select == 1) // 升序
				{
					if (this->m_EmpArray[minOrMax]->m_Id > this->m_EmpArray[j]->m_Id)
					{
						minOrMax = j;
					}
				}

				else if (select == 2) // 降序
				{
					if (this->m_EmpArray[minOrMax]->m_Id < this->m_EmpArray[j]->m_Id)
					{
						minOrMax = j;
					}
				}
				else
				{
					cout << "输入错误！" << endl;
					// 任意键清屏
					system("pause");
					system("cls");
				}
			}
			if (i != minOrMax)
			{
				Worker* temp = this->m_EmpArray[i];
				this->m_EmpArray[i] = this->m_EmpArray[minOrMax];
				this->m_EmpArray[minOrMax] = temp;
			}
		}
		cout << "排序成功，排序后结果为:" << endl;
		this->save();
		this->Show_Emp();
	}
	// 任意键清屏
	system("pause");
	system("cls");
}

void WorkerManager::Clean_File()
{
	cout << "确认清空?" << endl;
	cout << "1.确认" << endl;
	cout << "2.返回" << endl;

	int select;
	cin >> select;
	if (select == 1)
	{
		// 打开模式 ios::trunc 如果存在就删除文件并重建
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();

		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i] != NULL)
				{
					delete this->m_EmpArray[i];
				}
			}
			this->m_EmpNum = 0;
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_FileIsEmpty = true;
		}
		cout << "清空成功！" << endl;
	}
	// 任意键清屏
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