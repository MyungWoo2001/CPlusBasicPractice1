// PracticeProject1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>


int main()
{

    //// Operator test
    //Sensor sensor1(1, 1.2, "Ok");
    //Sensor sensor2(2, 1.3, "Ok");
    //Sensor sensor3(3, 1.4, "Ok");
    //Sensor sensor4(4, 1.5, "Ok");
    //
    //SensorSystem1 system1;
    //system1.addSensor(sensor1);
    //system1.addSensor(sensor2);
    //system1.printAllInfo();

    //SensorSystem1 system2;
    //system2.addSensor(sensor3);
    //system2.addSensor(sensor4);
    //system2.printAllInfo();

    //SensorSystem1 system;
    //system = system1 + system2;
    //system.printAllInfo();


    srand((unsigned int)time(0)); // init seed for rand()

    SensorSystem system;
    Controller controller;

    int choice;
    bool running = true;

    while (running) {
        std::cout << "==== Sensor Menu ====" << std::endl;
        std::cout << "1. Add Sensor \n";
        std::cout << "2. Remove Sensor \n";
        std::cout << "3. Sensors list \n";
        std::cout << "4. Run Sensors \n";
        std::cout << "5. Calibraie Sensors\n";
        std::cout << "6. Exit \n";
        std::cout << "Option:";
        std::cin >> choice;

        switch (choice) {
        case 1:
        {
            std::cout << "--- Adding Sensor --- \n";
            std::cout << "Type of sensor: [1.DSensor] [2.TSensor] [3.PSensor]: ";
            int sensorType = 0;
            std::cin >> sensorType;
            switch (sensorType) {
            case 1:
            {
                Sensor* s = new DSensor(Sensor::count + 1, 0.0);
                system.addSensor(s);
                break;
            }
            case 2:
            {
                Sensor* s = new TSensor(Sensor::count + 1, 0.0);
                system.addSensor(s);
                break;
            }
            case 3:
            {
                Sensor* s = new PSensor(Sensor::count + 1, 0.0);
                system.addSensor(s);
                break;
            }
            default:
                std::cout << "Invalid type!!!";
                break;
            }
            break;
        }
        case 2:
            std::cout << "--- Removing Sensor --- \n";
            int sid;
            std::cout << "Enter SensorID:";
            std::cin >> sid;
            system.remove(sid);
            break;
        case 3:
            std::cout << "--- Sensors list --- \n";
            system.printAllInfo();
            break;
        case 4:
            std::cout << "--- Update Sensors --- \n";
            controller.run(system);
            break;
        case 5:
            std::cout << "--- Calibrating Sensors";
            controller.reset(system);
            break;
        case 6:
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
