#pragma once // ��ֹͷ�ļ��ظ�����
#include<iostream>
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"

using namespace std;

class WorkerManager
{
public:
	// ���캯��
	WorkerManager();

	// չʾ�˵�
	void Show_Menu();

	// �˳��ӿ�
	void exitSystem();

	// ����ְ������
	void Add_Emp();

	// ��������
	~WorkerManager();

	// ��¼�ļ��е���Ա����
	int m_EmpNum;

	// Ա�������ָ��
	Worker** m_EmpArray;

};