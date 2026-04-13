#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

// Function Template
template <typename T>
T safeDivide(T a, T b)
{
    if (b == 0)
        throw runtime_error("Division by zero");
    return a / b;
}

// Class Template
template <typename T>
class DataProcessor
{
private:
    vector<T> data;

public:
    void addData(T value)
    {
        data.push_back(value);
    }

    T getData(int index)
    {
        if (index < 0 || index >= data.size())
            throw out_of_range("Invalid index");
        return data[index];
    }

    void inputData()
    {
        int n;
        cout << "Enter number of elements: ";
        cin >> n;

        if (n <= 0)
            throw invalid_argument("Invalid size");

        for (int i = 0; i < n; i++)
        {
            T value;
            cout << "Enter value " << i + 1 << ": ";
            cin >> value;
            addData(value);
        }
    }

    void display() const
    {
        for (const auto &val : data)
            cout << val << " ";
        cout << endl;
    }
};

int main()
{
    try
    {
        int choice;
        cout << "Select Data Type:\n1. Integer\n2. Double\nChoice: ";
        cin >> choice;

        if (choice == 1)
        {
            DataProcessor<int> obj;
            obj.inputData();
            cout << "Stored Data: ";
            obj.display();

            int a, b;
            cout << "Enter two integers for division: ";
            cin >> a >> b;

            cout << "Result: " << safeDivide(a, b) << endl;
        }
        else if (choice == 2)
        {
            DataProcessor<double> obj;
            obj.inputData();
            cout << "Stored Data: ";
            obj.display();

            double a, b;
            cout << "Enter two numbers for division: ";
            cin >> a >> b;

            cout << "Result: " << safeDivide(a, b) << endl;
        }
        else
        {
            throw invalid_argument("Invalid choice");
        }
    }
    catch (invalid_argument &e)
    {
        cout << "Invalid Argument: " << e.what() << endl;
    }
    catch (runtime_error &e)
    {
        cout << "Runtime Error: " << e.what() << endl;
    }
    catch (out_of_range &e)
    {
        cout << "Out of Range: " << e.what() << endl;
    }
    catch (...)
    {
        cout << "Unknown Exception" << endl;
    }

    return 0;
}
