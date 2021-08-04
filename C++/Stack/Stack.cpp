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
}
