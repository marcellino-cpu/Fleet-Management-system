#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <string>
#include <queue>
using namespace std;

struct vehicle
{
    string brand;
    string model;
    int year;
    int mileage;
    bool operator<(const vehicle &other) const
    {
        return year < other.year;
    }
    // This tells the compiler how to compare two vehicles , (operator<) name of function
    // We define comparison based on the 'year' field
    // So the compiler now knows how to sort vehicles or use them in a priority_queue
    // 'const' ensures the operator does not modify the vehicles
    // This is required so STL containers like priority_queue or sort can safely use the comparison
};

void Storing_cars(vehicle newcar, vector<vehicle> &datacar)
{

    datacar.push_back(newcar);
}

void Displaying_Fleet(const vector<vehicle> &Cars_data)
{
    int counter = 1;
    for (const auto &indecator : Cars_data)
    {
        cout << "CAR #" << counter << '\n';
        counter++;
        cout << "Brand : ";
        cout << indecator.brand << '\n';
        cout << "Model : ";
        cout << indecator.model << '\n';
        cout << "Year : ";
        cout << indecator.year << '\n';
        cout << "Mileage : ";
        cout << indecator.mileage << '\n';
        cout << "=============================" << '\n';
        cout << "=============================" << '\n';
    }
}

void Displaying_brands(set<string> &Unique_brands, const vector<vehicle> &Cars_data)
{
    for (const auto &S : Cars_data)
    {
        Unique_brands.insert(S.brand); // take care : you insert here the vector's component (S)
    }
    cout << "Brands exitsing in your fleet " << '\n';
    for (const auto &X : Unique_brands)
    {

        cout << X << '\n'; // take care : you are displaying set component (X) not car.brand
    }
}

void count_per_brand(unordered_map<string, int> count, const vector<vehicle> &cars_data)
{

    for (const auto &V : cars_data)
    {
        count[V.brand]++;
    }

    for (const auto &[Brand, count] : count)
    {
        cout << Brand << " | It's available amount  :   " << count << '\n';
    }
}

void Search_by_Brand(string brand, unordered_map<string, vector<vehicle>> &Search_by_Brand, const vector<vehicle> &DATA_CARS)
{
    Search_by_Brand.clear(); // because when we search about a car , the second time you'll search about a new car the first car you searched for will appear , so to avoid this I used mp.clear()
                             // also for better time complexity and removing the stored cars in this map by each time of search
    for (const auto &X : DATA_CARS)
    {
        Search_by_Brand[X.brand].push_back(X);
    }

    auto itr = Search_by_Brand.find(brand);
    if (itr != Search_by_Brand.end())
    {
        for (const auto &A : itr->second)
        { // we want to loop on the vector which is inside map
            cout << "Car's brand :  ";
            cout << A.brand << '\n';
            cout << "Car's model :  ";
            cout << A.model << '\n';
            cout << "Car's year :   ";
            cout << A.year << '\n';
            cout << "Car's mileage :  ";
            cout << A.mileage << '\n';
            cout << "---------------------------------" << '\n';
            cout << "---------------------------------" << '\n';
        }
    }
    else
    {
        cout << "This brand does not exist in your fleet " << '\n';
    }
}

void Search_by_model(string ModeL, unordered_map<string, vector<vehicle>> &MODEL_map, vector<vehicle> &carsdata)
{
    MODEL_map.clear();
    for (const auto &H : carsdata)
    {
        MODEL_map[H.model].push_back(H);
    }

    auto itr = MODEL_map.find(ModeL);
    if (itr != MODEL_map.end())
    {
        for (const auto &K : itr->second)
        {
            cout << "Brand :  ";
            cout << K.brand << '\n';
            cout << "Model :  ";
            cout << K.model << '\n';
            cout << "Year :   ";
            cout << K.year << '\n';
            cout << "Mileage :";
            cout << K.mileage << '\n';
            cout << "--------------------------------------" << '\n';
            cout << "--------------------------------------" << '\n';
        }
    }
    else
    {
        cout << "This model does not exist " << '\n';
    }
}

void search_by_year(int year, unordered_map<int, vector<vehicle>> &search_by__year, vector<vehicle> &V)
{
    search_by__year.clear();
    for (const auto &G : V)
    {
        search_by__year[G.year].push_back(G);
    }
    auto itr = search_by__year.find(year);
    if (itr != search_by__year.end())
    {
        for (const auto &Q : itr->second)
        {
            cout << "Brand : ";
            cout << Q.brand << '\n';
            cout << "Model : ";
            cout << Q.model << '\n';
            cout << "Year : ";
            cout << Q.year << '\n';
            cout << "Mileage :";
            cout << Q.mileage << '\n';
            cout << "---------------------------------------" << '\n';
            cout << "---------------------------------------" << '\n';
        }
    }
    else
    {
        cout << "There is no car added to your fleet with this year number ! ";
    }
}

void Sorting(const vector<vehicle> &V, priority_queue<pair<int, vehicle>> &sort_by_newest)
{
    for (const auto &P : V)
    {
        sort_by_newest.push({P.year, P});
    }

    cout << "Cars from newest one to the oldest : " << '\n';

    while (!sort_by_newest.empty())
    {
        auto Newestcar = sort_by_newest.top(); // grabbing the newest car to display , then remove it by pop()
        cout << "===========================" << '\n';
        cout << "Year" << Newestcar.first << '\n';
        cout << "------- " << '\n';
        cout << "Brand : " << Newestcar.second.brand << '\n';
        cout << "Model : " << Newestcar.second.model << '\n';
        cout << "Mileage : " << Newestcar.second.model << '\n';

        sort_by_newest.pop();
    }
}

void sort_by_oldest(vector<vehicle> &CARS_DATA, priority_queue<pair<int, vehicle>, vector<pair<int, vehicle>>, greater<pair<int, vehicle>>> &sort_from_oldest)
{
    for (const auto &Z : CARS_DATA)
    {
        sort_from_oldest.push({Z.year, Z});
    }

    cout << "Cars form the oldest one to the newest : " << '\n';
    while (!sort_from_oldest.empty())
    {

        auto oldestcar = sort_from_oldest.top(); // grabbing the oldest car to the top , then removing after displaying with pop()
        cout << "================================" << '\n';
        cout << "Year : " << oldestcar.first << '\n';
        cout << "-------" << '\n';
        cout << "Brand : " << oldestcar.second.brand << '\n';
        cout << "Model : " << oldestcar.second.model << '\n';
        cout << "Mileage : " << oldestcar.second.mileage << '\n';
        sort_from_oldest.pop();
    }
}

int main()
{
    vector<vehicle> Cars_data;
    set<string> Unique_brands;                               // string not vehicle as we store (Cars' brands ) inside it which is a string
    unordered_map<string, int> counting;                     // O(1) better time complexity than map (O log n )
    unordered_map<string, vector<vehicle>> Search_by_BrandS; // O(1) better time complexity
    unordered_map<string, vector<vehicle>> Searchby_modell;  // O(1) better time complexity
    unordered_map<int, vector<vehicle>> search_by_yearr;     // O(1)
    priority_queue<pair<int, vehicle>> sort_by_newest;
    priority_queue<pair<int, vehicle>, vector<pair<int, vehicle>>, greater<pair<int, vehicle>>> sort_from_oldest;
    vehicle car;
    char choice;

    do
    {
        cout << "================================" << '\n';
        cout << "Fleet Management Console System " << '\n';
        cout << "================================" << '\n';
        cout << "1. ADD a new vehicle " << '\n';
        cout << "2. Display fleet " << '\n';
        cout << "3. Brands that exist in your fleet " << '\n';
        cout << "4. Display count per brand " << '\n';
        cout << "5. search vehicle by brand " << '\n';
        cout << "6. search vehicle by model " << '\n';
        cout << "7. search vehicle by year " << '\n';
        cout << "8. Sort cars from newest to oldest " << '\n';
        cout << "9. Sort cars from oldest to newest " << '\n';
        cout << "-----------------------------------" << '\n';
        cout << "Enter your choice : ";
        cin >> choice;

        switch (choice)
        {
        case '1':
        {

            cout << "Enter The brand : " << '\n';
            cin >> car.brand;
            cout << "Enter The model : " << '\n';
            cin >> car.model;
            cout << "Enter the year : " << '\n';
            cin >> car.year;
            do
            {
                if (car.year < 1886 || car.year > 2026)
                {

                    cout << "Please Enter a valid year between 1886 to 2026 ! " << '\n';
                    cin >> car.year;
                    continue;
                }
                break;
            } while (true);

            cout << "Enter the mileage of the car : " << '\n';
            cin >> car.mileage;

            do
            {
                if (car.mileage < 0 || car.mileage > 500000)
                {
                    cout << "Please Enter a positive mileage that does not exceed 500000 mile " << '\n';
                    cin >> car.mileage;
                    continue;
                }

                break;
            } while (car.mileage < 0 || car.mileage > 500000);
            Storing_cars(car, Cars_data);
            cout << "Successful storage !" << '\n';
        }
        break;

        case '2':
            Displaying_Fleet(Cars_data);

            break;

        case '3':
            Displaying_brands(Unique_brands, Cars_data);
            break;

        case '4':
            count_per_brand(counting, Cars_data);
            break;

        case '5':
        {
            string BRAND;
            cout << "Enter Cars's Brand you want to search for " << '\n';
            cin >> BRAND;
            Search_by_Brand(BRAND, Search_by_BrandS, Cars_data);
            break;
        }
        case '6':
        {
            string model;
            cout << "Enter car's model " << '\n';
            cin >> model;
            Search_by_model(model, Searchby_modell, Cars_data);
            break;
        }

        case '7':
        {
            int year;
            cout << "Enter a Year " << '\n';
            cin >> year;
            search_by_year(year, search_by_yearr, Cars_data);

            break;
        }
        case '8':
        {
            Sorting(Cars_data, sort_by_newest);

            break;
        }
        case '9':
            sort_by_oldest(Cars_data, sort_from_oldest);
            break;

        default:
            cout << "Invalid choice ! enter a number from 1 to 8 . " << '\n';
            break;
        }

    } while (true);
}
