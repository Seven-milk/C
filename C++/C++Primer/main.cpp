/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2021年06月29日 17时04分57秒
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  XudongZheng (), z786909151@163.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
// using namespace std;

int main()
{
	int x=1, y=2;
	for (;x<=10;x++)
	{
		x += y;
	}
	std::cout << "x="  << x  << std::endl;
}
