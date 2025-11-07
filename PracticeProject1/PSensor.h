#pragma once
#include"pch.h"

class PSensor : public Sensor
{
public:
	PSensor(int id, double val);

	void updateValue();
	void calibrate();
	void showInfo();
};

