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
#include <string>
#define TURE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define MAXSIZE 100
using namespace std;

typedef int Status;

class ElemType
{
public:
	string num;
	string name;
	int score;
	bool operator!=(ElemType &p);
	void print();
};

class Lnode
{
public:
	// elem
	ElemType data;
	Lnode *next;
};

class LinkList
{
public:
	// function
	LinkList();
	
	~LinkList();

	bool IsEmpty();

	bool DestoryList();

	bool ClearList();

	int GetLength();

	bool GetElem(int i, ElemType &e);

	Lnode *LocateElem(ElemType e);

	bool ListInsert(int i, ElemType e);

	bool ListDelete(int i, ElemType e);
	
	void CreateList_H(int n);

	void CreateList_R(int n);

	// elem
	Lnode *head;	
	
};
