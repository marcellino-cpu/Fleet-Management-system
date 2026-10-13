#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include "Car.h"
#include "Motorcycle.h"


class Fleet_Management_System
{
private :
   std:: vector<Car *> cars;
   std:: vector<Motorcycle *> motorcycles;

public :
    void Display_Menu();

    void Adding_Vehicle(int choice);

    void Adding_Car(std::string brand, std::string model, int year, int Mileage, double Price, std::string Transimision, int MaxSpeed);

    void Adding_Motorcycle(std::string brand, std::string model, int year, int Mileage, double Price, std::string Transimision,
                           int MaxSpeed);

    void Display_Fleet();

    void Brands_that_exist_in_your_fleet();

    void Display_count_per_brand();


    void Search_By_Brand(int choice ,std::string brand);

    void Search_By_Model(int choice ,std::string Model);

    void Search_By_Year(int choice, int year);



    void sort_Old_to_new();

    void sort_new_to_Old();

    void Removing_Vehicle(int choice, int id);
};
