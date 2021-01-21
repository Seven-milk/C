#pragma once
#include<iostream>
using namespace std;
#include<vector>;
#include<map>;
#include"speaker.h";

class SpeechManager 
{
public:
	// ����
	SpeechManager();

	// �˵�����
	void show_Menu();

	// �˳�����
	void exitSystem();

	// ����
	~SpeechManager();

	// ��ʼ������Ա����
	void initSpeech();

	// ����ѡ��
	void createSpeaker();

	// ��ʼ����
	void startSpeech();

	// ��ǩ����
	void speechDraw();

	// ��ʼ�������ݺ���
	void speechContest();

	// ��ʾ������������
	void showScore();

	// �����������
	void saveRecord();

	// �鿴��¼
	void loadRecord();

	// ��Ա����
	// 	��ű���ѡ�ֱ�ŵ�������12�ˣ�
	vector<int> v1;

	//  ��һ�ֽ�����������6�ˣ�
	vector<int> v2;

	//  ʤ��ǰ����������3�ˣ�
	vector<int>vVictory;

	// ��ű���Լ���Ӧ�ľ���ѡ�ֵ�����
	map<int, Speaker> m_Speaker;

	// ��¼��������
	int m_Index;

	// �ļ��Ƿ�Ϊ�ձ�־
	bool fileIsEmpty;

	// �����¼������
	map <int, vector<string>> m_Record;
};
