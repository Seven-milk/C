#include <iostream>
using namespace std;

int main7()
{
	int max = 0;
	int arr[5] = {300,350,200,400,250};

	for (int i = 0; i < 5; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		};

	};

	cout << "最大值为" << max << endl;

	system("pause");

	return 0;

}