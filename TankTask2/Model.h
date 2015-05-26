#pragma once

// �����, ���������� ��� ��������� ����
class Tube {
public:
	// ������������������ �����, �/�
	// ������ ����, ���� ���� ��������� � ������� � ������ ����, ���� ���� ���������
	double perfomance = 0;

	// true, ���� �������� ������� � ����� ��������
	bool active = false;

	// ����������� �������
	Tube(double perfomance, bool active);
};


// ������ ������, ������� �����
class Sensor {
public:
	// ������ ���������� �������
	// 0 - ����� ���, 1 - ����� ����
	double height = 0;

	// ������ �� �����, ������� ��������� ������
	Tube *tube = 0;

	// ����������� �������
	Sensor(double height, Tube *tube);
	
	// ��������� ������� ����
	virtual void check(double height) = 0;
};


// ������ ������, ����������� ��������
class OpeningSensor : public Sensor {
public:
	// ����������� �������
	OpeningSensor(double height, Tube *tube);
	
	// ��������� ������� ����
	virtual void check(double height);
};


// ������ ������, ����������� ��������
class ClosingSensor : public Sensor {
public:
	// ����������� �������
	ClosingSensor(double height, Tube *tube);

	// ��������� ������� ����
	virtual void check(double height);
};


// ������� � �����
class Tank {
public:
	// ������������ �������, �
	double capacity = 0;

	// ������� �������������, �
	double volume = 0;

	// ���������� �����
	Tube *inTube = 0;

	// ��������� �����
	Tube *outTube = 0;

	// ����������� ������
	OpeningSensor *openingSensor = 0;

	// ����������� ������
	ClosingSensor *closingSensor = 0;

	// �����, ��������� � ������� �������
	double time = 0;
	
	// ������� ������� ��� update(), �
	double dt = 0.1;

	// ����������� �������
	Tank();

	// ���������� �������
	~Tank();
	
	// ���������� ������� ������ ������ ����, �� 0 �� 1
	double height();

	// ��������� ��������� �������
	void update();
};

