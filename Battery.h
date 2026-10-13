#pragma once
#include <iostream>
#include <string>
using namespace std;

class Battery
{
private :
    int Voltage;
    int Capacity;
    string Type;

public :
    Battery(int Voltage, int Capacity, string Type);
    void SetCapcity(int Capacity);
    int GetVoltage();
    int GetCapacity();
    string GetType();

    void ViewDetails();
};
