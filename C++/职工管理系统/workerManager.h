#pragma once // ��ֹͷ�ļ��ظ�����
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
	// ���캯��
	WorkerManager();

	// չʾ�˵�
	void Show_Menu();

	// �˳��ӿ�
	void exitSystem();

	// ����ְ������
	void Add_Emp();

	// ���溯��
	void save();

	// ͳ����������
	int get_EmpNum();

	// ��ʼ��Ա�����麯��
	void init_Emp();

	// ��ʾ��Ϣ
	void Show_Emp();

	// �ж�Ա���Ƿ����
	int IsExist(int id);

	// ɾ��ְ��
	void Del_Emp();

	// �޸�ְ��
	void Mod_Emp();

	// ����ְ��
	void Find_Emp();

	// ����ְ��
	void Sort_Emp();

	// ����ļ�
	void Clean_File();

	// ��������
	~WorkerManager();

	// ��¼�ļ��е���Ա����
	int m_EmpNum;

	// Ա�������ָ��
	Worker** m_EmpArray;

	// �ļ��Ƿ񴴽�
	bool m_FileIsEmpty;

};