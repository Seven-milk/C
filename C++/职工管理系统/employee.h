#pragma once
#include<iostream>
#include"worker.h"

using namespace std;

class Employee : public Worker
{
public:

	Employee(int id, string name, int dId); // 重写构造函数

	virtual void showInfo(); // 重写岗位职责信息描述
	virtual string getDeptName(); // 重写获取岗位名称
};