#include <iostream>
#include<string>

using namespace std;


class Student {
public:
	string name;
	int number;

	void show() {
		cout << "name: " << name << " number: " << number << endl;
	}
};

int main()
{
	Student student1;
	student1.name = "ÕÅÈý";
	student1.number = 123456;
	student1.show();
	system("pause");

	return 0;

}