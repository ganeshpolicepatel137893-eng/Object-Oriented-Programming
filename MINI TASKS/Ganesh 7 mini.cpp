#include <iostream>
#include <fstream>
using namespace std;

// Student class
class Student {
public:
    int roll;
    char name[50];
    int marks;
    double fees;

    void input() {
        cout << "Enter Roll No: ";
        cin >> roll;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Marks: ";
        cin >> marks;
        cout << "Enter Fees: ";
        cin >> fees;
    }

    void display() {
        cout << "\nRoll No: " << roll
             << "\nName: " << name
             << "\nMarks: " << marks
             << "\nFees: " << fees << endl;
    }
};

int main() {
    int choice;
    Student s;

    do {
        cout << "\n1. Add Student\n2. View Students\n3. Update Student\n4. Exit\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {
            ofstream fout("student.dat", ios::binary | ios::app);
            s.input();
            fout.write((char*)&s, sizeof(s));
            fout.close();
        }
        else if (choice == 2) {
            ifstream fin("student.dat", ios::binary);
            while (fin.read((char*)&s, sizeof(s))) {
                s.display();
            }
            fin.close();
        }
        else if (choice == 3) {
            fstream file("student.dat", ios::binary | ios::in | ios::out);
            int searchRoll;
            cout << "Enter Roll No to update: ";
            cin >> searchRoll;

            while (file.read((char*)&s, sizeof(s))) {
                if (s.roll == searchRoll) {
                    cout << "Enter new details:\n";
                    s.input();
                    file.seekp(-sizeof(s), ios::cur);
                    file.write((char*)&s, sizeof(s));
                    break;
                }
            }
            file.close();
        }

    } while (choice != 4);

    return 0;
}
