//
// Created by Victus on 10/7/2026.
//

#include "Engine.h"

Engine::Engine(double Capacity, int HoursePower, int Clyinders, string Fuel_Type, string EngineType)
{
    this->Capacity = Capacity;
    this->HoursePower = HoursePower;
    this->cylinders = Clyinders;
    this->Fuel_Type = Fuel_Type;
    this->EngineType = EngineType;
}

double Engine::GetCapacity()
{
    return Capacity;
}

int Engine::GetPowerHourse()
{
    return HoursePower;
}

int Engine::GetCylinders()
{
    return cylinders;
}

string Engine::Get_Fuel_Type()
{
    return Fuel_Type;
}

string Engine::Get_Engine_Type()
{
    return EngineType;
}

void Engine::ViewDetails()
{
    cout << "Capacity : " << Capacity << '\n';
    cout << "Hourse Power : " << HoursePower << '\n';
    cout << "Number Of Cylinders  : " << cylinders    << '\n';
    cout << "Fuel Type : " << Fuel_Type << '\n';
    cout << "Engine Type : " << EngineType << '\n';
}
