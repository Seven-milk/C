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
#include "Queue.h"
using namespace std;

int main()
{
	Queue Q;
	ElemType e;
	bool empty;

	int len;
	len = Q.QueueLength();
	cout << "len: " << len << endl;

	ElemType a = 5;	
	bool En;
	En = Q.EnQueue(a);
	cout << "En:" << En << endl;
	cout << "head:"<< Q.base[Q.front] << endl;
	
	bool gethead;
	gethead = Q.GetHead(&e);
	cout << "GetHead: " << gethead << endl;
	cout << "Head: " << e << endl;

	bool De;
	De = Q.DeQueue(&e);
	cout << "DeQueue: " << De << endl;
	cout << "e: " << e << endl;

	len = Q.QueueLength();
	cout << "len: " << len << endl;
}
