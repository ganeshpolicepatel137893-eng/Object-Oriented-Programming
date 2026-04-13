#include <iostream>
using namespace std;

class FuelStation
{
private:
    float petrolStock;
    float dieselStock;
    float petrolPrice;
    float dieselPrice;
    float totalSales;

public:
    FuelStation()
    {
        petrolStock = 1000;
        dieselStock = 1000;
        petrolPrice = 105;
        dieselPrice = 95;
        totalSales = 0;
    }

    void sellPetrol()
    {
        float liters;
        cout << "Enter Petrol in Liters: ";
        cin >> liters;

        if (liters <= petrolStock)
        {
            float cost = liters * petrolPrice;
            petrolStock = petrolStock - liters;
            totalSales = totalSales + cost;

            cout << "Petrol Sold Successfully\n";
            cout << "Amount: " << cost << endl;
        }
        else
        {
            cout << "Not enough petrol stock\n";
        }
    }

    void sellDiesel()
    {
        float liters;
        cout << "Enter Diesel in Liters: ";
        cin >> liters;

        if (liters <= dieselStock)
        {
            float cost = liters * dieselPrice;
            dieselStock = dieselStock - liters;
            totalSales = totalSales + cost;

            cout << "Diesel Sold Successfully\n";
            cout << "Amount: " << cost << endl;
        }
        else
        {
            cout << "Not enough diesel stock\n";
        }
    }

    void showStock()
    {
        cout << "Petrol Stock: " << petrolStock << " Liters\n";
        cout << "Diesel Stock: " << dieselStock << " Liters\n";
    }

    void showSales()
    {
        cout << "Total Sales: " << totalSales << endl;
    }
};

int main()
{
    FuelStation station;
    int choice;

    do
    {
        cout << "\nFuel Management System\n";
        cout << "1. Sell Petrol\n";
        cout << "2. Sell Diesel\n";
        cout << "3. Show Stock\n";
        cout << "4. Show Sales\n";
        cout << "5. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            station.sellPetrol();
            break;

        case 2:
            station.sellDiesel();
            break;

        case 3:
            station.showStock();
            break;

        case 4:
            station.showSales();
            break;

        case 5:
            cout << "Program End\n";
            break;

        default:
            cout << "Invalid choice\n";
        }

    } while (choice != 5);

    return 0;
}
