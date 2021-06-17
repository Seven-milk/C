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

int b;

void main()

{
	scanf("%d", &b);
	void f(int x[5]);
	int a[5]={1,2,3,4,5};

	f(a);
}

void f(int * x)
{
	extern int b;
	for (int i=0; i<5; i++)
	{
		printf("%d\n", b * x[i]);
	}
}

