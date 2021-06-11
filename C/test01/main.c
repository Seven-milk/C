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
#define ratio 0.8

void main()
{
		float pre,runoff;
		printf("input pre:\n");
		scanf("%3f", &pre);
		runoff=pre * ratio;
		printf("pre %3f -> runoff %2f\n", pre, runoff);
};
