#include <iostream>
using namespace std;


int main12()
{
	char a[3] = { 'a','b','c' };
	char* p = a;
	cout << *p << endl;
	p++;
	cout << *p << endl;
	cout << sizeof(&a[0]) << endl;
	cout << sizeof(p) << endl;
	system("pause");

	return 0;

}