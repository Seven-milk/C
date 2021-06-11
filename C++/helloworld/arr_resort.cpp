#include <iostream>
using namespace std;

int main9()
{
	int store = 0;
	int arr[5] = { 300,350,200,400,250 };
	int start = 0;
	int end = sizeof(arr) / sizeof(arr[0]) - 1;

	cout << "更换顺序前" << endl;
	for (int i = 0;i<=end; i++)
	{
		cout << arr[i] << endl;
	}

	while (start < end) 
	{
		store = arr[start];
		arr[start] = arr[end];
		arr[end] = store;
		start++;
		end--;
	}

	start = 0;
	end = sizeof(arr) / sizeof(arr[0]) - 1;

	cout << "更换顺序后" << endl;
	for (int i = 0; i <= end; i++)
	{
		cout << arr[i] << endl;
	}

	system("pause");

	return 0;

}