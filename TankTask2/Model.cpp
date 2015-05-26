#include "Model.h"

/* ----------------------------------------------------
	class Tube
	Труба, подводящая или отводящая воду
*/

// Конструктор объекта
Tube::Tube(double perfomance, bool active)
{
	this->perfomance = perfomance;
	this->active = active;
}

/* ----------------------------------------------------
	class Sensor
	Датчик уровня, базовый класс
*/

// Конструктор объекта
Sensor::Sensor(double height, Tube *tube)
{
	this->height = height;
	this->tube = tube;
}

/* ----------------------------------------------------
	class OpeningSensor
	Датчик уровня, открывающий заслонку
*/

// Конструктор объекта
OpeningSensor::OpeningSensor(double height, Tube *tube) : 
Sensor(height, tube) {}

// Проверяет уровень воды
void OpeningSensor::check(double height)
{
	// Если уровень воды выше расположения датчика
	if (height >= this->height) {
		// Открыть заслонку трубы
		tube->active = true;
	}
}

/* ----------------------------------------------------
	class ClosingSensor
	Датчик уровня, закрывающий заслонку
*/

// Конструктор объекта
ClosingSensor::ClosingSensor(double height, Tube *tube) :
Sensor(height, tube) {}

// Проверяет уровень воды
void ClosingSensor::check(double height)
{
	// Если уровень воды ниже расположения датчика
	if (height < this->height) {
		// Закрыть заслонку трубы
		tube->active = false;
	}
}

/* ----------------------------------------------------
	class Tank
	Емкость с водой
*/

// Конструктор объекта
Tank::Tank()
{
	capacity = 50;
	volume = 0;

	// Подводящая труба
	inTube = new Tube( 2.5, true);

	// Отводящая труба
	outTube = new Tube( -5, false);

	// Открывающий датчик
	openingSensor = new OpeningSensor(0.9, outTube);

	// Закрывающий датчик
	closingSensor = new ClosingSensor(0.6, outTube);
}

// Деструктор объекта
Tank::~Tank()
{
	delete openingSensor;
	delete closingSensor;
	delete inTube;
	delete outTube;
}

// Возвращает текущую высоту уровня воды, от 0 до 1
double Tank::height()
{
	return (volume / capacity);
}

// Обновляет состояние системы
void Tank::update()
{
	// Трубы наполняет или опустошают емкость, если открыты
	if (inTube->active)
		volume += inTube->perfomance * dt;

	if (outTube->active)
		volume += outTube->perfomance * dt;

	// Проверка переполнения емкости
	if (volume < 0)
		volume = 0;

	if (volume > capacity)
		volume = capacity;

	// Проверить сенсоры
	openingSensor->check(height());
	closingSensor->check(height());

	time += dt;
}
