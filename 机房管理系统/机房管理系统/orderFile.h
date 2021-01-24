#pragma once
#include <iostream>
using namespace std;
#include <map>
#include "globalFile.h"
#include <fstream>

class OrderFile
{
public:
	// 构造函数
	OrderFile();

	// 更新预约记录
	void updateOrder();

	// order容器-map容器，key为记录条数，value为记录的键值对信息
	map<int, map<string, string>> m_orderData;

	// 预约的条数
	int m_Size;
};