#pragma once
#include<iostream>
using namespace std;

class Worker
{
public:
	virtual void showInfo() = 0; // ��λְ����Ϣ����
	virtual string getDeptName() = 0; // ��ȡ��λ����
	int m_Id; // ְ�����
	string m_Name; // ְ������
	int m_DeptId; // ���ű��
};
