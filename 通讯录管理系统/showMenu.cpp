#include "ͨѶ¼����ϵͳ.h"
void showMenu() {
	string menu[7] = { "1�������ϵ��","2����ʾ��ϵ��","3��ɾ����ϵ��",
		"4��������ϵ��","5���޸���ϵ��","6�������ϵ��","0���˳�ͨѶ¼" };
	for (int i = 0; i < 27; i++) {
		cout << "*";
	};
	cout << endl;
	for (int i = 0; i < 7; i++) {
		cout << "*****  " << menu[i] << "  *****" << endl;
	};
	for (int i = 0; i < 27; i++) {
		cout << "*";
	};
	cout << endl;
}