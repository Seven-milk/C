#include "teacher.h";

// 默认构造
Teacher::Teacher() 
{

};

// 有参构造
Teacher::Teacher(int empId, string name, string pwd)
{
	// 初始化属性
	this->m_empId = empId;
	this->m_Name = name;
	this->m_Pwd = pwd;
};

// 菜单界面重写
void Teacher::operMenu() 
{
	cout << "==========  欢迎老师 " << this->m_Name << "登陆！ ==========" << endl;
	cout << "\t\t ------------------------------- \n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|        1.查看所有预约         |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|        2.审核预约             |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|        0.注销登录             |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t ------------------------------- \n";
	cout << "请选择您的操作：" << endl;
};

// 查看所有预约
void Teacher::showAllOrder()
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

// 审核预约
void Teacher::validOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	};
	cout << "待审核的预约如下：" << endl;

	vector<int> v;// 用于临时存放可以审核的预约序号
	int index = 0;

	for (int i = 0; i < of.m_Size; i++)
	{
		// 只显示待审核的预约
		if (of.m_orderData[i]["status"] == "1")
		{
			v.push_back(i);
			cout << ++index << "、";
			cout << "预约日期：周" << of.m_orderData[i]["date"];
			cout << " 时段：" << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午");  // 三元运算符做转换解析
			cout << " 机房：" << of.m_orderData[i]["roomId"];
			string status = " 状态："; // 0 取消的预约； 1 审核中； 2 已预约； -1 预约失败
			if (of.m_orderData[i]["status"] == "1")
			{
				status += "审核中";
			}
			cout << status << endl;
		}	
	}
	cout << "请输入要审核的预约记录，0表示返回" << endl;
	int select = 0; // 要审核的记录Index:v[select-1]
	int ret = 0; // 审核是否通过
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
				cout << "请输入审核结果：" << endl;
				cout << "1.通过" << endl;
				cout << "2.不通过" << endl;
				cin >> ret;
				if (ret == 1)
				{
					of.m_orderData[v[select - 1]]["status"] = "2";
				}
				else
				{
					of.m_orderData[v[select - 1]]["status"] = "-1";
				}
				of.updateOrder();
				cout << "审核完毕！" << endl;
				break;
			}
		}
		cout << "输入有误，请重新输入" << endl;
	}
	system("pause");
	system("cls");
};