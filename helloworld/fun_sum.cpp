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
	cout << "ÇëÊäÈëa" << endl;
	cin >> a;
	cout << "ÇëÊäÈëb" << endl;
	cin >> b;
	
	int s = sum(a, b);
	cout << "a + b = " << s;

	system("pause");

	return 0;

}