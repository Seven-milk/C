/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2021年06月29日 17时04分57秒
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  XudongZheng (), z786909151@163.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
#include "LinkList.h"
using namespace std;

int main()
{
	LinkList L;
	ElemType e;
	L.CreateList_H(3);
	e.num = "123";
	e.name = "123";
	e.score = 12;
	cout << "e_init" << endl;
	e.print();
	bool insert = L.ListInsert(0, e);
	cout << "insert: " << insert  << endl;
	bool empty = L.IsEmpty();
	cout << "Is empty: " << empty << endl;
	int n=1;
	L.GetElem(n, e);
	cout << "elem in " << n << endl; 
	e.print();
	bool destory = L.DestoryList();
	cout << "Is destory: " << destory << endl;
	bool clear = L.ClearList();
	cout << "Is clear: " << clear << endl;
	int len = L.GetLength();
	cout << "Len: " << len << endl;
}
