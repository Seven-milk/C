/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2021年06月29日 15时26分34秒
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

void main()
{
	int x[3];
	for(int i=0; i<3; i++)
	{
		scanf("%d", &x[i]);
		getchar();
	}
	printf("---------------\n");
	for(int i=0; i<3; i++)
	{
		printf("%d\n", x[i]);
	}
}

