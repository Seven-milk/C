#pragma once
#include<iostream>;
using namespace std;
#include "identity.h";

class Teacher :public Identity
{
public:
	// Ĭ�Ϲ���
	Teacher();

	// �вι���
	Teacher(int empId, string name, string pwd);

	// �˵�������д
	virtual void operMenu();

	// �鿴����ԤԼ
	void showAllOrder();

	// ���ԤԼ
	void validOrder();

	// ��Ա����
	int m_empId; // ְ����
};