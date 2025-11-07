#pragma once
#include"pch.h"

class TSensor : public Sensor 
{
public:
	TSensor(int id, double val);

	void updateValue();

	void calibrate();
	void showInfo();

};

