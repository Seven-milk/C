#include <iostream>
#include <math.h>
using namespace std;

int main4()
{
	int num = 100;
	int a, b, c = 0;

	do
	{
		a = num / 100;
		b = (num - a * 100) / 10;
		c = (num - a * 100 - b * 10);
		if (pow(a, 3) + pow(b, 3) + pow(c, 3) == num)
		{
			cout << num << endl;
		}
		num += 1;

	}
	while (num < 1000);

	system("pause");

	return 0;

}