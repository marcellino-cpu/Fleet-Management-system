//
// Created by Victus on 10/7/2026.
//

#include "Car.h"


Car::Car(string Brand, string Model, int year, long long Mileage, double price, string Transimission,
         int MaxSpeed, int NumberOfSeats, int NumberOfDoors, int TrunkCapacity, string BodyType) : Vehicle(
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

string Car::GetBodyType()
{
    return BodyType;
}

void Car::ViewDetails()

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
    cout << "-----------------EXTRA INFO---------------" << '\n';
    cout << "Extra Details : " << '\n';
    cout << "Number OF Seats : " << NumberOfSeats << '\n';
    cout << "Number OF Doors : " << NumberOfDoors << '\n';
    cout << "Trunk Capacity : " << TrunkCapacity << '\n';
    cout << "Body Type : " << BodyType << '\n';

}

