//
// Created by Victus on 10/7/2026.
//

#include "Vehicle.h"

Vehicle::Vehicle(std::string Brand, std::string Model, int Year, long long Mileage, double Price,
                std:: string Transimission, int MaxSpeed)
{
    this->Brand = Brand;
    this->Model = Model;
    this->Year = Year;
    this->Mileage = Mileage;
    this->Price = Price;
    this->Transimission = Transimission;
    this->MaxSpeed = MaxSpeed;
    id = Id_Generator++;
}

void Vehicle::SetTransimission(std::string Transimission)
{
    bool isAlpha = true;
    for (int i = 0; i < Transimission.size(); i++)
    {
        if (!isalpha(Transimission[i]))
        {
            isAlpha = false;
        }
    }
    if (!isAlpha)
    {
        std::cout << "Invalid input ! Please Enter an input without Digits " << '\n';
    } else
    {
        this->Transimission = Transimission;
    }
}

std::string Vehicle::GetBrand()
{
    return Brand;
}

std::string Vehicle::GetModel()
{
    return Model;
}

int Vehicle::GetID()
{
    return id;
}

int Vehicle::GetYear() const
{
    return Year;
}

long long Vehicle::GetMileage()
{
    return Mileage;
}

double Vehicle::GetPrice()
{
    return Price;
}

int Vehicle::GetMaxSpeed()
{
    return MaxSpeed;
}


std::string Vehicle::GetTransimission()
{
    return Transimission;
}

int Vehicle::Id_Generator = 1000;
