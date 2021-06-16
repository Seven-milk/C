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
	int a[3];
	for(int i=0; i<3; i++)
	{
		scanf("%d", &a[i]);
	}
	for(int i=0; i<3; i++)
	{
		printf("%d\n", a[i]);
	}
}
