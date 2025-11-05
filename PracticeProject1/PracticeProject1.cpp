// PracticeProject1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
#include "Sensor.h"
#include "SensorSystem.h"

int main()
{
    srand((unsigned int)time(0)); // init seed for rand()

    SensorSystem system;

    // Add 5 sensors to system
    for (int i = 1; i < 6; i++) {
        Sensor s(0.0, "OK");
        system.addSensor(s);
    }

    // Update sensors several times
    for (int t = 1; t <= 5; t++) {
        std::cout << "Update #" << t << ":\n";
        system.updateAll();
        system.printAll();
        std::cout << "Total Sensor value: " << system.totalValue() << std::endl;
    }
        

    // declare 2 Sensor
    Sensor sensor1(12.5, "OK");
    Sensor sensor2(7.3, "OK");

    // Print information
    sensor1.printInfo();
    sensor2.printInfo();

    // Update sensor1's info
    sensor1.setValue(13.1);
    sensor1.printInfo();

    // Using operator+ to calculate sensor's value
    Sensor sensorSum = sensor1 + sensor2;
    std::cout << "After adding sensor1 and sensor2 value: \n";
    sensorSum.printInfo();

}
