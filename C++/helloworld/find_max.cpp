#include <iostream>
using namespace std;

int main1()
{
	int a, b, c, max = 0;
	cout << "������a" << endl;
	cin >> a;
	cout << "������b" << endl;
	cin >> b;
	cout << "������c" << endl;
	cin >> c;

	if (a > b)
	{
		max = a;
	}
	else 
	{
		max = b;
	}
	if (max < c)
	{
		max = c;
	}
	cout << "���ֵΪ" << max << endl;

	system("pause");

	return 0;

}