#pragma once
#include <iostream>
using namespace std;
#include <map>
#include "globalFile.h"
#include <fstream>

class OrderFile
{
public:
	// ���캯��
	OrderFile();

	// ����ԤԼ��¼
	void updateOrder();

	// order����-map������keyΪ��¼������valueΪ��¼�ļ�ֵ����Ϣ
	map<int, map<string, string>> m_orderData;

	// ԤԼ������
	int m_Size;
};