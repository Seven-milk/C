#include <iostream>
using namespace std;

int main1()
{
	int a, b, c, max = 0;
	cout << "请输入a" << endl;
	cin >> a;
	cout << "请输入b" << endl;
	cin >> b;
	cout << "请输入c" << endl;
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
	cout << "最大值为" << max << endl;

	system("pause");

	return 0;

}