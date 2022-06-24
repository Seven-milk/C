/*
 * =====================================================================================
 *
 *       Filename:  Queue.cpp
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
#include "Queue.h"

Queue::Queue(){
	this->base = new ElemType[MAXSIZE];	
	this->front = 0;
	this->rear = 0;
}

Queue::~Queue(){
	delete this->base;
	this->base = NULL;
}

int Queue::QueueLength(){
	return ((this->rear - this->front + MAXSIZE) % MAXSIZE);
}

bool Queue::EnQueue(ElemType e){
	if ((this->rear + 1) % MAXSIZE == this->front) return false;
	this->base[this->rear] = e;
	this->rear = (this->rear + 1) % MAXSIZE;
	return true;
}

bool Queue::DeQueue(ElemType *e){
	if(this->front == this->rear) return false;
	else
		*e = this->base[this->front];
		this->front = (this->front + 1) % MAXSIZE;
		return true;
}

bool Queue::GetHead(ElemType *e){
	if(this->front != this->rear){
		*e = this->base[this->front];
		return true;
	}
	else return false;
}
