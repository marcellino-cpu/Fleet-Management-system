#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <queue>
#include <functional>
#include "Fleet_Management_System.h"


void Fleet_Management_System::Adding_Car(std::string brand, std::string model, int year, int Mileage, double Price,
                                         std::string Transimision, int MaxSpeed
)
{
    std::cout << "Enter Number of Seats : " << '\n';
    int NumberOFseats;
    std::cin >> NumberOFseats;
    std::cout << "Enter Number of Doors : " << '\n';
    int NumberOFDoors;
    std::cin >> NumberOFDoors;
    std::cout << "Enter Trunk Capacity : " << '\n';
    int TrunkCapacity;
    std::cin >> TrunkCapacity;
    std::cout << "Enter Car's Type : " << '\n';
    std::string type;
    std::cin >> type;
    Car *car = new Car(brand, model, year, Mileage, Price, Transimision, MaxSpeed, NumberOFseats, NumberOFDoors,
                       TrunkCapacity, type);

    cars.push_back(car); // adding created car to the vector of cars

    std::cout << "Enter Engine info : " << '\n';
    std::cout << "Enter Capacity : " << '\n';
    double capacity;
    std::cin >> capacity;
    std::cout << "Enter Hourse Power : " << '\n';

    int HoursePower;
    std::cin >> HoursePower;
    std::cout << "Enter Clyinders  : " << '\n';

    int Clyinders;
    std::cin >> Clyinders;
    std::cout << "Enter Fuel_Type : " << '\n';

    std::string Fuel_Type;
    std::cin >> Fuel_Type;
    std::cout << "Enter Engine Type  : " << '\n';

    std::string EngineType;
    std::cin >> EngineType;
    Engine *engine = new Engine(capacity, HoursePower, Clyinders, Fuel_Type, EngineType);
    std::cout << "Enter Battery's voltage : " << '\n';
    int Voltage;
    std::cin >> Voltage;
    std::cout << "Enter Battery's Capacity : " << '\n';
    int Capacity;
    std::cin >> Capacity;
    std::cout << "Enter Battery's Type : " << '\n';
    std::string BatteryType;
    std::cin >> BatteryType;
    Battery *battery = new Battery(Voltage, Capacity, BatteryType);
    //composition (Strong Relation)
    car->engine = engine;
    // The pointer (engine) from the type Engine which is found inside Car's class is pointed towards the new created object of engine in line 49
    //& is not written beside the second engine as in this case it is the address is self , if engine and battery are declared without (new) , here we need (&) beside them
    car->battery = battery;
}

void Fleet_Management_System::Adding_Motorcycle(std::string brand, std::string model, int year, int Mileage,
                                                double Price,
                                                std::string Transimision, int MaxSpeed)
{
    std::cout << "Enter Moto Type : " << '\n';
    std::string MotoType;
    std::cin >> MotoType;
    std::cout << "Has ABS? (1->YES | 0->NO)" << '\n';
    bool choice;
    std::cin >> choice;
    std::cout << "Enter Seat Height : " << '\n';
    int Height;
    std::cin >> Height;
    Motorcycle *motorcycle = new Motorcycle(brand, model, year, Mileage, Price, Transimision, MaxSpeed, MotoType,
                                            choice, Height);

    motorcycles.push_back(motorcycle); // adding created motorcycle to motorcycle vector

    std::cout << "Enter Engine info : " << '\n';
    std::cout << "Enter Capacity : " << '\n';
    double capacity;
    std::cin >> capacity;
    std::cout << "Enter Hourse Power : " << '\n';
    int HoursePower;
    std::cin >> HoursePower;
    std::cout << "Enter Clyinders number : " << '\n';

    int Clyinders;
    std::cin >> Clyinders;
    std::cout << "Enter Fuel_Type  : " << '\n';

    std::string Fuel_Type;
    std::cin >> Fuel_Type;
    std::cout << "Enter Engine Type  : " << '\n';

    std::string EngineType;
    std::cin >> EngineType;
    Engine *engine = new Engine(capacity, HoursePower, Clyinders, Fuel_Type, EngineType);
    std::cout << "Enter Battery info : " << '\n';
    std::cout << "Enter Battery's voltage : " << '\n';
    int Voltage;
    std::cin >> Voltage;
    std::cout << "Enter Battery's Capacity : " << '\n';
    int Capacity;
    std::cin >> Capacity;
    std::cout << "Enter Battery's Type : " << '\n';
    std::string BatteryType;
    std::cin >> BatteryType;
    Battery *battery = new Battery(Voltage, Capacity, BatteryType);

    motorcycle->engine = engine;
    motorcycle->battery = battery;
}


template<class T>

void DisplayVehicles(const std::vector<T *> &vehicle__vector, std::string title)
{
    for (int i = 0; i < vehicle__vector.size(); i++)
    {
        std::cout << title << " #" << i + 1 << '\n';
        Vehicle *vehicle = vehicle__vector[i];
        vehicle->ViewDetails();
        //Run time polymorphism dealing with child (cars , motorcycles)  through the parent (vehicle)  --> called (Upcasting)
        if (Car *c = dynamic_cast<Car *>(vehicle__vector[i]))
        //since Engine and battery are found in the child classes (Car , Moto) so to access them from the Parent class (Vehicle) this is called Downcasting
        {
            // since vehicle__vector[i] its pointer is Vehicle (the parent class) from line 131 ,, so we here deal with Parent class (Vehicle) to access child class (car , moto) ---> Downcasting throw dynamic_cast operator
            c->engine->ViewDetails();
            c->battery->ViewDetails();
        } else if (Motorcycle *M = dynamic_cast<Motorcycle *>(vehicle__vector[i])) // Downcasting
        {
            M->engine->ViewDetails();
            M->battery->ViewDetails();
        }
    }
}


void Fleet_Management_System::Display_Fleet()
{
    DisplayVehicles(cars, "Cars");

    std::cout << "**************************************" << '\n';
    std::cout << "**************************************" << '\n';
    std::cout << "**************************************" << '\n';
    std::cout << "**************************************" << '\n';
    DisplayVehicles(motorcycles, "Motorcycles");


    // I used template instead of this code :
    // ======================================
    // cout << "Cars : " << '\n';
    // cout << "------------" << '\n';
    // for (int i = 0; i < cars.size(); i++)
    // {
    //     cout << "Car #" << i + 1 << '\n';
    //     cout << "------------" << '\n';
    //
    //     Vehicle *vehicle = cars[i]; // Run-time Polymorphism   dealing with child through the parent
    //     vehicle->ViewDetails();
    //     cars[i]->engine->ViewDetails();
    //     cars[i]->battery->ViewDetails();
    //     cout << "====================================================" << '\n';
    // }
    // cout << "*****************************************************" << '\n';
    // cout << "*****************************************************" << '\n';
    // cout << "*****************************************************" << '\n';
    //
    // cout << "Motorcyle : " << '\n';
    // cout << "------------" << '\n';
    // for (int i = 0; i < motorcycles.size(); i++)
    // {
    //     cout << "Motorcycle #" << i + 1 << '\n';
    //     cout << "------------" << '\n';
    //
    //     Vehicle *vehicle = motorcycles[i]; // Run-time Polymorphism  dealing with child through the parent
    //     vehicle->ViewDetails();
    //     motorcycles[i]->engine->ViewDetails();
    //     motorcycles[i]->battery->ViewDetails();
    //     cout << "====================================================" << '\n';
    // }
}


template<class S>
void Unique_Brands(std::set<std::string> unique_brands, std::vector<S *> vehicles)
{
    for (int i = 0; i < vehicles.size(); i++)
    {
        unique_brands.insert(vehicles[i]->GetBrand());
    }
    for (const auto &item: unique_brands) // set has no indcies
    {
        std::cout << item << '\n';
    }
}


void Fleet_Management_System::Brands_that_exist_in_your_fleet()
{
    std::set<std::string> brands_cars;
    std::set<std::string> brands_motorcycle;


    std::cout << "Brand Cars that exist in your fleet : " << '\n';
    Unique_Brands(brands_cars, cars);


    std::cout << "Brand Motorcycle that exist in your fleet : " << '\n';
    Unique_Brands(brands_motorcycle, motorcycles);
}


template<class M>

void count_Brands(std::unordered_map<std::string, int> count_per_brand_cars, std::vector<M *> vehicle)
{
    for (int i = 0; i < vehicle.size(); i++)
    {
        count_per_brand_cars[vehicle[i]->GetBrand()]++;
        // you must write vehicle[i]->GetBrand() by yourself as it will not be found in the suggestions while writing so take care dont be confused
    }
    for (const auto [Brand , count]: count_per_brand_cars)
    {
        std::cout << Brand << " : " << count << '\n';
    }
}

void Fleet_Management_System::Display_count_per_brand()
{
   std:: unordered_map<std::string, int> count_per_brand;
    std::cout << "For Cars : " << '\n';
    count_Brands(count_per_brand, cars);


    std::cout << "===============================" << '\n';
    std::cout << "For Motorcycle : " << '\n';
    std::unordered_map<std::string, int> count_per_brand_moto;
    count_Brands(count_per_brand_moto, motorcycles);
}

void Fleet_Management_System::Adding_Vehicle(int choice)
{
    std::cout << "Enter Brand : " << '\n';
    std::string brand;
    std::cin >> brand;

    std::cout << "Enter Model : " << '\n';
   std:: string model;
   std:: cin >> model;
    std::cout << "Enter Vehicle's Production Year : " << '\n';
    int year;
    std::cin >> year;


    while (year > 2026 || year <= 2000)
    {
       std:: cout << "Invalid year ! Please enter a valid year from 2000 to 2026 " << '\n';
       std:: cin >> year;
    }

    std::cout << "Enter Mileage : " << '\n';
    int Mileage;
    std::cin >> Mileage;

    while (Mileage < 0 || Mileage > 500000)
    {
        std::cout << "Invalid Mileage ! Please enter a valid Mileage from 0 to 500000 " << '\n';
       std:: cin >> Mileage;
    }
    std::cout << "Enter Price : " << '\n';

    double Price;
    std::cin >> Price;
    while (Price < 0)
    {
       std:: cout << "Invalid Price ! Please enter a valid Positive Price" << '\n';
       std:: cin >> Price;
    }

   std:: cout << "Enter Maximum speed : " << '\n';
    int MaxSpeed;
   std:: cin >> MaxSpeed;
    while (MaxSpeed < 0)
    {
      std::  cout << "Invalid Price ! Please enter a valid Positive Maximum speed" << '\n';
       std:: cin >> MaxSpeed;
    }
    std::cout << "Enter Transimission " << '\n';
    std::string Transimision;
    std::cin >> Transimision;

    if (choice == 1)
    {
        Adding_Car(brand, model, year, Mileage, Price, Transimision, MaxSpeed);
    } else
    {
        Adding_Motorcycle(brand, model, year, Mileage, Price, Transimision, MaxSpeed);
    }
}

template<class B>

void Search_by_Brand_in_fleet(std::vector<B *> &Vehicle, std::string Brand)
{
    std::unordered_map<std::string,std:: vector<B *> > search_by_brand; // for faster search O(1)
    for (auto item: Vehicle)
    {
        search_by_brand[item->GetBrand()].push_back(item);
        // again you MUST write this line by yourself , syntax of this line while writing will not appear in suggestions so dont be confused
        //why(vehicle)  as we deal with vector<Car*>cars ((pointer points to addresses of cars object , when you want any of these cars make (object)
    }

    auto itr = search_by_brand.find(Brand);
    if (itr != search_by_brand.end())
    {
        for (auto item: itr->second)
        // itr-second (as we loop on cars vector which is inside the hash map)
        {
            item->ViewDetails(); // -> not . as itr->second (which is car or moto) is a pointer <B*>
        }
    } else
    {
        std::cout << "This Vehicle does not exist in our fleet ! " << '\n';
    }
}


void Fleet_Management_System::Search_By_Brand(int choice, std::string Brand)
{
    if (choice == 1)
    {
        Search_by_Brand_in_fleet(cars, Brand);
    } else if (choice == 2)
    {
        Search_by_Brand_in_fleet(motorcycles, Brand);
    }
}


template<class T>
void Search_By_Model_IN_Your_fleet(std::vector<T *> vechicle, std::string Model)
{
    std::unordered_map<std::string, std::vector<T *> > search_By_Model;
    for (auto item: vechicle)
    {
        search_By_Model[item->GetModel()].push_back(item);
    }

    auto itr = search_By_Model.find(Model);
    if (itr != search_By_Model.end())
    {
        for (auto item: itr->second)
        {
            item->ViewDetails();
        }
    } else
    {
        std::cout << "This vehicle does not exist in our fleet " << '\n';
    }
}


void Fleet_Management_System::Search_By_Model(int choice, std::string Model)
{
    if (choice == 1)
    {
        Search_By_Model_IN_Your_fleet(cars, Model);
    } else
    {
        Search_By_Model_IN_Your_fleet(motorcycles, Model);
    }
}


template<class T>
void Search_By_Year_IN_Your_fleet(std::vector<T *> vechicle, int Year)
{
    std::unordered_map<int,std:: vector<T *> > search_By_Model;
    for (auto item: vechicle)
    {
        search_By_Model[item->GetYear()].push_back(item);
    }

    auto itr = search_By_Model.find(Year);
    if (itr != search_By_Model.end())
    {
        for (auto item: itr->second)
        {
            item->ViewDetails();
        }
    } else
    {
        std::cout << "This vehicle does not exist in our fleet " << '\n';
    }
}


void Fleet_Management_System::Search_By_Year(int choice, int Year)
{
    if (choice == 1)
    {
        Search_By_Year_IN_Your_fleet(cars, Year);
    } else
    {
        Search_By_Year_IN_Your_fleet(motorcycles, Year);
    }
}


bool CompareCars(Car *a, Car *b)
{
    return a->GetYear() < b->GetYear();
}

bool CompareMoto(Motorcycle *a, Motorcycle *b)
{
    return a->GetYear() < b->GetYear();
}

template<class T>
void PrintSorted_OLD_TO_NEW(std::vector<T *> Vector_Copy, bool (*compareFunc)(T *, T *), std::string title)
//Using Function Pointer | ( *compareFunc) the name of pointer that will carry the function sent
{
   std:: cout << "For : " << title << '\n';
    std::cout << "--------------------" << '\n';

    sort(Vector_Copy.begin(), Vector_Copy.end(), compareFunc);
    for (int i = 0; i < Vector_Copy.size(); i++)
    {
        Vehicle *vehicle = Vector_Copy[i]; // Run-Time Polymorphism
        vehicle->ViewDetails();
    }
}


void Fleet_Management_System::sort_Old_to_new()
{
    std::vector<Car *> CARS = cars;
    std::vector<Motorcycle *> MOTO = motorcycles;
    PrintSorted_OLD_TO_NEW(CARS, CompareCars, "Cars");

    std::cout << "*****************************************" << '\n';
    std::cout << "*****************************************" << '\n';
    PrintSorted_OLD_TO_NEW(MOTO, CompareMoto, "Motorcycles");
}

bool CompareCars2(Car *a, Car *b)
{
    return a->GetYear() > b->GetYear();
}

bool CompareMoto2(Motorcycle *a, Motorcycle *b)
{
    return a->GetYear() > b->GetYear();
}

template<class T>

void printsorted_NEW_TO_OLD(std::vector<T *> Copy_Vector, bool (*CompareFunc)(T *, T *), std::string title)
{
   std:: cout << "For : " << title << '\n';
   std:: cout << "------------------" << '\n';

    sort(Copy_Vector.begin(), Copy_Vector.end(), CompareFunc);
    for (int i = 0; i < Copy_Vector.size(); i++)
    {
        Vehicle *vehicle = Copy_Vector[i];
        vehicle->ViewDetails(); //Run Time polyMorphism
    }
}


void Fleet_Management_System::sort_new_to_Old()
{
   std:: vector<Car *> CARS = cars;
    std::vector<Motorcycle *> MOTO = motorcycles;

    printsorted_NEW_TO_OLD(CARS, CompareCars2, "Cars");
    std::cout << "**********************************************************" << '\n';
    std::cout << "**********************************************************" << '\n';
    std::cout << "**********************************************************" << '\n';
    printsorted_NEW_TO_OLD(MOTO, CompareMoto2, "Motorcycles");
}

template<class T>
void Remove_By_Binary_Search(std::vector<T *> &vehicle, int id)
{
    // ID's are arranged as we genetrated id's , so we can apply binary search O(log n) , instead of linear search O(n);
    // without & vehicle vector will be just a copy of cars or moto vector and any modification on it will not be noted in the orginial vectors


    int start = 0, end = vehicle.size() - 1, mid = -1, index = -1;
    bool found = false;
    while (start <= end)
    {
        mid = (start + end) / 2;
        if (vehicle[mid]->GetID() == id)
        {
            found = true;
            index = mid;
            break;
        }
        if (vehicle[mid]->GetID() < id)
        {
            start = mid + 1;
        } else
        {
            end = mid - 1;
        }
    }
    if (found)
    {
        delete vehicle[index]; // in order to be deleted from heap memory and avoiding memory leak
        vehicle.erase(vehicle.begin() + index);
       std:: cout << "Removed successfully !" << '\n';
    } else
    {
        std::cout << "Does not exist in our fleet " << '\n';
    }
}

void Fleet_Management_System::Removing_Vehicle(int choice, int id)
{
    if (choice == 1)
    {
        Remove_By_Binary_Search(cars, id);
    } else
    {
        Remove_By_Binary_Search(motorcycles, id);
    }
}


void Fleet_Management_System::Display_Menu()
{
    int Choice;
    char do_you_want_to_continue;
    do
    {
        std::cout << "================================" << '\n';
        std::cout << "Fleet Management Console System " << '\n';
        std::cout << "================================" << '\n';
        std::cout << "1. ADD a new vehicle " << '\n';
        std::cout << "2. Display fleet " << '\n';
        std::cout << "3. Brands that exist in your fleet " << '\n';
        std::cout << "4. Display count per brand " << '\n';
        std::cout << "5. search vehicle by brand " << '\n';
        std::cout << "6. search vehicle by model " << '\n';
        std::cout << "7. search vehicle by year " << '\n';
        std::cout << "8. Sort cars from newest to oldest " << '\n';
        std::cout << "9. Sort cars from oldest to newest " << '\n';
        std::cout << "10. Remove a Vehicle " << '\n';
        std::cout << "-----------------------------------" << '\n';
        std::cout << "Enter your choice : ";

        while (!(std::cin >> Choice)) // testes the input , if it is not integer as(abc) enter the loop
        {
            std::cout << "Invalid input ! Enter an integer ! " << '\n';
            std::cin.clear(); //clears the error state of cin , allowing to accept input again
            std::cin.ignore(10000, '\n'); // ignores wrong input up to 10000 char , when the user press enter stop ignoring
        }

        switch (Choice)
        {
            case 1:
            {
                std::cout << "1. For adding cars " << '\n';
                std::cout << "2. For adding motorcycles " << '\n';

                int choice;


                while (!(std::cin >> choice) || (choice != 1 && choice != 2)) // to avoid string or char input
                {
                    std::cout << "Enter a valid choice -> (1 or 2) !" << '\n';
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                }

                if (choice == 1)
                {
                    Adding_Vehicle(choice);
                } else
                {
                    Adding_Vehicle(choice);
                }
                break;
            }


            case 2:
                Display_Fleet();
                break;
            case 3:
            {
                Brands_that_exist_in_your_fleet();
                break;
            }
            case 4:
            {
                Display_count_per_brand();
                break;
            }
            case 5:
            {
                std::cout << "1. Search For a car " << '\n';
                std::cout << "2. Search for a Motorcycle " << '\n';
                int choice;


                while (!(std::cin >> choice) || (choice != 1 && choice != 2))
                {
                    std::cout << "Enter a valid choice -> (1 or 2) !" << '\n';
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                }


                std::cout << "Enter the brand you want to search by : " << '\n';
                std::string Brand;
                std::cin >> Brand;


                Search_By_Brand(choice, Brand);


                break;
            }
            case 6:
            {
                std::cout << "1. Search For a car " << '\n';
                std::cout << "2. Search for a Motorcycle " << '\n';
                int choice;


                while (!(std::cin >> choice) || (choice != 1 && choice != 2))
                {
                   std:: cout << "Enter a valid choice -> (1 or 2) !" << '\n';
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                }

                std::cout << "Enter the Model you want to search by : " << '\n';
                std::string Model;
                std::cin >> Model;
                Search_By_Model(choice, Model);

                break;
            }
            case 7:
            {
                std::cout << "1. Search For a car " << '\n';
                std::cout << "2. Search for a Motorcycle " << '\n';
                int choice;

                while (!(std::cin >> choice) || (choice != 1 && choice != 2))
                {
                    std::cout << "Enter a valid choice -> (1 or 2) !" << '\n';
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                }
                std::cout << "Enter the Year you want to search by : " << '\n';
                int year;
                std::cin >> year;

                Search_By_Year(choice, year);


                break;
            }
            case 8:
            {
                sort_new_to_Old();
                break;
            }
            case 9:
            {
                sort_Old_to_new();
                break;
            }
            case 10:
            {
                std::cout << "What type of Vehicles you want to remove ? " << '\n';
                std::cout << "1.Car " << '\n';
                std::cout << "2.Motorcycle " << '\n';
                int choice;


                while (!(std::cin >> choice) || (choice != 1 && choice != 2))
                {
                    std::cout << "Enter a valid choice -> (1 or 2) !" << '\n';
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                }

               std:: cout << "Enter it's ID : " << '\n';
                int id;
               std:: cin >> id;

                Removing_Vehicle(choice, id);


                break;
            }
            default:

                break ;
        }


       std:: cout << "Do you want to continue ? (Y/N) or (y/n)" << '\n';

        std::cin >> do_you_want_to_continue;
        while (do_you_want_to_continue != 'Y' && do_you_want_to_continue != 'y' && do_you_want_to_continue != 'N' &&
               do_you_want_to_continue != 'n')
        {
            std::cout << "Invalid please Enter a valid letter ((Y/y)-> YES | (N/n)->No)" << '\n';
            std::cin >> do_you_want_to_continue;
        }

        if (do_you_want_to_continue == 'Y' || do_you_want_to_continue == 'y')
        {
            continue;
        } else
        {
            break;
        }
    } while (do_you_want_to_continue != 'Y' || do_you_want_to_continue != 'y' || do_you_want_to_continue != 'N' ||
             do_you_want_to_continue != 'n');
}
