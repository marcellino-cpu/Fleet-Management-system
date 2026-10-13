//
// Created by Victus on 10/7/2026.
//

#include "Motorcycle.h"

Motorcycle::Motorcycle(string Brand, string Model, int Year, long long Mileage, double Price, string Transimission,
                       int MaxSpeed, string Type, bool hasABS, int seatHeight) : Vehicle(Brand, Model, Year, Mileage,
        Price, Transimission, MaxSpeed), Type(Type), hasABS(hasABS), seatHeight(seatHeight)
{
}

string Motorcycle::GetType()
{
    return Type;
}

bool Motorcycle::GetHasAbs()
{
    return hasABS;
}

int Motorcycle::GetseatHieght()
{
    return seatHeight;
}

void Motorcycle::ViewDetails()
{
    //Overriding ViewDetails method from the parent class vehicle (Polymorphism)

    cout << "ID : " << GetID() << '\n';
    cout << "Brand : " << GetBrand() << '\n';
    cout << "Model : " << GetModel() << '\n';
    cout << "Year : " << GetYear() << '\n';
    cout << "Mileage : " << GetMileage() << '\n';
    cout << "Price : " << GetPrice() << '\n';
    cout << "Transimission : " << GetTransimission() << '\n';

    cout << "Max Speed : " << GetMaxSpeed() << '\n';
    cout << "----------------EXTRA INFO----------------" << '\n';
    cout << "Extra Details : " << '\n';
    cout << "Type : " << Type << '\n';
    cout << "Height between seat and Ground : " << seatHeight << " M " << '\n';
    cout << "Anti-loch Braking System : " << hasABS << '\n';
}

