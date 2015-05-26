#include "TankView.h"
#include <math.h>

// ����������� �������
TankView::TankView(int width, int height)
{
	this->width = width;
	this->height = height;
	
	// ��������� ������
	tank = new Tank();

	// ����� � �����
	waterB = gcnew SolidBrush(Color::LightBlue);
	gateB = gcnew SolidBrush(Color::Black);
	borderP = gcnew Pen(Color::Black, 2);
	sensorP = gcnew Pen(Color::DarkBlue, 3);
}

// ���������� �������
TankView::~TankView()
{
	delete tank;
	delete waterB;
	delete gateB;
	delete borderP;
	delete sensorP;
}

// ���������� ����������� ������������� �������
void TankView::draw(Graphics ^g)
{
	int tubeHeight = 50;
	int tankHeight = height - 2 * tubeHeight;

	// ���������� �����
	int tubeWidth = lround(tubeHeight * tank->inTube->perfomance / abs(tank->outTube->perfomance));
	if (tank->inTube->active) {
		// ������ ����
		g->FillRectangle(waterB, 
			(width - tubeWidth) / 2, 2, 
			tubeWidth, tubeHeight + tankHeight);
	}
	g->DrawRectangle(borderP, 
		(width - tubeWidth) / 2, 2, 
		tubeWidth, tubeHeight - 2);

	// ��� � �����
	int waterHeight = lround(tankHeight * tank->volume / tank->capacity);
	g->FillRectangle(waterB, 
		5, tubeHeight + tankHeight - waterHeight, 
		width - 10, waterHeight);
	
	g->DrawRectangle(borderP, 
		5, tubeHeight, 
		width - 10, tankHeight);

	// ��������� �����
	if (tank->outTube->active) {
		// ������ ����
		g->FillRectangle(waterB,
			(width - tubeHeight) / 2, tubeHeight + tankHeight,
			tubeHeight, tubeHeight - 2);
	}
	else {
		// ������ �������� ��������
		g->FillRectangle(gateB,
			(width - tubeHeight) / 2, tubeHeight + tankHeight,
			tubeHeight, 10);
	}
	g->DrawRectangle(borderP,
		(width - tubeHeight) / 2, tubeHeight + tankHeight,
		tubeHeight, 10);

	g->DrawRectangle(borderP, 
		(width - tubeHeight) / 2, tubeHeight + tankHeight,
		tubeHeight, tubeHeight - 2);

	// �������
	int sensorHeight = lround(tankHeight * tank->openingSensor->height);
	g->DrawEllipse(sensorP,
		0, tubeHeight + tankHeight - sensorHeight - 5,
		9, 9);

	sensorHeight = lround(tankHeight * tank->closingSensor->height);
	g->DrawEllipse(sensorP,
		width - 10, tubeHeight + tankHeight - sensorHeight - 5,
		9, 9);
}

