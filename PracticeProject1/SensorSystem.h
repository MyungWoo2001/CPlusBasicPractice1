#pragma once
#include<vector>
#include"Sensor.h"

class SensorSystem{
private:
	std::vector<Sensor> sensors;

public:
	// add new Sensor
	void addSensor(const Sensor& s) {
		sensors.push_back(s);
	}

	// Update all sensors
	void updateAll() {
		for (auto& s: sensors) {
			s.updateValue();
		}
	}

	// Print information of all sensors
	void printAll() const {
		std::cout << "==== Sensor Report ====\n";
		for (const auto& s : sensors) {
			s.printInfo();
		}
		std::cout << "========================\n";
	}

	// Sum of all sensors's value
	double totalValue() const {
		double sum = 0.0;
		for (const auto& s : sensors) {
			sum += s.getValue();
		}
		return sum;
	}



};

