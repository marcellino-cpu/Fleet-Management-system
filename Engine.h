#pragma once
#include <iostream>
#include <string>

class Engine
{
private :
    double Capacity;
    int HoursePower;
    int cylinders;
    std::string Fuel_Type;
    std::string EngineType;

public :
    Engine(double Capacity, int HoursePower, int Clyinders, std::string Fuel_Type, std::string EngineType);

    double GetCapacity();

    int GetPowerHourse();

    int GetCylinders();

    std::string Get_Fuel_Type();

    std::string Get_Engine_Type();

    void ViewDetails();
};
