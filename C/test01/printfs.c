/*
 * =====================================================================================
 *
 *       Filename:  printfs.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2021年06月18日 16时51分57秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>
void printfs(char *p)
{
	for(;*p != '\0'; p++)
	{
		printf("%c", *p);
	}
	printf("\n");
}
