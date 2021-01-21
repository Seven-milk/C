#include <iostream>
using namespace std;
#include "speechManager.h";


int main()
{
	SpeechManager sm;
	// 测试
	/*for (map<int, Speaker>::iterator it = sm.m_Speaker.begin(); it != sm.m_Speaker.end(); it++)
	{
		cout << "选手编号：" << it->first;
		cout << " 姓名：" << it->second.m_Name;
		cout << " 成绩：" << it->second.m_Score[0] << endl;

	}*/

	while(true)
	{
		sm.show_Menu();
		cout << "请输入选择：" << endl;
		int choice;
		cin >> choice;

		switch (choice)
		{
		case 1: // 开始比赛
			sm.startSpeech();
			break;
		case2: // 查看记录
			sm.loadRecord();
			break;
		case3: // 清空记录
			break;
		case 0: // 退出系统
			sm.exitSystem();
			break;
		default:
			system("cls"); // 清屏
			break;
		}
	}
	


	system("pause");
	return 0;

}