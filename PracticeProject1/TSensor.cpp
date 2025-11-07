#include "pch.h"
#include "TSensor.h"

TSensor::TSensor(int id, double val) : Sensor(id, val, "Thermal") {
	std::cout << "TSensor Generated! \n";
}

// Update value by random
void TSensor::updateValue() {
	double ranvalue = rand() % 3000 / 100.0 + 10.0; // 10.0 -> 39.9
	*value = ranvalue;
	// update status following value
	if (ranvalue > 30) status = "Warning - Too hot";
	else if (ranvalue < 20) status = "Warning - Too cold";
	else status = "OK";
}

void TSensor::calibrate() {
	std::cout << "Calibrating TSensor #" << id << "\n";
	*value = 25;
}

void TSensor::showInfo() {
	std::cout << "TSensor ID: " << id
		<< ", Value: " << *value
		<< ", Status: " << status << std::endl;
}
