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

    int choice;
    bool running = true;

    while (running) {
        std::cout << "==== Sensor Menu ====" << std::endl;
        std::cout << "1. Add Sensor \n";
        std::cout << "2. Remove Sensor \n";
        std::cout << "3. Update Sensor value \n";
        std::cout << "4. Print Report \n";
        std::cout << "5. Exit \n";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "--- Adding Sensor --- \n";
            system.addSensor(Sensor(0.0, "OK"));
            system.printAll();
            break;
        case 2:
            std::cout << "--- Removing Sensor --- \n";
            break;
        case 3:
            std::cout << "--- Update Sensor --- \n";
            break;
        case 4:
            std::cout << "--- Print Report --- \n";
            break;
        case 5:
            std::cout << "--- Exit Program. \n";
            running = false;
            break;
        default:
            std::cout << "!!! Invalid choice !!!\n";

        }

    }

    //// Add 5 sensors to system
    //for (int i = 1; i < 6; i++) {
    //    Sensor s(0.0, "OK");
    //    system.addSensor(s);
    //}

    //// Update sensors several times
    //for (int t = 1; t <= 5; t++) {
    //    std::cout << "Update #" << t << ":\n";
    //    system.updateAll();
    //    system.printAll();
    //    std::cout << "Total Sensor value: " << system.totalValue() << std::endl;
    //}
    //    

    //// declare 2 Sensor
    //Sensor sensor1(12.5, "OK");
    //Sensor sensor2(7.3, "OK");

    //// Print information
    //sensor1.printInfo();
    //sensor2.printInfo();

    //// Update sensor1's info
    //sensor1.setValue(13.1);
    //sensor1.printInfo();

    //// Using operator+ to calculate sensor's value
    //Sensor sensorSum = sensor1 + sensor2;
    //std::cout << "After adding sensor1 and sensor2 value: \n";
    //sensorSum.printInfo();

}
