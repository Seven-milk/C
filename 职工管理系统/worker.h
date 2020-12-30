#pragma once
#include<iostream>
using namespace std;

class Worker
{
public:
	virtual void showInfo() = 0; // 岗位职责信息描述
	virtual string getDeptName() = 0; // 获取岗位名称
	int m_Id; // 职工编号
	string m_Name; // 职工姓名
	int m_DeptId; // 部门编号
};
