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
	for(int i=0; i<=5; i++)
	{
		for(int j=0; j<i; j++)
		{
			printf("*");
		}
		printf("\n");
	}
}
