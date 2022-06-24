/*
 * =====================================================================================
 *
 *       Filename:  Stack.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2021年08月04日 00时10分53秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  XudongZheng (), z786909151@163.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include "Stack.h"

Stack::Stack(){
	this->top = NULL;	
}

Stack::~Stack(){
	delete this->top;
	this->top = NULL;
}

bool Stack::StackEmpty(){
	if (this->top == NULL) return true;
	else return false;
}

bool Stack::ClearStack(){
	this->top = NULL;
	return true;
}

bool Stack::Push(ElemType e){
	StackNode *p = new StackNode;
	p->data = e;
	p->next = this->top;
	this->top = p;
	return true;
}

bool Stack::Pop(ElemType *e){
	if(this->top == NULL) return false;
	else
		*e = this->top->data;
		StackNode *p;
		p = this->top;
		this->top = this->top->next;
		delete p;
		return true;
}

bool Stack::GetTop(ElemType *e){
	if(this->top != NULL){
		*e = this->top->data;
		return true;
	}
	else return false;
}
