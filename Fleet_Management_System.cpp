#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <queue>
#include <functional>
#include "Fleet_Management_System.h"


void Fleet_Management_System::Adding_Car(string brand, string model, int year, int Mileage, double Price,
                                         string Transimision, int MaxSpeed
)
{
    cout << "Enter Number of Seats : " << '\n';
    int NumberOFseats;
    cin >> NumberOFseats;
    cout << "Enter Number of Doors : " << '\n';
    int NumberOFDoors;
    cin >> NumberOFDoors;
    cout << "Enter Trunk Capacity : " << '\n';
    int TrunkCapacity;
    cin >> TrunkCapacity;
    cout << "Enter Car's Type : " << '\n';
    string type;
    cin >> type;
    Car *car = new Car(brand, model, year, Mileage, Price, Transimision, MaxSpeed, NumberOFseats, NumberOFDoors,
                       TrunkCapacity, type);

    cars.push_back(car); // adding created car to the vector of cars

    cout << "Enter Engine info : " << '\n';
    cout << "Enter Capacity : " << '\n';
    double capacity;
    cin >> capacity;
    cout << "Enter Hourse Power : " << '\n';

    int HoursePower;
    cin >> HoursePower;
    cout << "Enter Clyinders  : " << '\n';

    int Clyinders;
    cin >> Clyinders;
    cout << "Enter Fuel_Type : " << '\n';

    string Fuel_Type;
    cin >> Fuel_Type;
    cout << "Enter Engine Type  : " << '\n';

    string EngineType;
    cin >> EngineType;
    Engine *engine = new Engine(capacity, HoursePower, Clyinders, Fuel_Type, EngineType);
    cout << "Enter Battery's voltage : " << '\n';
    int Voltage;
    cin >> Voltage;
    cout << "Enter Battery's Capacity : " << '\n';
    int Capacity;
    cin >> Capacity;
    cout << "Enter Battery's Type : " << '\n';
    string BatteryType;
    cin >> BatteryType;
    Battery *battery = new Battery(Voltage, Capacity, BatteryType);
    //composition (Strong Relation)
    car->engine = engine;
    // The pointer (engine) from the type Engine which is found inside Car's class is pointed towards the new created object of engine in line 49
    //& is not written beside the second engine as in this case it is the address is self , if engine and battery are declared without (new) , here we need (&) beside them
    car->battery = battery;
}

void Fleet_Management_System::Adding_Motorcycle(string brand, string model, int year, int Mileage, double Price,
                                                string Transimision, int MaxSpeed)
{
    cout << "Enter Moto Type : " << '\n';
    string MotoType;
    cin >> MotoType;
    cout << "Has ABS? (1->YES | 0->NO)" << '\n';
    bool choice;
    cin >> choice;
    cout << "Enter Seat Height : " << '\n';
    int Height;
    cin >> Height;
    Motorcycle *motorcycle = new Motorcycle(brand, model, year, Mileage, Price, Transimision, MaxSpeed, MotoType,
                                            choice, Height);

    motorcycles.push_back(motorcycle); // adding created motorcycle to motorcycle vector

    cout << "Enter Engine info : " << '\n';
    cout << "Enter Capacity : " << '\n';
    double capacity;
    cin >> capacity;
    cout << "Enter Hourse Power : " << '\n';
    int HoursePower;
    cin >> HoursePower;
    cout << "Enter Clyinders number : " << '\n';

    int Clyinders;
    cin >> Clyinders;
    cout << "Enter Fuel_Type  : " << '\n';

    string Fuel_Type;
    cin >> Fuel_Type;
    cout << "Enter Engine Type  : " << '\n';

    string EngineType;
    cin >> EngineType;
    Engine *engine = new Engine(capacity, HoursePower, Clyinders, Fuel_Type, EngineType);
    cout << "Enter Battery info : " << '\n';
    cout << "Enter Battery's voltage : " << '\n';
    int Voltage;
    cin >> Voltage;
    cout << "Enter Battery's Capacity : " << '\n';
    int Capacity;
    cin >> Capacity;
    cout << "Enter Battery's Type : " << '\n';
    string BatteryType;
    cin >> BatteryType;
    Battery *battery = new Battery(Voltage, Capacity, BatteryType);

    motorcycle->engine = engine;
    motorcycle->battery = battery;
}


template<class T>

void DisplayVehicles(const vector<T *> &vehicle__vector, string title)
{
    for (int i = 0; i < vehicle__vector.size(); i++)
    {
        cout << title << " #" << i + 1 << '\n';
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

    cout << "**************************************" << '\n';
    cout << "**************************************" << '\n';
    cout << "**************************************" << '\n';
    cout << "**************************************" << '\n';
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
void Unique_Brands(set<string> unique_brands, vector<S *> vehicles)
{
    for (int i = 0; i < vehicles.size(); i++)
    {
        unique_brands.insert(vehicles[i]->GetBrand());
    }
    for (const auto &item: unique_brands) // set has no indcies
    {
        cout << item << '\n';
    }
}


void Fleet_Management_System::Brands_that_exist_in_your_fleet()
{
    set<string> brands_cars;
    set<string> brands_motorcycle;


    cout << "Brand Cars that exist in your fleet : " << '\n';
    Unique_Brands(brands_cars, cars);


    cout << "Brand Motorcycle that exist in your fleet : " << '\n';
    Unique_Brands(brands_motorcycle, motorcycles);
}


template<class M>

void count_Brands(unordered_map<string, int> count_per_brand_cars, vector<M *> vehicle)
{
    for (int i = 0; i < vehicle.size(); i++)
    {
        count_per_brand_cars[vehicle[i]->GetBrand()]++;
        // you must write vehicle[i]->GetBrand() by yourself as it will not be found in the suggestions while writing so take care dont be confused
    }
    for (const auto [Brand , count]: count_per_brand_cars)
    {
        cout << Brand << " : " << count << '\n';
    }
}

void Fleet_Management_System::Display_count_per_brand()
{
    unordered_map<string, int> count_per_brand;
    cout << "For Cars : " << '\n';
    count_Brands(count_per_brand, cars);


    cout << "===============================" << '\n';
    cout << "For Motorcycle : " << '\n';
    unordered_map<string, int> count_per_brand_moto;
    count_Brands(count_per_brand_moto, motorcycles);
}

void Fleet_Management_System::Adding_Vehicle(int choice)
{
    cout << "Enter Brand : " << '\n';
    string brand;
    cin >> brand;

    cout << "Enter Model : " << '\n';
    string model;
    cin >> model;
    cout << "Enter Vehicle's Production Year : " << '\n';
    int year;
    cin >> year;


    while (year > 2026 || year <= 2000)
    {
        cout << "Invalid year ! Please enter a valid year from 2000 to 2026 " << '\n';
        cin >> year;
    }

    cout << "Enter Mileage : " << '\n';
    int Mileage;
    cin >> Mileage;

    while (Mileage < 0 || Mileage > 500000)
    {
        cout << "Invalid Mileage ! Please enter a valid Mileage from 0 to 500000 " << '\n';
        cin >> Mileage;
    }
    cout << "Enter Price : " << '\n';

    double Price;
    cin >> Price;
    while (Price < 0)
    {
        cout << "Invalid Price ! Please enter a valid Positive Price" << '\n';
        cin >> Price;
    }

    cout << "Enter Maximum speed : " << '\n';
    int MaxSpeed;
    cin >> MaxSpeed;
    while (MaxSpeed < 0)
    {
        cout << "Invalid Price ! Please enter a valid Positive Maximum speed" << '\n';
        cin >> MaxSpeed;
    }
    cout << "Enter Transimission " << '\n';
    string Transimision;
    cin >> Transimision;

    if (choice == 1)
    {
        Adding_Car(brand, model, year, Mileage, Price, Transimision, MaxSpeed);
    } else
    {
        Adding_Motorcycle(brand, model, year, Mileage, Price, Transimision, MaxSpeed);
    }
}

template<class B>

void Search_by_Brand_in_fleet(vector<B *> &Vehicle, string Brand)
{
    unordered_map<string, vector<B *> > search_by_brand; // for faster search O(1)
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
        cout << "This Vehicle does not exist in our fleet ! " << '\n';
    }
}


void Fleet_Management_System::Search_By_Brand(int choice, string Brand)
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
void Search_By_Model_IN_Your_fleet(vector<T *> vechicle, string Model)
{
    unordered_map<string, vector<T *> > search_By_Model;
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
        cout << "This vehicle does not exist in our fleet " << '\n';
    }
}


void Fleet_Management_System::Search_By_Model(int choice, string Model)
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
void Search_By_Year_IN_Your_fleet(vector<T *> vechicle, int Year)
{
    unordered_map<int, vector<T *> > search_By_Model;
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
        cout << "This vehicle does not exist in our fleet " << '\n';
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
void PrintSorted_OLD_TO_NEW(vector<T *> Vector_Copy, bool (*compareFunc)(T *, T *), string title)
//Using Function Pointer | ( *compareFunc) the name of pointer that will carry the function sent
{
    cout << "For : " << title << '\n';
    cout << "--------------------" << '\n';

    sort(Vector_Copy.begin(), Vector_Copy.end(), compareFunc);
    for (int i = 0; i < Vector_Copy.size(); i++)
    {
        Vehicle *vehicle = Vector_Copy[i]; // Run-Time Polymorphism
        vehicle->ViewDetails();
    }
}


void Fleet_Management_System::sort_Old_to_new()
{
    vector<Car *> CARS = cars;
    vector<Motorcycle *> MOTO = motorcycles;
    PrintSorted_OLD_TO_NEW(CARS, CompareCars, "Cars");

    cout << "*****************************************" << '\n';
    cout << "*****************************************" << '\n';
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

void printsorted_NEW_TO_OLD(vector<T *> Copy_Vector, bool (*CompareFunc)(T *, T *), string title)
{
    cout << "For : " << title << '\n';
    cout << "------------------" << '\n';

    sort(Copy_Vector.begin(), Copy_Vector.end(), CompareFunc);
    for (int i = 0; i < Copy_Vector.size(); i++)
    {
        Vehicle *vehicle = Copy_Vector[i];
        vehicle->ViewDetails(); //Run Time polyMorphism
    }
}


void Fleet_Management_System::sort_new_to_Old()
{
    vector<Car *> CARS = cars;
    vector<Motorcycle *> MOTO = motorcycles;

    printsorted_NEW_TO_OLD(CARS, CompareCars2, "Cars");
    cout << "**********************************************************" << '\n';
    cout << "**********************************************************" << '\n';
    cout << "**********************************************************" << '\n';
    printsorted_NEW_TO_OLD(MOTO, CompareMoto2, "Motorcycles");
}

template<class T>
void Remove_By_Binary_Search(vector<T *> &vehicle, int id)
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
        cout << "Removed successfully !" << '\n';
    } else
    {
        cout << "Does not exist in our fleet " << '\n';
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

        while (!(cin >> Choice)) // testes the input , if it is not integer as(abc) enter the loop
        {
            cout << "Invalid input ! Enter an integer ! " << '\n';
            cin.clear(); //clears the error state of cin , allowing to accept input again
            cin.ignore(10000, '\n'); // ignores wrong input up to 10000 char , when the user press enter stop ignoring
        }

        switch (Choice)
        {
            case 1:
            {
                cout << "1. For adding cars " << '\n';
                cout << "2. For adding motorcycles " << '\n';

                int choice;


                while (!(cin >> choice) || (choice != 1 && choice != 2))  // to avoid string or char input
                {
                    cout << "Enter a valid choice -> (1 or 2) !" << '\n';
                    cin.clear();
                    cin.ignore(10000, '\n');

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
                cout << "1. Search For a car " << '\n';
                cout << "2. Search for a Motorcycle " << '\n';
                int choice;



                while (!(cin >> choice) || (choice != 1 && choice != 2))
                {
                    cout << "Enter a valid choice -> (1 or 2) !" << '\n';
                    cin.clear();
                    cin.ignore(10000, '\n');

                }



                cout << "Enter the brand you want to search by : " << '\n';
                string Brand;
                cin >> Brand;


                Search_By_Brand(choice, Brand);


                break;
            }
            case 6:
            {
                cout << "1. Search For a car " << '\n';
                cout << "2. Search for a Motorcycle " << '\n';
                int choice;


                while (!(cin >> choice) || (choice != 1 && choice != 2))
                {
                    cout << "Enter a valid choice -> (1 or 2) !" << '\n';
                    cin.clear();
                    cin.ignore(10000, '\n');

                }

                cout << "Enter the Model you want to search by : " << '\n';
                string Model;
                cin >> Model;
                Search_By_Model(choice, Model);

                break;
            }
            case 7:
            {
                cout << "1. Search For a car " << '\n';
                cout << "2. Search for a Motorcycle " << '\n';
                int choice;

                while (!(cin >> choice) || (choice != 1 && choice != 2))
                {
                    cout << "Enter a valid choice -> (1 or 2) !" << '\n';
                    cin.clear();
                    cin.ignore(10000, '\n');

                }
                cout << "Enter the Year you want to search by : " << '\n';
                int year;
                cin >> year;

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
                cout << "What type of Vehicles you want to remove ? " << '\n';
                cout << "1.Car " << '\n';
                cout << "2.Motorcycle " << '\n';
                int choice;



                while (!(cin >> choice) || (choice != 1 && choice != 2))
                {
                    cout << "Enter a valid choice -> (1 or 2) !" << '\n';
                    cin.clear();
                    cin.ignore(10000, '\n');

                }

                cout << "Enter it's ID : " << '\n';
                int id;
                cin >> id;

                Removing_Vehicle(choice, id);


                break;
            }
            default:

                break ;
        }


        cout << "Do you want to continue ? (Y/N) or (y/n)" << '\n';

        cin >> do_you_want_to_continue;
        while (do_you_want_to_continue != 'Y' && do_you_want_to_continue != 'y' && do_you_want_to_continue != 'N' &&
               do_you_want_to_continue != 'n')
        {
            cout << "Invalid please Enter a valid letter ((Y/y)-> YES | (N/n)->No)" << '\n';
            cin >> do_you_want_to_continue;
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
