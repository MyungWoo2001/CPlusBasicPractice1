#include "pch.h"
#include "SensorSystem.h"

// Destructor
SensorSystem::~SensorSystem() {
	for (Sensor* s : sensors) {
		delete s;
	}

	std::cout << "[System] All sensors destroyed!\n";
}

SensorSystem::SensorSystem() {}

// copy constructor
SensorSystem::SensorSystem(const SensorSystem& ss) {
	sensors = ss.sensors;
	std::cout << "Copy sensors \n";
}
//// operator =
//SensorSystem& SensorSystem::operator=(const SensorSystem1& ss) {
//	if (this != &ss) {
//		for (auto it = sensors.begin(); it != sensors.end(); it++) {
//			delete* it;
//		}
//		sensors.clear();
//		for (auto it = ss.sensors.begin(); it != ss.sensors.end(); it++) {
//			sensors.push_back(new Sensor(*(*it)));
//		}
//	}
//
//	return *this;
//}

//// operator +
//SensorSystem SensorSystem::operator+(const SensorSystem1& ss) {
//	SensorSystem1 result;
//	// insert this.sensors to result.sensors
//	for (auto it = this->sensors.begin(); it != this->sensors.end(); it++) {
//		result.sensors.push_back(new Sensor(*(*it)));
//	}
//	// insert ss.sensors to result.sensors
//	for (auto it = ss.sensors.begin(); it != ss.sensors.end(); it++) {
//		result.sensors.push_back(new Sensor(*(*it)));
//	}
//
//	return result;
//}



// add new Sensor
void SensorSystem::addSensor(Sensor* s) {
	sensors.push_back(s);
}

// Remove one sensor
void SensorSystem::remove(int id) {
	for (auto it = sensors.begin(); it != sensors.end(); ++it) {
		if ((*it)->getID() == id) {
			delete* it;
			sensors.erase(it);
			return;
		}
	}
	std::cout << "Sensor with id: " << id << "not found! \n";
}

// Update all sensors
void SensorSystem::updateAll() {
	for (Sensor* s : sensors) {
		s->updateValue();
	}
}

// Calibrate all sensors
void SensorSystem::calibrateAll() {
	for (Sensor* s : sensors) {
		s->calibrate();
	}
}


// Print information of all sensors
void SensorSystem::printAllInfo() const {
	std::cout << "==== Sensor Report ====\n";
	for (Sensor* s : sensors) {
		s->showInfo();
	}
	std::cout << "========================\n";
}

// Sum of all sensors's value
double SensorSystem::totalValue() const {
	double sum = 0.0;
	for (auto it = sensors.begin(); it != sensors.end(); ++it) {
		sum += (*it)->getValue();
	}
	return sum;
}

// Get count of sensors
int SensorSystem::getcount() const {
	int cnt = sensors.size();
	return cnt;
}