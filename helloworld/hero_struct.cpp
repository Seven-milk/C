#include <iostream>
#include <string>
using namespace std;

struct Hero
{
	string name;
	int age;
	string sex;
};

void print_struct(const Hero * p_hero, int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << p_hero->name << " " << p_hero->age << " " << p_hero->sex << endl;
		p_hero++;
	}
}

void bubble(Hero * arr, int len)
{
	Hero* arr_ = arr;
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < len - i - 1; j++)
		{
			if (arr->age > (arr + 1)->age)
			{
				Hero store = *arr;
				*(arr) = *(arr + 1);
				*(arr + 1)= store;
			};
			arr++;
		};
		arr = arr_;
	};
};

int main15()
{
	Hero hero_arr[5] =
	{
		{"Áõ±¸", 23, "ÄĞ"},
		{"¹ØÓğ", 22, "ÄĞ"},
		{"ÕÅ·É", 20, "ÄĞ"},
		{"ÕÔÔÆ", 21, "ÄĞ"},
		{"õõ²õ", 19, "Å®"},
	};
	cout << "ÅÅĞòÇ°" << endl;
	int len = sizeof(hero_arr) / sizeof(hero_arr[0]);
	print_struct(hero_arr, len);
	bubble(hero_arr, len);
	cout << "ÅÅĞòºó" << endl;
	print_struct(hero_arr, len);
	system("pause");

	return 0;
}