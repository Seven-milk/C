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
	double a, b, c, p, q, x1, x2;
	while(1)
	{
		printf("input the coef of function: ax2+bx+c=0\n");
		scanf("%lf%lf%lf", &a, &b, &c);
		getchar();
		if (b * b - 4.0 * a * c > 0)
		{	
			break;
		}
		else
		{
			printf("b2 - 4ac = %lf < 0\n", b * b - 4.0 * a * c);
		}
	}
	p = -b / 2.0 / a;
	q = sqrt(b * b - 4.0 * a * c) / 2.0 / a;
	x1 = p + q;
	x2 = p - q;
	printf("root is x1=%lf, x2=%lf\n", x1, x2);
	printf("p=%lf, q=%lf\n", p, q);
}
