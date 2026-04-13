#include <iostream>
#include <string>
using namespace std;

// Base Class
class Employee {
protected:
    string name;
    double salary;
    int absentDays;

public:
    virtual void input() {
        cout << "Enter Employee Name: ";
        cin.ignore();
        getline(cin, name);

        cout << "Enter Base Salary: ";
        cin >> salary;

        cout << "Enter Absent Days (500 Rs per day deduction): ";
        cin >> absentDays;
    }

    virtual double calculateSalary() {
        return salary - (absentDays * 500);
    }

    virtual void display() {
        cout << "\nEmployee Name: " << name << endl;
        cout << "Final Salary: " << calculateSalary() << endl;
    }
};

// Derived Class 1
class Manager : public Employee {
private:
    double bonus;

public:
    void input() {
        Employee::input();
        cout << "Enter Manager Bonus: ";
        cin >> bonus;
    }

    double calculateSalary() {
        return (salary + bonus) - (absentDays * 500);
    }

    void display() {
        cout << "\n--- Manager Details ---" << endl;
        Employee::display();
    }
};

// Derived Class 2
class Developer : public Employee {
private:
    double overtime;

public:
    void input() {
        Employee::input();
        cout << "Enter Overtime Pay: ";
        cin >> overtime;
    }

    double calculateSalary() {
        return (salary + overtime) - (absentDays * 500);
    }

    void display() {
        cout << "\n--- Developer Details ---" << endl;
        Employee::display();
    }
};

// Derived Class 3
class Clerk : public Employee {
public:
    void display() {
        cout << "\n--- Clerk Details ---" << endl;
        Employee::display();
    }
};

// Main
int main() {
    Employee* emp[50];
    int n, choice;

    cout << "Enter number of employees: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "\nSelect Job Role";
        cout << "\n1. Manager";
        cout << "\n2. Developer";
        cout << "\n3. Clerk";
        cout << "\nEnter choice: ";
        cin >> choice;

        if (choice == 1)
            emp[i] = new Manager();
        else if (choice == 2)
            emp[i] = new Developer();
        else
            emp[i] = new Clerk();

        emp[i]->input();
    }

    cout << "\n\n===== PAYROLL OUTPUT =====\n";

    for (int i = 0; i < n; i++) {
        emp[i]->display();
    }

    return 0;
}
