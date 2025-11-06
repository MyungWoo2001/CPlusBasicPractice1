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
        std::cout << "3. Sensors list \n";
        std::cout << "4. Update Sensor value \n";
        std::cout << "5. Exit \n";
        std::cout << "Option:";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "--- Adding Sensor --- \n";
            system.addSensor(Sensor(Sensor::count + 1,0.0, "OK"));
            break;
        case 2:
            std::cout << "--- Removing Sensor --- \n";
            int sid;
            std::cout << "Enter SensorID:";
            std::cin >> sid;
            system.remove(sid);
            break;
        case 3:
            std::cout << "--- Sensor list --- \n";
            system.printAllInfo();
            break;
        case 4:
            std::cout << "--- Update Sensor --- \n";
            system.updateAll();
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
