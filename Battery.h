#pragma once
#include <iostream>
#include <string>


class Battery
{
private :
    int Voltage;
    int Capacity;
   std:: string Type;

public :
    Battery(int Voltage, int Capacity,std:: string Type);
    void SetCapcity(int Capacity);
    int GetVoltage();
    int GetCapacity();
    std::string GetType();

    void ViewDetails();
};
