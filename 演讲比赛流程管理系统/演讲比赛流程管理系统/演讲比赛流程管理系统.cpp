#include <iostream>
using namespace std;
#include "speechManager.h";


int main()
{
	SpeechManager sm;
	// ����
	/*for (map<int, Speaker>::iterator it = sm.m_Speaker.begin(); it != sm.m_Speaker.end(); it++)
	{
		cout << "ѡ�ֱ�ţ�" << it->first;
		cout << " ������" << it->second.m_Name;
		cout << " �ɼ���" << it->second.m_Score[0] << endl;

	}*/

	while(true)
	{
		sm.show_Menu();
		cout << "������ѡ��" << endl;
		int choice;
		cin >> choice;

		switch (choice)
		{
		case 1: // ��ʼ����
			sm.startSpeech();
			break;
		case2: // �鿴��¼
			sm.loadRecord();
			break;
		case3: // ��ռ�¼
			break;
		case 0: // �˳�ϵͳ
			sm.exitSystem();
			break;
		default:
			system("cls"); // ����
			break;
		}
	}
	


	system("pause");
	return 0;

}