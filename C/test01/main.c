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
	int a=5, b=2, c=3;
	int *p1, *p2, *p3;
	p1 = &a;
	p2 = &b;
	p3 = &c;
	printf("%d, %d, %d\n", &a, &b, &c);
	printf("%d, %d, %d\n", p1, p2, p3);
	printf("%d, %d, %d\n", *p1, *p2, *p3);
}
