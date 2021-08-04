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
	bool empty;
	empty = S.StackEmpty();
	cout << "Is empty: " << empty << endl;

	ElemType a = 5;	
	bool push;
	push = S.Push(a);
	cout << "push:" << push << endl;
	cout << "top:"<< S.top->data << endl;
	empty = S.StackEmpty();
	cout << "Is empty: " << empty << endl;
	bool gettop;
	gettop = S.GetTop(&e);
	cout << "GetTop: " << gettop << endl;
	cout << "top: " << e << endl;

	bool pop;
	pop = S.Pop(&e);
	cout << "pop: " << pop << endl;
	cout << "e: " << e << endl;

	bool clear;
	clear = S.ClearStack();
	cout << "Is clear: " << clear << endl;
}
