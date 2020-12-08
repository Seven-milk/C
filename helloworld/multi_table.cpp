#include <iostream>
using namespace std;

int main()
{
	int a, b, c = 0;
	for (int i = 1; i < 10; i++)
	{
		for (int j = 1; j < i + 1; j++)
		{
			cout << i << "*" << j << "=" << i * j << " ";
		}
		cout << "\n";
	}

	system("pause");

	return 0;

}