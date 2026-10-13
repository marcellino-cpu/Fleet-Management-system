//
// Created by Victus on 10/7/2026.
//

#include "Battery.h"

Battery::Battery(int Voltage, int Capacity, std::string Type) : Voltage(Voltage), Capacity(Capacity), Type(Type)
{
}


void Battery::SetCapcity(int Capacity)
{
    if (Capacity < 0)
    {
        std::cout << "INVALID VALUE ! " << '\n';
    } else
    {
        this->Capacity = Capacity;
    }
}

int Battery::GetVoltage()
{
    return Voltage;
}

int Battery::GetCapacity()
{
    return Capacity;
}

std::string Battery::GetType()
{
    return Type;
}

void Battery::ViewDetails()
{
    std::cout << "Battery information : " << '\n';
    std::cout << "Capacity : " << Capacity << " Ah" << '\n';
    std::cout << "Voltage : " << Voltage << " V " << '\n';
    std::cout << "Type : " << Type << '\n';
}
