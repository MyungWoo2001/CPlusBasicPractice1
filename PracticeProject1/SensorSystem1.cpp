#include "pch.h"
#include "SensorSystem1.h"

SensorSystem1::SensorSystem1() {}

// copy constructor
SensorSystem1::SensorSystem1(const SensorSystem1& ss) {
	sensors = ss.sensors;
	std::cout << "Copy sensors \n";
}
// operator =
SensorSystem1& SensorSystem1::operator=(const SensorSystem1& ss) {
	if (this != &ss) {
		for (auto it = sensors.begin(); it != sensors.end(); it++) {
			delete* it;
		}
		sensors.clear();
		for (auto it = ss.sensors.begin(); it != ss.sensors.end(); it++) {
			sensors.push_back(new Sensor(*(*it)));
		}
	}

	return *this;
}

// operator +
SensorSystem1 SensorSystem1::operator+(const SensorSystem1& ss) {
	SensorSystem1 result;
	// insert this.sensors to result.sensors
	for (auto it = this->sensors.begin(); it != this->sensors.end(); it++) {
		result.sensors.push_back(new Sensor(*(*it)));
	}
	// insert ss.sensors to result.sensors
	for (auto it = ss.sensors.begin(); it != ss.sensors.end(); it++) {
		result.sensors.push_back(new Sensor(*(*it)));
	}

	return result;
}

// Destructor
SensorSystem1::~SensorSystem1() {
	for (Sensor* s : sensors) {
		delete s;
	}

	std::cout << "[System] All sensors destroyed!\n";
}

// add new Sensor
void SensorSystem1::addSensor(const Sensor& s) {
	Sensor* sensor = new Sensor(s);
	try {
		sensors.push_back(sensor);
	}
	catch (...) {
		delete sensor;
		throw;
	}
	sensor->printInfo();
}
// Update all sensors
void SensorSystem1::updateAll() {
	for (auto it = sensors.begin(); it != sensors.end(); ++it) {
		(*it)->updateValue();
	}
}

// Remove one sensor
void SensorSystem1::remove(int id) {
	for (auto it = sensors.begin(); it != sensors.end(); ++it) {
		if ((*it)->getID() == id) {
			delete* it;
			sensors.erase(it);
			return;
		}
	}
	std::cout << "Sensor with id: " << id << "not found! \n";
}

// Print information of all sensors
void SensorSystem1::printAllInfo() const {
	std::cout << "==== Sensor Report ====\n";
	for (auto it = sensors.begin(); it != sensors.end(); ++it) {
		(*it)->printInfo();
	}
	std::cout << "========================\n";
}

// Sum of all sensors's value
double SensorSystem1::totalValue() const {
	double sum = 0.0;
	for (auto it = sensors.begin(); it != sensors.end(); ++it) {
		sum += (*it)->getValue();
	}
	return sum;
}

// Get count of sensors
int SensorSystem1::getcount() const {
	int cnt = sensors.size();
	return cnt;
}