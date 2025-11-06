#include "pch.h"
#include "Sensor.h"

int Sensor::count = 0;

// Constructor
Sensor::Sensor(int sensorID, double sensorValue, std::string sensorStatus): id(sensorID), value(nullptr), status(sensorStatus) {
	value = new double(sensorValue);
	std::cout << "Sensor Generated" << std::endl;
	count++;
}

// Copy Constructor
Sensor::Sensor(const Sensor& s): id(s.id), value(nullptr), status(s.status) {
	value = new double(*s.value);
	std::cout << "Sensor Copy\n";
}
// Copy assignment operator 
Sensor& Sensor::operator=(const Sensor& s) {
	if (this != &s) {
		id = s.id;
		status = s.status;

		// delete old memory
		delete value;
		value = new double(*s.value);
	}
	std::cout << "Copy Assignment called for Sensor" << id << std::endl;
	return *this;
}

// Destructor
Sensor::~Sensor() {
	delete value;
	std::cout << "Sensor " << id << " destroyed. \n" << std::endl;
}

// Getter
int Sensor::getID() const { return id; }
double Sensor::getValue() const { return *value; }
std::string Sensor::getStatus() const { return status; }

// Setter
void Sensor::setValue(double v) { *value = v; }
void Sensor::setStatus(const std::string& s) { status = s; }

// Update value by random
void Sensor::updateValue() {
	double ranvalue = rand() % 1000 / 10.0; // 0.0 -> 99.9
	*value = ranvalue;
	// update status following value
	if (ranvalue < 30) status = "Offline";
	else if (ranvalue < 60) status = "Warning";
	else status = "OK";
}

// Operator overload: plus sensor's values
Sensor Sensor::operator+(const Sensor& other) const {
	return Sensor(id, *value + *other.value, status);
}

void Sensor::printInfo() const {
	std::cout << "Sensor ID: " << id
		<< ", Value: " << *value
		<< ", Status: " << status << std::endl;
}