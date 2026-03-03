#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;
struct vehicle
{
    string brand;
    string model;
    int year;
    double mileage;
};
int main()
{

    vector<vehicle> M;
    vehicle v;
    char choice;

    do
    {

        cout << "==================================" << '\n';
        cout << "Fleet Management Console System " << '\n';
        cout << "==================================" << '\n';

        cout << "1. Add a new vehicle " << '\n';
        cout << "2. Display fleet " << '\n';
        cout << "3. Brands that exist in your fleet" << '\n';
        cout << "4. Display count per brand " << '\n';
        cout << "5. search vehicle by brand " << '\n';
        cout << "6. search vehicle by model" << '\n';
        cout << "7. search vehicle by year" << '\n';
        cout << "8. Exit" << '\n';
        cout << "---------------------------------" << '\n';
        cout << "---------------------------------" << '\n';
        cout << "Enter your choice :" << '\n';
        cin >> choice;
        switch (choice)
        {
            // Adding new car to the fleet
        case '1':
            cout << "Enter the brand : " << '\n';
            cin >> v.brand;
            cout << "Enter the model : " << '\n';
            cin >> v.model;
            do
            {
                cout << "Enter the year : " << '\n';
                cin >> v.year;
                if (v.year > 2026 || v.year < 1886)
                {
                    cout << "Invalid year ! Enter a year between 1886 and 2026 " << '\n';
                    continue;
                }

                break;
            } while (true);
            do
            {
                cout << "Enter the mileage : " << '\n';
                cin >> v.mileage;
                if (v.mileage < 0 || v.mileage > 1000000)
                {
                    cout << "Invalid mileage ! " << '\n';
                    continue;
                }
                break;
            } while (true);

            M.push_back(v);
            break;
            // displaying the cars of the fleet
        case '2':
            if (M.empty())
            {
                cout << "No vehicles are avalible in the fleet" << '\n';
            }
            for (int i = 0; i < M.size(); i++)
            {
                cout << "------------------------------" << '\n';
                cout << "Brand : " << M[i].brand << '\n';
                cout << "Model : " << M[i].model << '\n';
                cout << "year : " << M[i].year << '\n';
                cout << "mileage :" << M[i].mileage << '\n';
                cout << "------------------------------" << '\n';
            }
            break;
        case '3':
        {
            cout << M.size() << '\n';
            set<string> s;
            for (int i = 0; i < M.size(); i++)
            {
                s.insert(M[i].brand);
            }

            set<string>::iterator itr;
            for (itr = s.begin(); itr != s.end(); itr++)
            {
                cout << *itr << '\n';
            }

            break;
        }
        case '4':
        {
            map<string, int> mp;
            for (int i = 0; i < M.size(); i++)
            {
                mp[M[i].brand]++;
            }
            map<string, int>::iterator itr;
            for (itr = mp.begin(); itr != mp.end(); itr++)
            {
                cout << itr->first << ":" << itr->second << '\n';
            }
            break;
        }
        case '5':
        {
            map<string, vector<vehicle>> filtermap;
            string c;
            cout << "Enter brand :" << '\n';
            cin >> c;
            for (int i = 0; i < M.size(); i++)
            {
                filtermap[M[i].brand].push_back(M[i]);
            }
            map<string, vector<vehicle>>::iterator itr;
            for (itr = filtermap.begin(); itr != filtermap.end(); itr++)
            {
                for (int j = 0; j < itr->second.size(); j++)
                {
                    if (c != itr->second[j].brand)
                    {
                        break;
                    }

                    cout << "**********************************" << '\n';
                    cout << "brand: " << itr->first << '\n';
                    cout << "Car model :" << itr->second[j].brand << '\n';
                    cout << "Car model : " << itr->second[j].model << '\n';
                    cout << "Car year : " << itr->second[j].year << '\n';
                    cout << "Car mileage : " << itr->second[j].mileage << '\n';
                    cout << "**********************************" << '\n';
                }
            }
            break;
        }
        case '6':
        {
            map<string, vector<vehicle>> filtermodel;
            for (int i = 0; i < M.size(); i++)
            {
                filtermodel[M[i].model].push_back(M[i]);
            }
            string b;
            cout << "Enter car model : " << '\n';
            cin >> b;

            map<string, vector<vehicle>>::iterator itr;
            for (itr = filtermodel.begin(); itr != filtermodel.end(); itr++)
            {
                for (int i = 0; i < itr->second.size(); i++)
                {
                    if (b != itr->second[i].model)
                    {
                        continue;
                    }
                    cout << "******************************" << '\n';
                    cout << "Brand : " << itr->first << '\n';
                    cout << "Car brand : " << itr->second[i].brand << '\n';
                    cout << "Car model : " << itr->second[i].model << '\n';
                    cout << "Car year: " << itr->second[i].year << '\n';
                    cout << "Car milage :" << itr->second[i].mileage << '\n';
                    cout << "**********************************" << '\n';
                }
            }
        }
        break;
        case '7':
        {
            map<int, vector<vehicle>> filteryear;
            for (int i = 0; i < M.size(); i++)
            {
                filteryear[M[i].year].push_back(M[i]);
            }
            int a;
            cout << "Enter the year : " << '\n';
            cin >> a;
            map<int, vector<vehicle>>::iterator itr;
            for (itr = filteryear.begin(); itr != filteryear.end(); itr++)
            {

                for (int i = 0; i < itr->second.size(); i++)
                {
                    if (a != itr->second[i].year)
                    {
                        continue;
                    }
                    cout << "************************************" << '\n';
                    cout << "Brand : " << itr->second[i].brand << '\n';
                    cout << "Model : " << itr->second[i].model << '\n';
                    cout << "Year : " << itr->second[i].year << '\n';
                    cout << "Mileage : " << itr->second[i].mileage << '\n';
                    cout << "*************************************" << '\n';
                }
            }
            break;
        }
        case '8':
        {
            break;
        }
        default:
            cout << "Returning to the main menu..." << '\n';
            break;
        }
    } while (choice != 9);
}