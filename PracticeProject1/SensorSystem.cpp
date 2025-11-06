#include "pch.h"
#include "SensorSystem.h"


SensorSystem::SensorSystem() {}

// Conversion Constructor
SensorSystem::SensorSystem(const std::vector<Sensor>& ss) : sensors(ss) {}

// Move Constructor
SensorSystem::SensorSystem(SensorSystem&& ss) noexcept {
	std::cout << "move coverstructor \n";
	sensors = std::move(ss.sensors);
}

// copy construtor
SensorSystem::SensorSystem(const SensorSystem& ss) {
	std::cout << "copy constructor\n";
	sensors = ss.sensors;
}

// copy assignment =
SensorSystem& SensorSystem::operator=(const SensorSystem& ss) {
	std::cout << "copy assignment \n";
	if (this != &ss) {
		sensors.clear();
		sensors.insert(sensors.end(), ss.sensors.begin(), ss.sensors.end());
	}

	return *this;
}

// operator +
SensorSystem SensorSystem::operator+(const SensorSystem& ss) {
	SensorSystem result;
	result.sensors = sensors;
	result.sensors.insert(result.sensors.end(), ss.sensors.begin(), ss.sensors.end());

	return result;
}


// add new Sensor
void SensorSystem::addSensor(const Sensor& s) {
	sensors.push_back(s);
	s.printInfo();
}
// Update all sensors
void SensorSystem::updateAll() {
	for (auto& s : sensors) {
		s.updateValue();
	}
}

// Remove one sensor
void SensorSystem::remove(int id) {
	for (int i = 0; i < sensors.size(); i++) {
		if (sensors[i].getID() == id) {
			sensors.erase(sensors.begin() + i);
			return;
		}
	}
}

// Print information of all sensors
void SensorSystem::printAllInfo() const {
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

// Get count of sensors
int SensorSystem::getcount() const {
	int cnt = sensors.size();
	return cnt;
}