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
#include "LinearList.h"
using namespace std;

int main()
{
	LinearList L;
	for(int i=0; i<10; i++) L.ListInsert_Sq(i, i);
	int len = L.GetLength();
	bool empty = L.IsEmpty();
	cout << "len=" << len << " is empty = " << empty << endl;
	for (int i=0; i<L.length; i++) cout << L.elem[i] << endl;
}
