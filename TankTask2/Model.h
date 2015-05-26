#pragma once

// Труба, подводящая или отводящая воду
class Tube {
public:
	// Производительность трубы, л/с
	// Больше ноля, если вода поступает в емкость и меньше ноля, если вода отводится
	double perfomance = 0;

	// true, если заслонка открыта и труба работает
	bool active = false;

	// Конструктор объекта
	Tube(double perfomance, bool active);
};


// Датчик уровня, базовый класс
class Sensor {
public:
	// Высота распожения датчика
	// 0 - самый низ, 1 - самый верх
	double height = 0;

	// Ссылка на трубу, которой управляет датчик
	Tube *tube = 0;

	// Конструктор объекта
	Sensor(double height, Tube *tube);
	
	// Проверяет уровень воды
	virtual void check(double height) = 0;
};


// Датчик уровня, открывающий заслонку
class OpeningSensor : public Sensor {
public:
	// Конструктор объекта
	OpeningSensor(double height, Tube *tube);
	
	// Проверяет уровень воды
	virtual void check(double height);
};


// Датчик уровня, закрывающий заслонку
class ClosingSensor : public Sensor {
public:
	// Конструктор объекта
	ClosingSensor(double height, Tube *tube);

	// Проверяет уровень воды
	virtual void check(double height);
};


// Емкость с водой
class Tank {
public:
	// Максимальная емкость, л
	double capacity = 0;

	// Текущая заполненность, л
	double volume = 0;

	// Подводящая труба
	Tube *inTube = 0;

	// Отводящая труба
	Tube *outTube = 0;

	// Открывающий датчик
	OpeningSensor *openingSensor = 0;

	// Закрывающий датчик
	ClosingSensor *closingSensor = 0;

	// Время, прошедшее с момента запуска
	double time = 0;
	
	// Единица времени для update(), с
	double dt = 0.1;

	// Конструктор объекта
	Tank();

	// Деструктор объекта
	~Tank();
	
	// Возвращает текущую высоту уровня воды, от 0 до 1
	double height();

	// Обновляет состояние системы
	void update();
};

