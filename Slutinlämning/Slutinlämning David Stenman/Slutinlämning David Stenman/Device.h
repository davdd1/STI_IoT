#pragma once
#include <string>
#include <iostream>
#include <vector>

using std::string; using std::endl; using std::cout; using std::cin; using std::vector;

class Device
{
private:
	const string name;
	Device* leftDevice = nullptr;
	Device* rightDevice = nullptr;
	Device* parentDevice = nullptr;
public:
	Device(string& name);
	~Device() { cout << "Device deleted!" << endl; }
	string getName() { return name; }
	Device* getLeftDevice() { return leftDevice; }
	Device* getRightDevice() { return rightDevice; }
	Device* getParentDevice() { return parentDevice; }
	void disconnectDevice(Device* device); //koppla bort en enhet om den finns och �r ansluten
	void setLeftDevice(Device* device) { leftDevice = device; }
	void setRightDevice(Device* device) { rightDevice = device; }
	void setParentDevice(Device* device) { parentDevice = device; }
	void dcLeftDevice() { leftDevice = nullptr; }
	void dcRightDevice() { rightDevice = nullptr; }
	void dcParentDevice() { parentDevice = nullptr; }
	void printDevice(int level); //Printar enheten och dess anslutna enhet om den finns
	virtual void ping() = 0;		//Pingar en enhet och spelar upp en beep om enheten �r ansluten
};

class NetworkDevice : public Device
{
public:
	NetworkDevice(string name);
	~NetworkDevice() { cout << "NetworkDevice deleted!" << endl; }
	void ping();
};

class AudioDevice : public Device
{
public:
	AudioDevice(string name);
	~AudioDevice() { cout << "AudioDevice deleted!" << endl; }
	void ping();
};