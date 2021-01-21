#include "speechManager.h";
#include<algorithm>;
#include<deque>;
#include<functional>;
#include<numeric>;
#include <fstream>;
#define filePath "speech.csv"

// 构造
SpeechManager::SpeechManager()
{
	// 初始化
	this->initSpeech();
	// 创建选手
	this->createSpeaker();
	// 读取文件
	this->loadRecord();
};

// 菜单
void SpeechManager::show_Menu()
{
	cout << "*******************************" << endl;
	cout << "****** 欢迎参加演讲比赛 *******" << endl;
	cout << "****** 1. 开始演讲比赛  *******" << endl;
	cout << "****** 2. 查看往届记录  *******" << endl;
	cout << "****** 3. 清空比赛记录  *******" << endl;
	cout << "****** 0. 退出比赛程序  *******" << endl;
	cout << "*******************************" << endl;
	cout << endl;
};

// 退出功能
void SpeechManager::exitSystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
};

// 初始化，成员函数
void SpeechManager::initSpeech()
{
	// 容器保证为空
	this->v1.clear();
	this->v2.clear();
	this->vVictory.clear();
	this->m_Speaker.clear();
	// 初始化比赛轮数
	this->m_Index = 1;
};

// 创建选手
void SpeechManager::createSpeaker()
{
	string nameSeed = "ABCDEFGHIJKL";
	for (int i = 0; i < nameSeed.size(); i++)
	{
		string name = "选手";
		name += nameSeed[i];
		// 创建选手
		Speaker sp;
		// 初始化名称
		sp.m_Name = name;
		// 初始化分数
		for (int i = 0; i < 2; i++)
		{
			sp.m_Score[i] = 0;
		}
		// 给12名选手编号
		this->v1.push_back(i + 10001);
		// 将编号和选手放入map容器
		this->m_Speaker.insert(make_pair(i + 10001, sp));
	}
};

// 抽签函数
void SpeechManager::speechDraw()
{
	cout << "第 << " << this->m_Index << " >> 轮比赛选手正在抽签" << endl;
	cout << "--------------------------" << endl;
	cout << "抽签后演讲顺序如下：" << endl;
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

// 开始比赛内容函数
void SpeechManager::speechContest()
{
	cout << "---------------------第" << this->m_Index << "轮比赛开始：------" << endl;
	
	vector<int> v_Src; // 比赛选手容器 
	multimap<double, int, greater<double>> groupScore; // 临时容器，6人一组，为了分组取前3名
	//键值对（double(分数)， int （编号）），用从大到小排序

	int num = 0; // 记录人员个数，6人一组


	if (this->m_Index == 1) // 第一轮比赛
	{
		v_Src = this->v1;
	}
	else // 第二轮比赛
	{
		v_Src = this->v2;
	};

	// 遍历所有选手进行比赛
	for (vector<int>::iterator it = v_Src.begin(); it != v_Src.end(); it++)
	{
		num++;
		// 评委打分
		deque<double>d;
		for (int i=0; i<10; i++) // 10个评委
		{
			double score = (rand() % 401 + 600) / 10.f; // 600~1000 
			// cout << score << " ";  // 测试输出
			d.push_back(score);
		}
		// cout << endl;
		// 降序排列
		sort(d.begin(), d.end(), greater<double>());
		// 去除最高分和最低分
		d.pop_front();
		d.pop_back();
		double sum = accumulate(d.begin(), d.end(), 0.0f);
		double avg = sum / double(d.size()); // 平均分，强转为double，为了同种类运算
		// cout << "姓名" << this->m_Speaker[*it].m_Name << "平均分为" << avg << endl; // 测试

		// 将平均分存入容器
		this->m_Speaker[*it].m_Score[(this->m_Index) - 1] = avg;

		// 将打分数据存入临时容器
		groupScore.insert(make_pair(avg, *it)); // key是得分，value是编号
		
		// 每6人取前3，每6个人（每次整除6）打印一次
		if (num % 6 == 0)
		{
			cout << "第" << num / 6 << "组名次如下：" << endl;
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end(); it++)
			{
				cout << "编号：" << it->second << " 姓名：" << this->m_Speaker[it->second].m_Name << " 成绩："
					<< this->m_Speaker[it->second].m_Score[this->m_Index - 1] << endl;
			};
			// 取走前3名，作为晋级第二轮，或总结果
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
			groupScore.clear(); // 每个小组比完了（6个人），清空临时容器，重新装载
			cout << endl;
		}
	}
	cout << "----------第" << this->m_Index << "轮比赛完毕-----------" << endl;
	system("pause");
}

// 显示比赛分数函数
void SpeechManager::showScore()
{
	cout << "-----------第" << this->m_Index << "轮晋级选手信息如下：-------------" << endl;
	vector<int>v; // 创建容器，用于统一轮数
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
		cout << "选手编号：" << *it << " 选手姓名：" << this->m_Speaker[*it].m_Name 
			<< " 得分：" << this->m_Speaker[*it].m_Score[this->m_Index - 1] << endl;
	}
	cout << endl;

	system("pause");
	system("cls");
	this->show_Menu();
}

// 保存分数函数
void SpeechManager::saveRecord()
{
	ofstream ofs;
	ofs.open("speech.csv", ios::out | ios::app); // 用输出的方式打开文件，追加方式

	// 存储每个人的数据
	for (vector<int>::iterator it = this->vVictory.begin(); it != this->vVictory.end(); it++)
	{
		ofs << *it << ","
			<< this->m_Speaker[*it].m_Score[1] << ",";
	}
	ofs << endl;

	// 关闭文件
	ofs.close();

	cout << "已保存记录" << endl;

}


// 开始比赛
void SpeechManager::startSpeech()
{
	// 抽签：第一轮
	this->speechDraw();
	// 开始演讲比赛
	this->speechContest();
	// 显示第一轮比赛结果
	this->showScore();
	// 抽签：第二轮
	this->m_Index++;
	this->speechDraw();
	// 开始演讲比赛
	this->speechContest();
	//  显示前三名结果
	this->showScore();
	// 保存分数
	this->saveRecord();
	
	// 清屏
	cout << "本届比赛完毕！" << endl;
	system("pause");
	system("cls");
};

// 查看记录
void SpeechManager::loadRecord()
{
	ifstream ifs(filePath, ios::in); // 写入方式读入
	// 文件不存在
	if (!ifs.is_open()) // 取反，表示找不到
	{
		this->fileIsEmpty = true;
		cout << "文件不存在!" << endl;
		ifs.close();
		return;
	};
	// 文件存在，但被清空
	char ch;
	ifs >> ch; // 读一个字符，用于判断是否为空
	if (ifs.eof()) // 直接读到末尾，表示为空
	{
		cout << "文件为空!" << endl;
		ifs.close();
		return;
	}
	// 文件存在，且不为空
	ifs.putback(ch); // 将读取的单个字符放回去
	string data;
	int index = 0;
	while (ifs >> data) // 右移读取，读取每一行数据（会一行行读），需要进行分割（","分割），相当于分词操作
	{
		vector<string>v;
		int pos = -1;
		int start = 0;
		while (true)
		{
			pos = data.find(",", start); // 从0开始查找","
			if (pos == -1)
			{
				break; // 找不到break返回
			}
			string tmp = data.substr(start, pos - start); // 找到了进行分割：start(起始位置),pos-start(截取长度)
			v.push_back(tmp);
			start = pos + 1;
		}
		this->m_Record.insert(make_pair(index, v)); // 将分割后的每个单元放入v中，然后存放到m_Record中，key是序号index，value是vector
		index++;
	}
	ifs.close();

};

// 析构
SpeechManager::~SpeechManager() {};
