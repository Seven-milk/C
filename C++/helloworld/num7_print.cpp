#include <iostream>
using namespace std;

int main5()
{
	int a, b, c = 0;
	for (int i = 1; i < 101; i++)
	{
		a = i % 10;
		b = i / 10 % 10;
		c = i % 7;
		if (a == 7 || b == 7 || c == 0)
		{
			cout << "ÇÃ×À×Ó" << endl;
		}
		else
		{
			cout << i << endl;
		}
	}

	system("pause");

	return 0;

}