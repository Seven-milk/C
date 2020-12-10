#include <iostream>
#include <string>
using namespace std;


struct Student 
{
	string name;
	int score;
};

struct Teacher
{
	string name;
	Student stu_arr[5];
};

void input_content(Teacher *p_teacher, int len)
{	
	for (int i = 0; i < len; i++)
	{
		p_teacher->name = "teacher" + to_string(i + 1);
		for (int j = 0; j < 5; j++)
		{
			int score = rand() % 100 + 1;
			string stu_name = "stu" + to_string(j + 1);
			Student stu = { stu_name , score };
			p_teacher->stu_arr[j] = stu;
		}
		p_teacher++;
	}
};

void print_struct(const Teacher* p_teacher, int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << p_teacher->name << ":\n";
		for (int j = 0; j < 5; j++) 
		{
			cout << p_teacher->stu_arr[j].name << " " << p_teacher->stu_arr[j].score << " ";
		}
		cout << endl;
		p_teacher++;
	}
}

int main14()
{
	Teacher teacher_arr[3];
	int len = sizeof(teacher_arr) / sizeof(teacher_arr[0]);
	input_content(teacher_arr, len);
	print_struct(teacher_arr, len);

	system("pause");

	return 0;

}