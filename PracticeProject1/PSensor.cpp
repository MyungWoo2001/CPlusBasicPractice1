#include "pch.h"
#include "PSensor.h"

PSensor::PSensor(int id, double val) : Sensor(id, val, "Presure") {};

// Update value by random
void PSensor::updateValue() {
	double ranvalue = rand() % 1000 / 10.0; // 0.0 -> 99.9
	*value = ranvalue;
	// update status following value
	if (ranvalue < 1) status = "Low";
	else if (ranvalue < 10) status = "Medium";
	else status = "Hight";
}

void PSensor::calibrate() {
	std::cout << "Calibrating Psensor #" << id << "\n";
	*value = 8.0;
}

void PSensor::showInfo() {
	std::cout << "PSensor ID: " << id
		<< ", Value: " << *value
		<< ", Status: " << status << std::endl;
}