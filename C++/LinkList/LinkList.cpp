/*
 * =====================================================================================
 *
 *       Filename:  LinearList.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2021年06月30日 16时55分05秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  XudongZheng (), z786909151@163.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include "LinkList.h"

bool ElemType::operator!=(ElemType &p)
{
	return this->num != p.num || this->name != p.name || this->score != p.score;
}

void ElemType::print()
{
	cout << "num=" << this->num << endl;
	cout << "name=" << this->name << endl;
	cout << "score=" << this->score << endl;
}

LinkList::LinkList()
{
	this->head = new Lnode;
	this->head->next = NULL;
}

LinkList::~LinkList()
{
	
	delete this->head;
}

void LinkList::CreateList_H(int n)
{
	for (int i=0; i<n; i++)
	{
		Lnode *p = new Lnode;
		cout << "请输入num" << endl;
		cin >> p->data.num;
		cout << "请输入name" << endl;
		cin >> p->data.name;
		cout << "请输入score" << endl;
		cin >> p->data.score;

		p->next = this->head->next;
		this->head->next = p;
	}
}

void LinkList::CreateList_R(int n)
{
	Lnode *r = this->head;
	for (int i=0; i<n; i++)
	{
		Lnode *p = new Lnode;
		
		cout << "请输入num" << endl;
		cin >> p->data.num;
		cout << "请输入name" << endl;
		cin >> p->data.name;
		cout << "请输入score" << endl;
		cin >> p->data.score;
		
		p->next = NULL;
		r->next = p;
		r = p;
	}
}

bool LinkList::IsEmpty()
{
	if(this->head == NULL) return true;
	else return false;
}

bool LinkList::DestoryList()
{
	Lnode *p;
	while(this->head!=NULL)
	{
		p = this->head;
		this->head = this->head->next;
		delete p;
	}
	return true;
}

bool LinkList::ClearList()
{
	Lnode *p, *q;
	if (this->head == NULL) return true;
	p = this->head->next;
	while (p != NULL)
	{
		q = p->next;
		delete p;
		q = p;
	}
	this->head = NULL;
	return true;
}

int LinkList::GetLength()
{
	Lnode *p;
	if (this->head == NULL) return 0;
	p = this->head->next;
	int n = 0;
	while(p!=NULL)
	{
		n++;
		p = p->next;
	}
	return n;
}

bool LinkList::GetElem(int i, ElemType &e)
{
	Lnode *p;
	p = this->head->next;
	int j = 0;
	while(p !=NULL && j < i)
	{
		p = p->next;
		j++;
	}
	if (p==NULL || j>i) return false;
	e = p->data;
	return true;
}

Lnode *LinkList::LocateElem(ElemType e)
{
	Lnode *p = this->head->next;
	while(p != NULL && p->data != e)
	{
		p = p->next;
	}
	return p;
}

bool LinkList::ListInsert(int i, ElemType e)
{
	Lnode *p = this->head;
	int j=0;
	while(p != NULL && j < i)
	{
		p = p->next;
		j++;
	}
	if (p == NULL || j > i) return false;
	Lnode *s = new Lnode;
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true;
}

bool LinkList::ListDelete(int i, ElemType e)
{
	Lnode *p = this->head;
	Lnode *q;
	int j=0;
	while(p->next != NULL && j<i) {p = p->next; j++;}
	if(p->next == NULL || j>i) return false;
	q = p->next;
	p->next = q->next;
	e = q->data;
	delete q;
	return true;
}
