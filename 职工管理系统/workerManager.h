#pragma once // 防止头文件重复包含
#include<fstream>
#include<iostream>
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
#define FILENAME "empfile.txt"

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

	// 保存函数
	void save();

	// 统计人数函数
	int get_EmpNum();

	// 初始化员工数组函数
	void init_Emp();

	// 显示信息
	void Show_Emp();

	// 判断员工是否存在
	int IsExist(int id);

	// 删除职工
	void Del_Emp();

	// 修改职工
	void Mod_Emp();

	// 查找职工
	void Find_Emp();

	// 排序职工
	void Sort_Emp();

	// 清空文件
	void Clean_File();

	// 析构函数
	~WorkerManager();

	// 记录文件中的人员个数
	int m_EmpNum;

	// 员工数组的指针
	Worker** m_EmpArray;

	// 文件是否创建
	bool m_FileIsEmpty;

};