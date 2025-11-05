#pragma once
#include<string>
#include<iostream>

class Sensor
{
private:
	int id;
	double value;
	std::string status;

public:

	static int count;

	//Constructor
	Sensor(double sensorValue, std::string sensorStatus);

	// Destructor
	~Sensor();

	// Getter
	int getID() const;
	double getValue() const;
	std::string getStatus() const;

	// Setter
	void setValue(double v);
	void setStatus(const std::string& stt);

	void updateValue();

	//Operator overload: plus sensor values
	Sensor operator+(const Sensor& other) const;

	// Print sensor information
	void printInfo() const;

};

