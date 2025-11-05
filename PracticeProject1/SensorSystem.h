#pragma once
#include<vector>
#include"Sensor.h"

class SensorSystem{
private:
	std::vector<Sensor> sensors;

public:
	// add new Sensor
	void addSensor(const Sensor& s);

	// Update all sensors
	void updateAll();

	// Print information of all sensors
	void printAll() const;

	// Sum of all sensors's value
	double totalValue() const;



};

