#include "通讯录管理系统.h"
void showMenu() {
	string menu[7] = { "1、添加联系人","2、显示联系人","3、删除联系人",
		"4、查找联系人","5、修改联系人","6、清空联系人","0、退出通讯录" };
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