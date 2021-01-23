#pragma once;
#include<iostream>;
using namespace std;
#include "identity.h";

class Student: public Identity
{
public:

	// 默认构造
	Student();

	// 有参构造
	Student(int id, string name, string pwd);

	// 菜单界面
	virtual void operMenu();

	// 申请预约
	void applyOrder();

	// 查看自己预约
	void showMyOrder();

	// 查看所有预约
	void showAllOrder();

	// 取消预约
	void cancelOrder();

	// 属性
	int m_Id; // 学号

};