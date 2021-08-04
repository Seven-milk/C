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
#include "Stack.h"
using namespace std;

int main()
{
	Stack S;
	ElemType e;
	cout << S.stacksize << endl;
	cout << *S.base << *S.top << endl;
	//cout << "insert: " << insert  << endl;
	//bool empty = L.IsEmpty();
	//cout << "Is empty: " << empty << endl;
	//int n=1;
	//L.GetElem(n, e);
	//cout << "elem in " << n << endl; 
	//e.print();
	//bool destory = L.DestoryList();
	//cout << "Is destory: " << destory << endl;
	//bool clear = L.ClearList();
	//cout << "Is clear: " << clear << endl;
	//int len = L.GetLength();
	//cout << "Len: " << len << endl;
}
