#pragma once
#include "Station.h"

// �ӵ�ͼ�ļ��ж�ȡվ�����Ϣ������վ�������
extern "C" _declspec(dllimport) void __stdcall readMap(Station *stationArr );
// ��ȡ��ǰһ����վ�������
extern "C" _declspec(dllimport) int __stdcall getStationNum(Station *stationArr);

