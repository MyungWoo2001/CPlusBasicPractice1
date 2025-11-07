#pragma once
#include<vector>
#include"Sensor.h"

class SensorSystem {
private:
	std::vector<Sensor*> sensors;

public:

	// Destructor
	~SensorSystem();

	SensorSystem();

	// copy constructor
	SensorSystem(const SensorSystem&);
	// operator =
	SensorSystem& operator=(const SensorSystem&);

	// operator +
	SensorSystem operator+(const SensorSystem&);

	// add new Sensor
	void addSensor(Sensor* s);

	// remove Sensor
	void remove(int id);

	// Update all sensors
	void updateAll();

	// Calibrate all sensors
	void calibrateAll();

	// Print information of all sensors
	void printAllInfo() const;

	// Sum of all sensors's value
	double totalValue() const;

	// Get count of sensors
	int getcount() const;

	

};