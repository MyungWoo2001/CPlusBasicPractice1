#include "pch.h"
#include "SensorSystem.h"

// add new Sensor
void SensorSystem::addSensor(const Sensor& s) {
	sensors.push_back(s);
}
// Update all sensors
void SensorSystem::updateAll() {
	for (auto& s : sensors) {
		s.updateValue();
	}
}

// Print information of all sensors
void SensorSystem::printAll() const {
	std::cout << "==== Sensor Report ====\n";
	for (const auto& s : sensors) {
		s.printInfo();
	}
	std::cout << "========================\n";
}

// Sum of all sensors's value
double SensorSystem::totalValue() const {
	double sum = 0.0;
	for (const auto& s : sensors) {
		sum += s.getValue();
	}
	return sum;
}