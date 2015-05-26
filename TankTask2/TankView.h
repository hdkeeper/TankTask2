#pragma once
#include "Model.h"

using namespace System::Drawing;

// ����������� ������������� ������
ref class TankView
{
public:
	// ������ �� ��������� ������
	Tank *tank = 0;
	
	// ������ � ��������
	int width = 0;

	// ������ � ��������
	int height = 0;

	// ���� ������ ������ ����
	Brush ^waterB = nullptr;

	// ���� ������ ������ ��������
	Brush ^gateB = nullptr;

	// ���� ����� ������� �������
	Pen ^borderP = nullptr;

	// ���� ����� ������ �������
	Pen ^sensorP = nullptr;

	// ����������� �������
	TankView( int width, int height);

	// ���������� �������
	~TankView();

	// ���������� �������������
	void draw( Graphics ^g);
};

