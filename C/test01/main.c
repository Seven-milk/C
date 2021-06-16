/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description: test01 
 *
 *        Version:  1.0
 *        Created:  06/11/2021 01:50:41 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <math.h>

void main()

{
	void f(int x[5]);
	int a[5]={1,2,3,4,5};

	f(a);
}

void f(int * x)
{
	for (int i=0; i<5; i++)
	{
		printf("%d\n", x[i]);
	}
}
