#pragma once
#include "Model.h"

using namespace System::Drawing;

// Графическое представление модели
ref class TankView
{
public:
	// Ссылка на экземпляр модель
	Tank *tank = 0;
	
	// Ширина в пикселях
	int width = 0;

	// Высота в пикселях
	int height = 0;

	// Этой кистью рисуем воду
	Brush ^waterB = nullptr;

	// Этой кистью рисуем заслонку
	Brush ^gateB = nullptr;

	// Этим пером обводим границы
	Pen ^borderP = nullptr;

	// Этим пером рисуем датчики
	Pen ^sensorP = nullptr;

	// Конструктор объекта
	TankView( int width, int height);

	// Деструктор объекта
	~TankView();

	// Отрисовать представление
	void draw( Graphics ^g);
};

