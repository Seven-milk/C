#pragma once
#include<iostream>
using namespace std;
#include<vector>;
#include<map>;
#include"speaker.h";

class SpeechManager 
{
public:
	// 构造
	SpeechManager();

	// 菜单功能
	void show_Menu();

	// 退出功能
	void exitSystem();

	// 析构
	~SpeechManager();

	// 初始化，成员函数
	void initSpeech();

	// 创建选手
	void createSpeaker();

	// 开始比赛
	void startSpeech();

	// 抽签函数
	void speechDraw();

	// 开始比赛内容函数
	void speechContest();

	// 显示比赛分数函数
	void showScore();

	// 保存分数函数
	void saveRecord();

	// 查看记录
	void loadRecord();

	// 成员属性
	// 	存放比赛选手编号的容器（12人）
	vector<int> v1;

	//  第一轮晋级的容器（6人）
	vector<int> v2;

	//  胜利前三名容器（3人）
	vector<int>vVictory;

	// 存放编号以及对应的具体选手的容器
	map<int, Speaker> m_Speaker;

	// 记录比赛轮数
	int m_Index;

	// 文件是否为空标志
	bool fileIsEmpty;

	// 往届记录的容器
	map <int, vector<string>> m_Record;
};
