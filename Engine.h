#pragma once
#include <iostream>
#include <string>
using namespace std ;

class Engine
{
private :
    double Capacity;
    int HoursePower;
    int cylinders;
    string Fuel_Type;
    string EngineType;


public :
    Engine(double Capacity, int HoursePower, int Clyinders, string Fuel_Type, string EngineType);

    double GetCapacity();
    int GetPowerHourse();
    int GetCylinders();
    string Get_Fuel_Type();
    string Get_Engine_Type();

    void ViewDetails();

};
