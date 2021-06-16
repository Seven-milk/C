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
	int a[3][4]={1,2,3,4,5,6,7,8,9,10,11,12}, b[4][3];
	for(int i=0; i<3; i++)
	{
		for(int j=0; j<4; j++)
		{
			b[j][i]=a[i][j];
		}
	}
	for (int i=0; i<3; i++)
	{
		printf("%d %d %d %d\n", a[i][0], a[i][1], a[i][2], a[i][3]);
	}
	for(int i=0; i<4; i++)
	{
		printf("%d %d %d\n", b[i][0], b[i][1], b[i][2]);
	}
}
