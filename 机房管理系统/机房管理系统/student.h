#pragma once
#include<iostream>
using namespace std;
#include "identity.h"
#include "computerRoom.h"
#include <vector>
#include <fstream>
#include "globalFile.h"
#include "orderFile.h"

class Student: public Identity
{
public:

	// Ĭ�Ϲ���
	Student();

	// �вι���
	Student(int id, string name, string pwd);

	// �˵�����
	virtual void operMenu();

	// ����ԤԼ
	void applyOrder();

	// �鿴�Լ�ԤԼ
	void showMyOrder();

	// �鿴����ԤԼ
	void showAllOrder();

	// ȡ��ԤԼ
	void cancelOrder();

	// ����
	int m_Id; // ѧ��
	
	// ��������
	vector<ComputerRoom> vCom;
};