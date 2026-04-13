#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n;

    cout << "===== SIMPLE BILL GENERATOR =====" << endl;
    cout << "How many items? ";
    cin >> n;

    string items[n];
    int qty[n];
    float price[n];
    float total[n];

    float grandTotal = 0;

    for(int i = 0; i < n; i++) {
        cout << "\nItem " << i + 1 << " name: ";
        cin >> items[i];

        cout << "Quantity: ";
        cin >> qty[i];

        cout << "Price per item: ";
        cin >> price[i];

        total[i] = qty[i] * price[i];
        grandTotal += total[i];
    }

    cout << fixed << setprecision(2);

    cout << "\n========== BILL ==========" << endl;
    cout << "Item\tQty\tPrice\tTotal" << endl;

    for(int i = 0; i < n; i++) {
        cout << items[i] << "\t" 
             << qty[i] << "\t" 
             << price[i] << "\t" 
             << total[i] << endl;
    }

    cout << "--------------------------" << endl;
    cout << "Grand Total: " << grandTotal << endl;

    return 0;
}
