#include "pch.h"
#include "DSensor.h"

DSensor::DSensor(int id, double val): Sensor(id, val, "Optical") {
	std::cout << "DSensor Constructor!\n";
}

// Update value by random
void DSensor::updateValue() {
	double ranvalue = rand() % 1000 / 10.0; // 0.0 -> 99.9
	*value = ranvalue;
	// update status following value
	if (ranvalue < 30) status = "Offline";
	else if (ranvalue < 60) status = "Warning";
	else status = "OK";
}

void DSensor::calibrate() {
	std::cout << "Calibrating DSensor #" << id << std::endl;
	*value = 0;
}

void DSensor::showInfo() {
	std::cout << "DSensor ID: " << id
		<< ", Value: " << *value
		<< ", Status: " << status << std::endl;
}