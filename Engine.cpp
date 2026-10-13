//
// Created by Victus on 10/7/2026.
//

#include "Engine.h"

Engine::Engine(double Capacity, int HoursePower, int Clyinders, std::string Fuel_Type, std::string EngineType)
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

std::string Engine::Get_Fuel_Type()
{
    return Fuel_Type;
}

std::string Engine::Get_Engine_Type()
{
    return EngineType;
}

void Engine::ViewDetails()
{
    std::cout << "Capacity : " << Capacity << '\n';
    std::cout << "Hourse Power : " << HoursePower << '\n';
    std::cout << "Number Of Cylinders  : " << cylinders << '\n';
    std::cout << "Fuel Type : " << Fuel_Type << '\n';
    std::cout << "Engine Type : " << EngineType << '\n';
}
