#include "pch.h"

void Controller::run(SensorSystem& ss) {
	std::cout << "\n[Controller] Running all sensors...\n";
	ss.updateAll();
	ss.printAllInfo();
}

void Controller::reset(SensorSystem& ss) {
	std::cout << "\n[Controller] Calibrating all sensor...\n";
	ss.calibrateAll();
	ss.printAllInfo();
}


