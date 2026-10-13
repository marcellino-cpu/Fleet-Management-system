//
// Created by Victus on 10/7/2026.
//

#include "Car.h"


Car::Car(std::string Brand, std::string Model, int year, long long Mileage, double price, std::string Transimission,
         int MaxSpeed, int NumberOfSeats, int NumberOfDoors, int TrunkCapacity, std::string BodyType) : Vehicle(
        Brand, Model, year, Mileage, price, Transimission, MaxSpeed), NumberOfSeats(NumberOfSeats),
    NumberOfDoors(NumberOfDoors), TrunkCapacity(TrunkCapacity), BodyType(BodyType)
{
}

int Car::GetNumberOfSeats()
{
    return NumberOfSeats;
}

int Car::GetNumberOfDoors()
{
    return NumberOfDoors;
}

int Car::GetTrunkCapacity()
{
    return TrunkCapacity;
}

std::string Car::GetBodyType()
{
    return BodyType;
}

void Car::ViewDetails()

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
    std::cout << "-----------------EXTRA INFO---------------" << '\n';
    std::cout << "Extra Details : " << '\n';
    std::cout << "Number OF Seats : " << NumberOfSeats << '\n';
    std::cout << "Number OF Doors : " << NumberOfDoors << '\n';
    std::cout << "Trunk Capacity : " << TrunkCapacity << '\n';
    std::cout << "Body Type : " << BodyType << '\n';
}
