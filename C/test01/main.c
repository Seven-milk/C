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
	double max(double x, double y);
	double x, y, z;

	printf("input x and y to compare\n");
	scanf("%lf%lf", &x, &y);
	z=max(x, y);
	printf("the big one=%lf\n", z);
}

double max(double x, double y)
{
	double z;
	z = x > y ? x : y;
	return(z);
}
