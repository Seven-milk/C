#include <iostream>
using namespace std;

void bubble(int * arr, int len)
{
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < len - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int store = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = store;
			};
		};
	};
};

void PrintArray(int * arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << endl;
	};

};

int main13()
{
	int arr[10] = { 4,3,6,9,1,2,10,8,7,5 };
	int len = sizeof(arr) / sizeof(arr[0]);

	cout << "更换顺序前" << endl;
	PrintArray(arr, len);
	bubble(arr, len);
	cout << "更换顺序后" << endl;
	PrintArray(arr, len);


	system("pause");

	return 0;

}