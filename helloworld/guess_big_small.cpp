#include <iostream>
using namespace std;

int main2()
{
	int num = rand() % 100 + 1;
	int guess = 0;



	while (1)
	{
		cout << "��²⣺" << endl;
		cin >> guess;

		if (guess > num)
		{
			cout << "�´���" << endl;
		}
		else if (guess < num)
		{
			cout << "��С��" << endl;
		}
		else
		{
			cout << "��ϲ���¶���" << endl;
			break;
		}
	}




	system("pause");

	return 0;

}