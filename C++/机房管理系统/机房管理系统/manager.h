#pragma once
#include "identity.h"
#include "globalFile.h"
#include <fstream>
#include <iostream>
#include <vector>
#include "student.h"
#include "teacher.h"
#include <algorithm>
#include "computerRoom.h"
using namespace std;

class Manager: public Identity
{
public:
	// Ĭ���޲ι���
	Manager();

	// �вι���
	Manager(string name, string pwd);

	// �˵�������д
	virtual void operMenu();

	// ����˺�
	void addPerson();

	// �鿴�˺�
	void showPerson();

	// �鿴������Ϣ
	void showComputer();

	// ���ԤԼ��¼
	void cleanFile();

	// ��ʼ������
	void initVector();

	// ����ظ�
	bool checkRepeat(int id, int type);

	// ѧ������
	vector<Student> vStu;

	// ��ʦ����
	vector<Teacher> vTea;

	// ��������
	vector<ComputerRoom> vCom;

};