#pragma once
class Device
{
public:
	virtual void updateValue() = 0;
	virtual void showInfo() = 0;
	virtual ~Device() {};
};

