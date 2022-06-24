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
	this->base = new ElemType[MAXSIZE];
	if (!this->base) exit(OVERFLOW);
	this->top = this->base;
	this->stacksize = MAXSIZE;
}

Stack::~Stack(){
	delete this->base;
	this->stacksize = 0;
	this->top = NULL;
	this->base = NULL;
}

bool Stack::StackEmpty(){
	if (this->top == this->base) return true;
	else return false;
}

int Stack::StackLength(){
	return this->top - this->base;
}

bool Stack::ClearStack(){
	if(this->base){
		this->top = this->base;
		return true;
	}
	else return false;
}

bool Stack::DestoryStack(){
	if(this->base){
		delete this->base;
		this->stacksize = 0;
		this->base = NULL;
		this->top = NULL;
		return true;
	}
	else return false;
}

bool Stack::Push(ElemType e){
	if(this->top - this->base == this->stacksize) return false;
	else
		*this->top = e;
		this->top++;
		return true;
}

bool Stack::Pop(ElemType *e){
	if(this->top == this->base) return false;
	else
		*e = *--this->top;
		return true;
}



