#include "speechManager.h";
#include<algorithm>;
#include<deque>;
#include<functional>;
#include<numeric>;
#include <fstream>;
#define filePath "speech.csv"

// ����
SpeechManager::SpeechManager()
{
	// ��ʼ��
	this->initSpeech();
	// ����ѡ��
	this->createSpeaker();
	// ��ȡ�ļ�
	this->loadRecord();
};

// �˵�
void SpeechManager::show_Menu()
{
	cout << "*******************************" << endl;
	cout << "****** ��ӭ�μ��ݽ����� *******" << endl;
	cout << "****** 1. ��ʼ�ݽ�����  *******" << endl;
	cout << "****** 2. �鿴�����¼  *******" << endl;
	cout << "****** 3. ��ձ�����¼  *******" << endl;
	cout << "****** 0. �˳���������  *******" << endl;
	cout << "*******************************" << endl;
	cout << endl;
};

// �˳�����
void SpeechManager::exitSystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
};

// ��ʼ������Ա����
void SpeechManager::initSpeech()
{
	// ������֤Ϊ��
	this->v1.clear();
	this->v2.clear();
	this->vVictory.clear();
	this->m_Speaker.clear();
	// ��ʼ����������
	this->m_Index = 1;
};

// ����ѡ��
void SpeechManager::createSpeaker()
{
	string nameSeed = "ABCDEFGHIJKL";
	for (int i = 0; i < nameSeed.size(); i++)
	{
		string name = "ѡ��";
		name += nameSeed[i];
		// ����ѡ��
		Speaker sp;
		// ��ʼ������
		sp.m_Name = name;
		// ��ʼ������
		for (int i = 0; i < 2; i++)
		{
			sp.m_Score[i] = 0;
		}
		// ��12��ѡ�ֱ��
		this->v1.push_back(i + 10001);
		// ����ź�ѡ�ַ���map����
		this->m_Speaker.insert(make_pair(i + 10001, sp));
	}
};

// ��ǩ����
void SpeechManager::speechDraw()
{
	cout << "�� << " << this->m_Index << " >> �ֱ���ѡ�����ڳ�ǩ" << endl;
	cout << "--------------------------" << endl;
	cout << "��ǩ���ݽ�˳�����£�" << endl;
	if (this->m_Index == 1)
	{
		random_shuffle(v1.begin(), v1.end());
		for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
		{
			cout << *it << " ";
		};
		cout << endl;
	}
	if (this->m_Index == 2)
	{
		random_shuffle(v2.begin(), v2.end());
		for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
		{
			cout << *it << " ";
		};
		cout << endl;
	}
	cout << "--------------------------" << endl;
	system("pause");
	cout << endl;
}

// ��ʼ�������ݺ���
void SpeechManager::speechContest()
{
	cout << "---------------------��" << this->m_Index << "�ֱ�����ʼ��------" << endl;
	
	vector<int> v_Src; // ����ѡ������ 
	multimap<double, int, greater<double>> groupScore; // ��ʱ������6��һ�飬Ϊ�˷���ȡǰ3��
	//��ֵ�ԣ�double(����)�� int ����ţ������ôӴ�С����

	int num = 0; // ��¼��Ա������6��һ��


	if (this->m_Index == 1) // ��һ�ֱ���
	{
		v_Src = this->v1;
	}
	else // �ڶ��ֱ���
	{
		v_Src = this->v2;
	};

	// ��������ѡ�ֽ��б���
	for (vector<int>::iterator it = v_Src.begin(); it != v_Src.end(); it++)
	{
		num++;
		// ��ί���
		deque<double>d;
		for (int i=0; i<10; i++) // 10����ί
		{
			double score = (rand() % 401 + 600) / 10.f; // 600~1000 
			// cout << score << " ";  // �������
			d.push_back(score);
		}
		// cout << endl;
		// ��������
		sort(d.begin(), d.end(), greater<double>());
		// ȥ����߷ֺ���ͷ�
		d.pop_front();
		d.pop_back();
		double sum = accumulate(d.begin(), d.end(), 0.0f);
		double avg = sum / double(d.size()); // ƽ���֣�ǿתΪdouble��Ϊ��ͬ��������
		// cout << "����" << this->m_Speaker[*it].m_Name << "ƽ����Ϊ" << avg << endl; // ����

		// ��ƽ���ִ�������
		this->m_Speaker[*it].m_Score[(this->m_Index) - 1] = avg;

		// ��������ݴ�����ʱ����
		groupScore.insert(make_pair(avg, *it)); // key�ǵ÷֣�value�Ǳ��
		
		// ÿ6��ȡǰ3��ÿ6���ˣ�ÿ������6����ӡһ��
		if (num % 6 == 0)
		{
			cout << "��" << num / 6 << "���������£�" << endl;
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end(); it++)
			{
				cout << "��ţ�" << it->second << " ������" << this->m_Speaker[it->second].m_Name << " �ɼ���"
					<< this->m_Speaker[it->second].m_Score[this->m_Index - 1] << endl;
			};
			// ȡ��ǰ3������Ϊ�����ڶ��֣����ܽ��
			int count = 0;
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end() && count < 3; it++, count++)
			{
				if (this->m_Index == 1)
				{
					this->v2.push_back((*it).second);
				}
				else
				{
					this->vVictory.push_back((*it).second);
				}

			}
			groupScore.clear(); // ÿ��С������ˣ�6���ˣ��������ʱ����������װ��
			cout << endl;
		}
	}
	cout << "----------��" << this->m_Index << "�ֱ������-----------" << endl;
	system("pause");
}

// ��ʾ������������
void SpeechManager::showScore()
{
	cout << "-----------��" << this->m_Index << "�ֽ���ѡ����Ϣ���£�-------------" << endl;
	vector<int>v; // ��������������ͳһ����
	if (this->m_Index == 1)
	{
		v = this->v2;
	}
	else
	{
		v = this->vVictory;
	}
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "ѡ�ֱ�ţ�" << *it << " ѡ��������" << this->m_Speaker[*it].m_Name 
			<< " �÷֣�" << this->m_Speaker[*it].m_Score[this->m_Index - 1] << endl;
	}
	cout << endl;

	system("pause");
	system("cls");
	this->show_Menu();
}

// �����������
void SpeechManager::saveRecord()
{
	ofstream ofs;
	ofs.open("speech.csv", ios::out | ios::app); // ������ķ�ʽ���ļ���׷�ӷ�ʽ

	// �洢ÿ���˵�����
	for (vector<int>::iterator it = this->vVictory.begin(); it != this->vVictory.end(); it++)
	{
		ofs << *it << ","
			<< this->m_Speaker[*it].m_Score[1] << ",";
	}
	ofs << endl;

	// �ر��ļ�
	ofs.close();

	cout << "�ѱ����¼" << endl;

}


// ��ʼ����
void SpeechManager::startSpeech()
{
	// ��ǩ����һ��
	this->speechDraw();
	// ��ʼ�ݽ�����
	this->speechContest();
	// ��ʾ��һ�ֱ������
	this->showScore();
	// ��ǩ���ڶ���
	this->m_Index++;
	this->speechDraw();
	// ��ʼ�ݽ�����
	this->speechContest();
	//  ��ʾǰ�������
	this->showScore();
	// �������
	this->saveRecord();
	
	// ����
	cout << "���������ϣ�" << endl;
	system("pause");
	system("cls");
};

// �鿴��¼
void SpeechManager::loadRecord()
{
	ifstream ifs(filePath, ios::in); // д�뷽ʽ����
	// �ļ�������
	if (!ifs.is_open()) // ȡ������ʾ�Ҳ���
	{
		this->fileIsEmpty = true;
		cout << "�ļ�������!" << endl;
		ifs.close();
		return;
	};
	// �ļ����ڣ��������
	char ch;
	ifs >> ch; // ��һ���ַ��������ж��Ƿ�Ϊ��
	if (ifs.eof()) // ֱ�Ӷ���ĩβ����ʾΪ��
	{
		cout << "�ļ�Ϊ��!" << endl;
		ifs.close();
		return;
	}
	// �ļ����ڣ��Ҳ�Ϊ��
	ifs.putback(ch); // ����ȡ�ĵ����ַ��Ż�ȥ
	string data;
	int index = 0;
	while (ifs >> data) // ���ƶ�ȡ����ȡÿһ�����ݣ���һ���ж�������Ҫ���зָ","�ָ���൱�ڷִʲ���
	{
		vector<string>v;
		int pos = -1;
		int start = 0;
		while (true)
		{
			pos = data.find(",", start); // ��0��ʼ����","
			if (pos == -1)
			{
				break; // �Ҳ���break����
			}
			string tmp = data.substr(start, pos - start); // �ҵ��˽��зָstart(��ʼλ��),pos-start(��ȡ����)
			v.push_back(tmp);
			start = pos + 1;
		}
		this->m_Record.insert(make_pair(index, v)); // ���ָ���ÿ����Ԫ����v�У�Ȼ���ŵ�m_Record�У�key�����index��value��vector
		index++;
	}
	ifs.close();

};

// ����
SpeechManager::~SpeechManager() {};
