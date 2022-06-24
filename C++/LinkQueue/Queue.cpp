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
	this->front = this->rear = new QueueNode;
 	this->front->next = NULL;
}

Queue::~Queue(){
	while(this->front){
		this->rear = this->front->next;
		delete this->front;
		this->front = this->rear;
	}
}

bool Queue::EnQueue(ElemType e){
	QueueNode *p = new QueueNode;
	p->data = e;
	p->next = NULL;
	this->rear->next = p;
	this->rear = p;
	return true;
}

bool Queue::DeQueue(ElemType *e){
	if(this->front == this->rear) return false;
	QueueNode *p;
	p = this->front;
	*e = this->front->data;
	this->front->next = p->next;
 	if(this->rear == p) this->rear = this->front;
	delete p;
	return true;
}

bool Queue::GetHead(ElemType *e){
	if(this->front == this->rear) return false;
	*e = this->front->next->data;
	return true;
}
