#include <iostream>
using namespace std;
class Student {
public:
    string name;
    int roll;
    int marks;
};

int main() {
    Student s[100];
    int n;

    cout << "Enter number of students: ";
    cin >> n;

    // Input
    for (int i = 0; i < n; i++) {
        cout << "\nEnter details for student " << i + 1 << endl;

        cout << "Name: ";
        cin >> s[i].name;

        cout << "Roll No: ";
        cin >> s[i].roll;

        cout << "Marks: ";
        cin >> s[i].marks;
    }

    // Display
    cout << "\n--- Student Records ---\n";
    for (int i = 0; i < n; i++) {
        cout << "\nStudent " << i + 1 << endl;
        cout << "Name: " << s[i].name << endl;
        cout << "Roll No: " << s[i].roll << endl;
        cout << "Marks: " << s[i].marks << endl;
    }

    return 0;
}
