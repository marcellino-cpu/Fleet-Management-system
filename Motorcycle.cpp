//
// Created by Victus on 10/7/2026.
//

#include "Motorcycle.h"

Motorcycle::Motorcycle(std::string Brand, std::string Model, int Year, long long Mileage, double Price,std:: string Transimission,
                       int MaxSpeed,std:: string Type, bool hasABS, int seatHeight) : Vehicle(Brand, Model, Year, Mileage,
        Price, Transimission, MaxSpeed), Type(Type), hasABS(hasABS), seatHeight(seatHeight)
{
}

std::string Motorcycle::GetType()
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

    std::cout << "ID : " << GetID() << '\n';
    std::cout << "Brand : " << GetBrand() << '\n';
    std::cout << "Model : " << GetModel() << '\n';
    std::cout << "Year : " << GetYear() << '\n';
    std::cout << "Mileage : " << GetMileage() << '\n';
    std::cout << "Price : " << GetPrice() << '\n';
    std::cout << "Transimission : " << GetTransimission() << '\n';

    std::cout << "Max Speed : " << GetMaxSpeed() << '\n';
    std::cout << "----------------EXTRA INFO----------------" << '\n';
    std::cout << "Extra Details : " << '\n';
    std::cout << "Type : " << Type << '\n';
    std::cout << "Height between seat and Ground : " << seatHeight << " M " << '\n';
    std::cout << "Anti-loch Braking System : " << hasABS << '\n';
}

