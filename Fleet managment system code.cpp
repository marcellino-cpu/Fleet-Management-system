#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <string>
#include <queue>

struct vehicle
{
    std::string brand;
    std::string model;
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




void Storing_cars(vehicle newcar, std::vector<vehicle> &datacar)
{

    datacar.push_back(newcar);
}




void Displaying_Fleet(const std::vector<vehicle> &Cars_data)
{
    int counter = 1;
    for (const auto &indecator : Cars_data)
    {
        std::cout << "CAR #" << counter << '\n';
        counter++;
        std::cout << "Brand : ";
        std::cout << indecator.brand << '\n';
        std::cout << "Model : ";
        std::cout << indecator.model << '\n';
        std::cout << "Year : ";
        std::cout << indecator.year << '\n';
        std::cout << "Mileage : ";
        std::cout << indecator.mileage << '\n';
        std::cout << "=============================" << '\n';
        std::cout << "=============================" << '\n';
    }
}






void Displaying_brands(std::set<std::string> &Unique_brands, const std::vector<vehicle> &Cars_data)
{
    for (const auto &S : Cars_data)
    {
        Unique_brands.insert(S.brand); // take care : you insert here the vector's component (S)
    }
    std::cout << "Brands exitsing in your fleet " << '\n';
    for (const auto &X : Unique_brands)
    {

        std::cout << X << '\n'; // take care : you are displaying set component (X) not car.brand
    }
}





void count_per_brand(std::unordered_map<std::string, int> count, const std::vector<vehicle> &cars_data)
{

    for (const auto &V : cars_data)
    {
        count[V.brand]++;
    }

    for (const auto &[Brand, count] : count)
    {
        std::cout << Brand << " | It's available amount  :   " << count << '\n';
    }
}






void Search_by_Brand(std::string brand, std::unordered_map<std::string, std::vector<vehicle>> &Search_by_Brand, const std::vector<vehicle> &DATA_CARS)
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
            std::cout << "Car's brand :  ";
            std::cout << A.brand << '\n';
            std::cout << "Car's model :  ";
            std::cout << A.model << '\n';
            std::cout << "Car's year :   ";
            std::cout << A.year << '\n';
            std::cout << "Car's mileage :  ";
            std::cout << A.mileage << '\n';
            std::cout << "---------------------------------" << '\n';
            std::cout << "---------------------------------" << '\n';
        }
    }
    else
    {
        std::cout << "This brand does not exist in your fleet " << '\n';
    }
}






void Search_by_model(std::string ModeL, std::unordered_map<std::string, std::vector<vehicle>> &MODEL_map, std::vector<vehicle> &carsdata)
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
            std::cout << "Brand :  ";
            std::cout << K.brand << '\n';
            std::cout << "Model :  ";
            std::cout << K.model << '\n';
            std::cout << "Year :   ";
            std::cout << K.year << '\n';
            std::cout << "Mileage :";
            std::cout << K.mileage << '\n';
            std::cout << "--------------------------------------" << '\n';
            std::cout << "--------------------------------------" << '\n';
        }
    }
    else
    {
        std::cout << "This model does not exist " << '\n';
    }
}








void search_by_year(int year, std::unordered_map<int, std::vector<vehicle>> &search_by__year, std::vector<vehicle> &V)
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
            std::cout << "Brand : ";
            std::cout << Q.brand << '\n';
            std::cout << "Model : ";
            std::cout << Q.model << '\n';
            std::cout << "Year : ";
            std::cout << Q.year << '\n';
            std::cout << "Mileage :";
            std::cout << Q.mileage << '\n';
            std::cout << "---------------------------------------" << '\n';
            std::cout << "---------------------------------------" << '\n';
        }
    }
    else
    {
        std::cout << "There is no car added to your fleet with this year number ! ";
    }
}








void Sorting(const std::vector<vehicle> &V, std::priority_queue<std::pair<int, vehicle>> &sort_by_newest)
{
    for (const auto &P : V)
    {
        sort_by_newest.push({P.year, P});
    }

    std::cout << "Cars from newest one to the oldest : " << '\n';

    while (!sort_by_newest.empty())
    {
        auto Newestcar = sort_by_newest.top(); // grabbing the newest car to display , then remove it by pop()
        std::cout << "===========================" << '\n';
        std::cout << "Year" << Newestcar.first << '\n';
        std::cout << "------- " << '\n';
        std::cout << "Brand : " << Newestcar.second.brand << '\n';
        std::cout << "Model : " << Newestcar.second.model << '\n';
        std::cout << "Mileage : " << Newestcar.second.model << '\n';

        sort_by_newest.pop();
    }
}







void sort_by_oldest(std::vector<vehicle> &CARS_DATA, std::priority_queue<std::pair<int, vehicle>, std::vector<std::pair<int, vehicle>>, std::greater<std::pair<int, vehicle>>> &sort_from_oldest)
{
    for (const auto &Z : CARS_DATA)
    {
        sort_from_oldest.push({Z.year, Z});
    }

    std::cout << "Cars form the oldest one to the newest : " << '\n';
    while (!sort_from_oldest.empty())
    {

        auto oldestcar = sort_from_oldest.top(); // grabbing the oldest car to the top , then removing after displaying with pop()
        std::cout << "================================" << '\n';
        std::cout << "Year : " << oldestcar.first << '\n';
        std::cout << "-------" << '\n';
        std::cout << "Brand : " << oldestcar.second.brand << '\n';
        std::cout << "Model : " << oldestcar.second.model << '\n';
        std::cout << "Mileage : " << oldestcar.second.mileage << '\n';
        sort_from_oldest.pop();
    }
}








int main()
{
    std::vector<vehicle> Cars_data;
    std::set<std::string> Unique_brands;                                    // string not vehicle as we store (Cars' brands ) inside it which is a string
    std::unordered_map<std::string, int> counting;                          // O(1) better time complexity than map (O log n )
    std::unordered_map<std::string, std::vector<vehicle>> Search_by_BrandS; // O(1) better time complexity
    std::unordered_map<std::string, std::vector<vehicle>> Searchby_modell;  // O(1) better time complexity
    std::unordered_map<int, std::vector<vehicle>> search_by_yearr;          // O(1)
    std::priority_queue<std::pair<int, vehicle>> sort_by_newest;
    std::priority_queue<std::pair<int, vehicle>, std::vector<std::pair<int, vehicle>>, std::greater<std::pair<int, vehicle>>> sort_from_oldest;
    vehicle car;
    char choice;

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
        std::cout << "-----------------------------------" << '\n';
        std::cout << "Enter your choice : ";
        std::cin >> choice;

        switch (choice)
        {
        case '1':
        {

            std::cout << "Enter The brand : " << '\n';
            std::cin >> car.brand;
            std::cout << "Enter The model : " << '\n';
            std::cin >> car.model;
            std::cout << "Enter the year : " << '\n';
            std::cin >> car.year;
            do
            {
                if (car.year < 1886 || car.year > 2026)
                {

                    std::cout << "Please Enter a valid year between 1886 to 2026 ! " << '\n';
                    std::cin >> car.year;
                    continue;
                }
                break;
            } while (true);

            std::cout << "Enter the mileage of the car : " << '\n';
            std::cin >> car.mileage;

            do
            {
                if (car.mileage < 0 || car.mileage > 500000)
                {
                    std::cout << "Please Enter a positive mileage that does not exceed 500000 mile " << '\n';
                    std::cin >> car.mileage;
                    continue;
                }

                break;
            } while (car.mileage < 0 || car.mileage > 500000);
            Storing_cars(car, Cars_data);
            std::cout << "Successful storage !" << '\n';
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
            std::string BRAND;
            std::cout << "Enter Cars's Brand you want to search for " << '\n';
            std::cin >> BRAND;
            Search_by_Brand(BRAND, Search_by_BrandS, Cars_data);
            break;
        }



            
        case '6':
        {
            std::string model;
            std::cout << "Enter car's model " << '\n';
            std::cin >> model;
            Search_by_model(model, Searchby_modell, Cars_data);
            break;
        }




            
        case '7':
        {
            int year;
            std::cout << "Enter a Year " << '\n';
            std::cin >> year;
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
            std::cout << "Invalid choice ! enter a number from 1 to 9 . " << '\n';
            break;
        }

    } while (true);
}
