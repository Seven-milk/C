#include "orderFile.h"

OrderFile::OrderFile()
{
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);

	string date; // 日期
	string interval; // 时间段
	string stuId; // 学生编号
	string stuName; // 学生姓名
	string roomId; // 机房编号
	string status; // 预约状态

	this->m_Size = 0; // 预约记录个数

	// 逐行读取信息(空格分割)，并存入map容器
	while (ifs >> date && ifs >> interval && ifs >> stuId
		&& ifs >> stuName && ifs >> roomId && ifs >> status)
	{
		// 临时变量容器，暂存数据，最终写入map容器
		string key;
		string value;
		map<string, string> m;

		// 对于每一行数据进行解析，找到：进行分割，将各个数据存入对应的临时变量和临时容器

		// date :分割前后
		int pos = date.find(":");
		if (pos != -1)
		{
			key = date.substr(0, pos); // key为“date”
			value = date.substr(pos + 1, date.size() - pos); // value为date值
			m.insert(make_pair(key, value)); // date的数据以键值对形式存入map
		}

		// interval :分割前后
		pos = interval.find(":");
		if (pos != -1)
		{
			key = interval.substr(0, pos);
			value = interval.substr(pos + 1, interval.size() - pos);
			m.insert(make_pair(key, value));
		}

		// stuId :分割前后
		pos = stuId.find(":");
		if (pos != -1)
		{
			key = stuId.substr(0, pos);
			value = stuId.substr(pos + 1, stuId.size() - pos);
			m.insert(make_pair(key, value));
		}

		// stuName :分割前后
		pos = stuName.find(":");
		if (pos != -1)
		{
			key = stuName.substr(0, pos);
			value = stuName.substr(pos + 1, stuName.size() - pos);
			m.insert(make_pair(key, value));
		}

		// roomId :分割前后
		pos = roomId.find(":");
		if (pos != -1)
		{
			key = roomId.substr(0, pos);
			value = roomId.substr(pos + 1, roomId.size() - pos);
			m.insert(make_pair(key, value));
		}

		// status :分割前后
		pos = status.find(":");
		if (pos != -1)
		{
			key = status.substr(0, pos);
			value = status.substr(pos + 1, status.size() - pos);
			m.insert(make_pair(key, value));
		};

		// 向最终容器存放map和对应编号（第几条数据）
		this->m_orderData.insert(make_pair(this->m_Size, m));
		this->m_Size++;
	}
}

void OrderFile::updateOrder()
{
	// 如果文件条数为空，就返回
	if (this->m_Size == 0)
	{
		return;
	}

	// 不为空的情况下，就删了文件重新创建，当更新信息时，实时更新到文件中
	ofstream ofs(ORDER_FILE, ios::out | ios::trunc);
	for (int i = 0; i < this->m_Size; i++)
	{
		ofs << "date:" << this->m_orderData[i]["date"] << " ";
		ofs << "interval:" << this->m_orderData[i]["interval"] << " ";
		ofs << "stuId:" << this->m_orderData[i]["stuId"] << " ";
		ofs << "stuName:" << this->m_orderData[i]["stuName"] << " ";
		ofs << "roomId:" << this->m_orderData[i]["roomId"] << " ";
		ofs << "status:" << this->m_orderData[i]["status"] << endl;
	}
	ofs.close();
};