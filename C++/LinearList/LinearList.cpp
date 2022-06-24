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
#include "LinearList.h"

LinearList::LinearList()
{
	this->elem = new ElemType[MAXSIZE];
	if(!this->elem) exit(OVERFLOW);
	this->length = 0;
}

LinearList::~LinearList()
{
	if(this->elem) delete this->elem;
}

void LinearList::ClearList()
{
	this->length = 0;
}

int LinearList::GetLength()
{
	return this->length;
}

bool LinearList::IsEmpty()
{
	if(this->length == 0) return true;
	else return false;
}

bool LinearList::GetElem(int i, ElemType &e)
{
	if (i < 0 || i > this->length) return false;
	e = this->elem[i];
	return true;
}

int LinearList::LocateElem(ElemType e)
{
	for(int i = 0; i < this->length; i++)
	{
		if (this->elem[i] == e)
		{
			return i;
		}
	}
	return 0;
}

bool LinearList::ListInsert_Sq(int i, ElemType e)
{

}
