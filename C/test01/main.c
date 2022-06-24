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

void swap(char *p1, char *p2);
void printfs(char *p1);

void main()

{
	int a[3]={0, 1, 2};
	int *p = a;

	for(int i=0; i < 3; i++)
	{
		printf("%d\n", p[i]);
		//p++;
	}
	

}

