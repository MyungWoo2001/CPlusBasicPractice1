#pragma once
#include<vector>
#include"Sensor.h"

class SensorSystem{
private:
	std::vector<Sensor> sensors;

public:

	//// Destructor
	//~SensorSystem();

	// add new Sensor
	void addSensor(const Sensor& s);

	// remove Sensor
	void remove(int id);

	// Update all sensors
	void updateAll();

	// Print information of all sensors
	void printAllInfo() const;

	// Sum of all sensors's value
	double totalValue() const;

	// Get count of sensors
	int getcount() const;

};