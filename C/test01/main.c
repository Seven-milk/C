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
	int f(int x);
	int x, y;

	printf("input x\n");
	scanf("%d", &x);
	y=f(x);
	printf("%d\n", y);
}

int f(int x)
{
	int z;
	if (x > 1)
	{
		z = x * f(x-1);	
	}
	else if(x == 1 || x == 0)
	{
		z = 1;
	}
	return z;
}
