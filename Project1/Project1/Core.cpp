#include <cstdlib>
#include <fstream>
#include <sstream>
#include <queue>
#include "Core.h"

#define STATION_NUM 300

void readMap(Station *stationArr) {

	string lineName;
	string station_str;
	string word;
	int stationIndex; // ��վ���
	queue<string> temp;
	ifstream fin;
	int last_index; //��һ����վ����������±�ֵ

	fin.open("beijing-subway.txt");

	//��ȡһ����·����Ϣ
	while (getline(fin, lineName)) {

		// ������·���͸���·�ϵ�����վ��վ����վ�ţ���string����ʽװ�������
		getline(fin, station_str);
		stringstream ss(station_str);
		while (ss >> word) {
			temp.push(word);
		}

		// ���������վ����վ��ȡ��������������
		while (!temp.empty()) {
			word = temp.front();
			temp.pop();
			stationIndex = atoi(temp.front().c_str());
			temp.pop();

			// ��վ�����������
			if (!stationArr[stationIndex].isEmpty()) { // �Ѵ��ڵ�վ��
				stationArr[stationIndex].addLine(lineName); // ����·�ӽ�ȥ
			}
			else { // δ�����վ��

				stationArr[stationIndex] = Station(word, lineName);
				//st_map.insert(pair<string, int>(word, st_num));

			}

		}

		fin.close();

	}
}

int getStationNum(Station * stationArr) {

	for (int i = 0; i < STATION_NUM; ++i) {
		if (stationArr[i].name == "") {
			return i;
		}
	}

	return 0;
}
