/*
 * =====================================================================================
 *
 *       Filename:  Stack.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2021年08月04日 00时10分42秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  XudongZheng (), z786909151@163.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define MAXSIZE 100
using namespace std;
typedef int ElemType;

class Stack{
public:
	// method
	Stack();

	~Stack();

	// variable
	int stacksize;
	
	ElemType *base;
	
	ElemType *top;


};
