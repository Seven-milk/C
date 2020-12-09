#include <iostream>
using namespace std;

int main10()
{
	int store = 0;
	int arr[] = { 4,2,8,0,5,7,1,3,9 };
	int start = 0;
	int end = sizeof(arr) / sizeof(arr[0]) - 1;
	int turn = end;

	cout << "更换顺序前" << endl;
	for (int i = 0; i <= end; i++)
	{
		cout << arr[i] << endl;
	};

	while (turn >= 1)
	{
		for (int i=0; i<turn;i++)
		{
			if (arr[i] > arr[i+1])
			{
				store = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = store;
			}
		};
		turn--;
	};


	start = 0;
	end = sizeof(arr) / sizeof(arr[0]) - 1;

	cout << "更换顺序后" << endl;
	for (int i = 0; i <= end; i++)
	{
		cout << arr[i] << endl;
	};

	system("pause");

	return 0;

}