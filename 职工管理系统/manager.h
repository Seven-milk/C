#pragma once
#include<iostream>
#include"worker.h"
using namespace std;

class Manager : public Worker
{
public:

	Manager(int id, string name, int dId); // ��д���캯��

	virtual void showInfo(); // ��д��λְ����Ϣ����
	virtual string getDeptName(); // ��д��ȡ��λ����
};
