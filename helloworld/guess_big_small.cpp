#include <iostream>
using namespace std;

int main2()
{
	int num = rand() % 100 + 1;
	int guess = 0;



	while (1)
	{
		cout << "请猜测：" << endl;
		cin >> guess;

		if (guess > num)
		{
			cout << "猜大了" << endl;
		}
		else if (guess < num)
		{
			cout << "猜小了" << endl;
		}
		else
		{
			cout << "恭喜，猜对了" << endl;
			break;
		}
	}




	system("pause");

	return 0;

}