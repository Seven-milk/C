/*
 * =====================================================================================
 *
 *       Filename:  LinearList.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2021年06月30日 16时55分51秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  XudongZheng (), z786909151@163.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
#define TURE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define MAXSIZE 100

typedef int Status;
typedef int ElemType;

class LinearList
{
public:
	// function
	LinearList();

	~LinearList();

	void ClearList();

	int GetLength();

	bool IsEmpty();

	bool GetElem(int i, ElemType &e);
	
	int LocateElem(ElemType e);
	
	bool ListInsert_Sq(int i, ElemType e);

	// element 
	ElemType *elem;

private:
	int length;
};
