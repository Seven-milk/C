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
	bool empty;
	empty = S.StackEmpty();
	int len;
	len = S.StackLength();
	cout << "Len: " << len << endl;
	cout << "Is empty: " << empty << endl;

	ElemType a = 5;	
	bool push;
	push = S.Push(a);
	cout << "push:" << push << endl;
	cout << "base:"<< *S.base << " "<< "top:" << *S.top << endl;
	empty = S.StackEmpty();
	len = S.StackLength();
	cout << "Len: " << len << endl;
	cout << "Is empty: " << empty << endl;

	bool pop;
	pop = S.Pop(&e);
	cout << "pop: " << pop << endl;
	cout << "e: " << e << endl;

	bool destory;
	destory = S.DestoryStack();
	cout << "Is destory: " << destory << endl;
	bool clear;
	clear = S.ClearStack();
	cout << "Is clear: " << clear << endl;
}
