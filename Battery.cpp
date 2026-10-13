//
// Created by Victus on 10/7/2026.
//

#include "Battery.h"

Battery::Battery(int Voltage, int Capacity, string Type) : Voltage(Voltage), Capacity(Capacity), Type(Type)
{
}


void Battery::SetCapcity(int Capacity)
{
    if (Capacity < 0)
    {
        cout << "INVALID VALUE ! " << '\n';
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

string Battery::GetType()
{
    return Type;
}

void Battery::ViewDetails()
{
    cout << "Battery information : " << '\n';
    cout << "Capacity : " << Capacity <<" Ah" <<  '\n';
    cout << "Voltage : " << Voltage << " V " << '\n';
    cout << "Type : " << Type << '\n';
}


