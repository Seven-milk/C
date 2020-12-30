#pragma once // 防止头文件重复包含
#include<iostream>
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"

using namespace std;

class WorkerManager
{
public:
	// 构造函数
	WorkerManager();

	// 展示菜单
	void Show_Menu();

	// 退出接口
	void exitSystem();

	// 增加职工函数
	void Add_Emp();

	// 析构函数
	~WorkerManager();

	// 记录文件中的人员个数
	int m_EmpNum;

	// 员工数组的指针
	Worker** m_EmpArray;

};