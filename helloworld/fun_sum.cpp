#include <iostream>
using namespace std;

int sum(int a, int b)
{
	return a + b;
}

int main()
{
	int a;
	int b;
	cout << "������a" << endl;
	cin >> a;
	cout << "������b" << endl;
	cin >> b;
	
	int s = sum(a, b);
	cout << "a + b = " << s;

	system("pause");

	return 0;

}