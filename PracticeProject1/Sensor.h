#pragma once
#include<string>
#include<iostream>

class Sensor : public Device {
protected:
	int id;
	double *value;
	std::string status;

public:

	static int count;

	//Constructor
	Sensor(int sensorID, double sensorValue, std::string sensorStatus);

	// move constructor
	Sensor(Sensor&& s) noexcept;

	/*Sensor& operator=(Sensor&& s) noexcept;*/

	// Copy Constructor
	Sensor(const Sensor& s);
	// Copy Assignment
	Sensor& operator=(const Sensor& s);

	// Destructor
	~Sensor();

	// Getter
	int getID() const;
	double getValue() const;
	std::string getStatus() const;

	// Setter
	void setValue(double v);
	void setStatus(const std::string& stt);

	//Operator overload: plus sensor values
	//Sensor operator+(const Sensor& other) const;

	// Virtual
	virtual void calibrate() = 0;

};

