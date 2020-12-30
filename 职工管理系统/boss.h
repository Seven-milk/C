#pragma once
#include<iostream>
#include"worker.h"
using namespace std;

class Boss : public Worker
{
public:
	Boss(int id, string name, int dId);
	virtual void showInfo(); // 岗位职责信息描述
	virtual string getDeptName(); // 获取岗位名称
};