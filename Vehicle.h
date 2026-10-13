#pragma once
#include "Engine.h"
#include "Battery.h"
#include <string>
#include <iostream>




//(Parent - Base - Super) class
class Vehicle
{
private :
    std::string Brand;
    std::string Model;
    int Year;
    long long Mileage;
    double Price;
    std::string Transimission;
    int MaxSpeed;
    static int Id_Generator;
    int id;

public :
    Vehicle(std::string Brand, std::string Model, int Year, long long Mileage, double Price, std::string Transimission, int MaxSpeed);  //Constructor


    //setters and getters for private members "Attributes"(Encapsulation)
    void SetPrice(double Price);

    void SetTransimission(std::string Transimission);

    std::string GetBrand();

    std::string GetModel();

    int GetID();

    int GetYear() const;

    long long GetMileage();

    double GetPrice();

    std::string GetTransimission();

    int GetMaxSpeed();

    virtual void ViewDetails() = 0;
// virtual pure function that made the class abstracted and must be overriden in the child classes
    // virtual Keyword in parent class allows the program to call the overriden function according to the actual type ;
};
