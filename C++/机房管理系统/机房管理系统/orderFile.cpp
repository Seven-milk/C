#include "orderFile.h"

OrderFile::OrderFile()
{
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);

	string date; // ����
	string interval; // ʱ���
	string stuId; // ѧ�����
	string stuName; // ѧ������
	string roomId; // �������
	string status; // ԤԼ״̬

	this->m_Size = 0; // ԤԼ��¼����

	// ���ж�ȡ��Ϣ(�ո�ָ�)��������map����
	while (ifs >> date && ifs >> interval && ifs >> stuId
		&& ifs >> stuName && ifs >> roomId && ifs >> status)
	{
		// ��ʱ�����������ݴ����ݣ�����д��map����
		string key;
		string value;
		map<string, string> m;

		// ����ÿһ�����ݽ��н������ҵ������зָ���������ݴ����Ӧ����ʱ��������ʱ����

		// date :�ָ�ǰ��
		int pos = date.find(":");
		if (pos != -1)
		{
			key = date.substr(0, pos); // keyΪ��date��
			value = date.substr(pos + 1, date.size() - pos); // valueΪdateֵ
			m.insert(make_pair(key, value)); // date�������Լ�ֵ����ʽ����map
		}

		// interval :�ָ�ǰ��
		pos = interval.find(":");
		if (pos != -1)
		{
			key = interval.substr(0, pos);
			value = interval.substr(pos + 1, interval.size() - pos);
			m.insert(make_pair(key, value));
		}

		// stuId :�ָ�ǰ��
		pos = stuId.find(":");
		if (pos != -1)
		{
			key = stuId.substr(0, pos);
			value = stuId.substr(pos + 1, stuId.size() - pos);
			m.insert(make_pair(key, value));
		}

		// stuName :�ָ�ǰ��
		pos = stuName.find(":");
		if (pos != -1)
		{
			key = stuName.substr(0, pos);
			value = stuName.substr(pos + 1, stuName.size() - pos);
			m.insert(make_pair(key, value));
		}

		// roomId :�ָ�ǰ��
		pos = roomId.find(":");
		if (pos != -1)
		{
			key = roomId.substr(0, pos);
			value = roomId.substr(pos + 1, roomId.size() - pos);
			m.insert(make_pair(key, value));
		}

		// status :�ָ�ǰ��
		pos = status.find(":");
		if (pos != -1)
		{
			key = status.substr(0, pos);
			value = status.substr(pos + 1, status.size() - pos);
			m.insert(make_pair(key, value));
		};

		// �������������map�Ͷ�Ӧ��ţ��ڼ������ݣ�
		this->m_orderData.insert(make_pair(this->m_Size, m));
		this->m_Size++;
	}
}

void OrderFile::updateOrder()
{
	// ����ļ�����Ϊ�գ��ͷ���
	if (this->m_Size == 0)
	{
		return;
	}

	// ��Ϊ�յ�����£���ɾ���ļ����´�������������Ϣʱ��ʵʱ���µ��ļ���
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