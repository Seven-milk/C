#include "student.h"

// 默认构造
Student::Student() 
{

};

// 有参构造
Student::Student(int id, string name, string pwd)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_Pwd = pwd;

	// 读取机房信息
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);

	ComputerRoom c;
	while (ifs >> c.m_ComId && ifs >> c.m_MaxNum)
	{
		this->vCom.push_back(c);
	}
	ifs.close();
};

// 菜单界面
void Student::operMenu()
{
	cout << "==========  欢迎学生代表 " << this->m_Name << "登陆！ ==========" << endl;
	cout << "\t\t ------------------------------- \n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|        1.申请预约             |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|        2.查看我的预约         |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|        3.查看所有预约         |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|        4.取消预约             |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|        0.注销登录             |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t ------------------------------- \n";
	cout << "请选择您的操作：" << endl;
};

// 申请预约
void Student::applyOrder()
{
	// 输入时间date，判断时间输入正确与否
	cout << "机房开放时间为周一至周五" << endl;
	cout << "请输入申请预约的时间：" << endl;
	cout << "1.周一" << endl;
	cout << "2.周二" << endl;
	cout << "3.周三" << endl;
	cout << "4.周四" << endl;
	cout << "5.周五" << endl;
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
		cout << "输入错误，请重新输入" << endl;
	}

	// 输入时间段interval，判断时间段输入正确与否
	cout << "请输入预约的时间段" << endl;
	cout << "1.上午" << endl;
	cout << "2.下午" << endl;
	
	while (true)
	{
		cin >> interval;
		if (interval >= 1 && interval <= 2)
		{
			break;
		}
		cout << "输入错误，请重新输入" << endl;
	}

	// 输入机房room，判断输入正确与否
	cout << "请选择机房" << endl;
	cout << "1号机房容量" << this->vCom[0].m_MaxNum << endl;
	cout << "2号机房容量" << this->vCom[1].m_MaxNum << endl;
	cout << "3号机房容量" << this->vCom[2].m_MaxNum << endl;

	while (true)
	{
		cin >> room;
		if (room >= 1 && room <= 3)
		{
			break;
		}
		cout << "输入错误，请重新输入" << endl;
	}

	cout << "预约成功，审核中！" << endl;

	// 将预约信息存入文件ORDER_FILE，append方式存入
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

// 查看自己预约
void Student::showMyOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < of.m_Size; i++)
	{
		// 只显示该生的信息，判断是否为该生
		if (atoi(of.m_orderData[i]["stuId"].c_str()) == this->m_Id) // 将stuId转为整型与m_Id进行判断
		{
			cout << "预约日期： 周" << of.m_orderData[i]["date"];
			cout << "时段：" << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午");  // 三元运算符做转换解析
			cout << "机房：" << of.m_orderData[i]["roomId"];
			string status = "状态："; // 0 取消的预约； 1 审核中； 2 已预约； -1 预约失败
			if (of.m_orderData[i]["status"] == "1")
			{
				status += "审核中";
			}
			else if (of.m_orderData[i]["status"] == "2")
			{
				status += "已预约";
			}
			else if (of.m_orderData[i]["status"] == "-1")
			{
				status += "预约失败";
			}
			else
			{
				status += "预约已取消";
			}
			cout << status << endl;
		}
	}
	system("pause");
	system("cls");
};

// 查看所有预约
void Student::showAllOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < of.m_Size; i++)
	{
		cout << i + 1 << "、";
		cout << "预约日期：周" << of.m_orderData[i]["date"];
		cout << " 时段：" << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午");  // 三元运算符做转换解析
		cout << " 学号：" << of.m_orderData[i]["stuId"];
		cout << " 姓名：" << of.m_orderData[i]["stuName"];
		cout << " 机房：" << of.m_orderData[i]["roomId"];
		string status = " 状态："; // 0 取消的预约； 1 审核中； 2 已预约； -1 预约失败
		if (of.m_orderData[i]["status"] == "1")
		{
			status += "审核中";
		}
		else if (of.m_orderData[i]["status"] == "2")
		{
			status += "已预约";
		}
		else if (of.m_orderData[i]["status"] == "-1")
		{
			status += "预约失败";
		}
		else
		{
			status += "预约已取消";
		}
		cout << status << endl;

	}
	system("pause");
	system("cls");
};

// 取消预约
void Student::cancelOrder()
{
	OrderFile of;
	// 判断是否为空
	if (of.m_Size == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "审核中或预约成功的记录可以取消，请输入取消的记录" << endl;

	vector<int>v; // 暂存自己申请预约，在m_orderData中是第几条（可能有多条）
	int index = 1;
	for (int i = 0; i < of.m_Size; i++) 
	{
		// 遍历所有记录，找到自己的
		if (atoi(of.m_orderData[i]["stuId"].c_str()) == this->m_Id)
		{
			// 将自己记录在m_orderData中的索引放入v容器
			v.push_back(i);

			// 输出自己预约的信息
			cout << index++ << "、";
			cout << " 预约日期：周" << of.m_orderData[i]["date"];
			cout << " 时段：" << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午");
			cout << " 机房：" << of.m_orderData[i]["roomId"];
			string status = " 状态："; // 0 取消的预约；1 审核中；2 已预约；-1 预约失败
			if (of.m_orderData[i]["status"] == "1")
			{
				status += "审核中";
			}
			else if (of.m_orderData[i]["status"] == "2")
			{
				status += "已预约";
			}
			cout << status << endl;
		}
	}

	// 取消预约，显示的顺序：index->select，在原来中的index->v[select-1]
	cout << "请输入要取消的记录，0表示返回" << endl;
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
				// cout << of.m_orderData[v[select - 1]]["status"]; // 测试
				of.updateOrder();
				cout << "已取消预约" << endl;
				break;
			}
		}
		// 超出范围，重新输入
		cout << "输入有误，请重新输入" << endl;
	}
	system("pause");
	system("cls");
};