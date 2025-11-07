#pragma once
#include"pch.h"

class DSensor : public Sensor {
public:
	DSensor(int id, double val);

	void updateValue();

	void calibrate();
	void showInfo();
};

