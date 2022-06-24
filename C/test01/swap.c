/*
 * =====================================================================================
 *
 *       Filename:  swap.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2021年06月18日 16时43分44秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>
void swap(char *p1, char *p2)
{
	char temp;
	for(; *p1 != '\0' || *p2 != '\0';)
	{
		temp = *p1;
		*p1 = *p2;
		*p2 = temp;
		if(*p1 != '\0') p1++;
		if(*p2 != '\0') p2++;
	}
}
