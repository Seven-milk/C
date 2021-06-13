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
	int i=5, j=5, p, q;
	p = (i++);
	q = (++j);
	printf("p=%d, q=%d, i=%d, j=%d\n", p, q, i, j);
	
	i = 5;
	j = 5;
	p = (i++)+(i++);
	q = (++j)+(++j);
	printf("p=%d, q=%d, i=%d, j=%d\n", p, q, i, j);

	
	i = 5;
	j = 5;
	p = (i++)+(i++)+(i++);
	q = (++j)+(++j)+(++j);
	printf("p=%d, q=%d, i=%d, j=%d\n", p, q, i, j);
}
