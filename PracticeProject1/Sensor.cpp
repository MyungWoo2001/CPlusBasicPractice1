#include "pch.h"
#include "Sensor.h"

int Sensor::count = 0;

// Constructor
Sensor::Sensor(double sensorValue, std::string sensorStatus): id(count+1), value(sensorValue), status(sensorStatus) {
	count++;
	std::cout << "Sensor Generated" << std::endl;
}
// Destructor
Sensor::~Sensor() {
	count--;
	std::cout << "Sensor " << id << " destroyed. \n" << std::endl;
}

// Getter
int Sensor::getID() const { return id; }
double Sensor::getValue() const { return value; }
std::string Sensor::getStatus() const { return status; }

// Setter
void Sensor::setValue(double v) { value = v; }
void Sensor::setStatus(const std::string& s) { status = s; }

// Update value by random
void Sensor::updateValue() {
	value = rand() % 1000 / 10.0; // 0.0 -> 99.9
	// update status following value
	if (value < 30) status = "Offline";
	else if (value < 60) status = "Warning";
	else status = "OK";
}

// Operator overload: plus sensor's values
Sensor Sensor::operator+(const Sensor& other) const {
	return Sensor(value + other.value, status);
}

void Sensor::printInfo() const {
	std::cout << "Sensor ID: " << id
		<< ", Value: " << value
		<< ", Status: " << status << std::endl;
}