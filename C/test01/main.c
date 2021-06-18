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
	char s1[10], s2[10], *p1, *p2;

	p1 = s1;
	p2 = s2;
	printf("input string1\n");
	scanf("%s", p1);
	printf("input string2\n");
	scanf("%s", p2);

	printf("s1:");
	printfs(s1);
	printf("s2:");
	printfs(s2);

	swap(p1, p2);
	
	printf("s1:");
	printfs(s1);
	printf("s2:");
	printfs(s2);

}


