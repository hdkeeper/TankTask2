#include "Model.h"

/* ----------------------------------------------------
	class Tube
	�����, ���������� ��� ��������� ����
*/

// ����������� �������
Tube::Tube(double perfomance, bool active)
{
	this->perfomance = perfomance;
	this->active = active;
}

/* ----------------------------------------------------
	class Sensor
	������ ������, ������� �����
*/

// ����������� �������
Sensor::Sensor(double height, Tube *tube)
{
	this->height = height;
	this->tube = tube;
}

/* ----------------------------------------------------
	class OpeningSensor
	������ ������, ����������� ��������
*/

// ����������� �������
OpeningSensor::OpeningSensor(double height, Tube *tube) : 
Sensor(height, tube) {}

// ��������� ������� ����
void OpeningSensor::check(double height)
{
	// ���� ������� ���� ���� ������������ �������
	if (height >= this->height) {
		// ������� �������� �����
		tube->active = true;
	}
}

/* ----------------------------------------------------
	class ClosingSensor
	������ ������, ����������� ��������
*/

// ����������� �������
ClosingSensor::ClosingSensor(double height, Tube *tube) :
Sensor(height, tube) {}

// ��������� ������� ����
void ClosingSensor::check(double height)
{
	// ���� ������� ���� ���� ������������ �������
	if (height < this->height) {
		// ������� �������� �����
		tube->active = false;
	}
}

/* ----------------------------------------------------
	class Tank
	������� � �����
*/

// ����������� �������
Tank::Tank()
{
	capacity = 50;
	volume = 0;

	// ���������� �����
	inTube = new Tube( 2.5, true);

	// ��������� �����
	outTube = new Tube( -5, false);

	// ����������� ������
	openingSensor = new OpeningSensor(0.9, outTube);

	// ����������� ������
	closingSensor = new ClosingSensor(0.6, outTube);
}

// ���������� �������
Tank::~Tank()
{
	delete openingSensor;
	delete closingSensor;
	delete inTube;
	delete outTube;
}

// ���������� ������� ������ ������ ����, �� 0 �� 1
double Tank::height()
{
	return (volume / capacity);
}

// ��������� ��������� �������
void Tank::update()
{
	// ����� ��������� ��� ���������� �������, ���� �������
	if (inTube->active)
		volume += inTube->perfomance * dt;

	if (outTube->active)
		volume += outTube->perfomance * dt;

	// �������� ������������ �������
	if (volume < 0)
		volume = 0;

	if (volume > capacity)
		volume = capacity;

	// ��������� �������
	openingSensor->check(height());
	closingSensor->check(height());

	time += dt;
}

