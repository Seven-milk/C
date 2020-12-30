#include <iostream>
#include<string>
#include"workerManager.h"
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"

using namespace std;

void test01()
{
	Worker* worker = NULL;
	worker = new Employee(1, "张三", 1);
	worker->showInfo();
	delete worker;

	worker = new Manager(2, "李四", 2);
	worker->showInfo();
	delete worker;

	worker = new Boss(3, "王五", 3);
	worker->showInfo();
	delete worker;
}

int main()
{
	WorkerManager wm;
	int choice;

	test01();
	while (true)
	{
		// 展示菜单
		wm.Show_Menu();
		cout << "请输入您的选择：" << endl;
		cin >> choice;

		// 分支
		switch (choice)
		{
		case 0: // 退出系统
			wm.exitSystem();
			break;
		case 1: // 添加职工
			break;
		case 2: // 显示职工
			break;
		case 3: // 删除职工
			break;
		case 4: // 修改职工
			break;
		case 5: // 查找职工
			break;
		case 6: // 按编号排序
			break;
		case 7: // 清空文档
			break;
		}
	}

	
	system("pause");//按任意键继续

	return 0;//退出

}