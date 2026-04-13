#include <iosthttps://www.onlinegdb.com/#editor_1ream>
#include <vector>
#include <cmath>

using namespace std;

int add(vector<int> nums) {
    int sum = 0;
    for (int n : nums) sum += n;
    return sum;
}

int subtract(vector<int> nums) {
    int result = nums[0];
    for (int i = 1; i < nums.size(); i++)
        result -= nums[i];
    return result;
}

int multiply(vector<int> nums) {
    int result = 1;
    for (int n : nums) result *= n;
    return result;
}

long long factorial(int n) {
    if (n < 0) return -1;
    long long fact = 1;
    for (int i = 2; i <= n; i++)
        fact *= i;
    return fact;
}

double power(double base, int exp) {
    return pow(base, exp);
}

bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;
    return true;
}

int digitSum(int n) {
    int sum = 0;
    while (n != 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main() {

    int choice;

    do {
        cout << "\n=== Math Toolkit Menu ===\n";
        cout << "1. Addition\n";
        cout << "2. Subtraction\n";
        cout << "3. Multiplication\n";
        cout << "4. Factorial\n";
        cout << "5. Power\n";
        cout << "6. Prime Check\n";
        cout << "7. Digit Sum\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice >= 1 && choice <= 3) {
            int n;
            cout << "How many numbers? ";
            cin >> n;

            vector<int> nums(n);
            cout << "Enter numbers:\n";
            for (int i = 0; i < n; i++)
                cin >> nums[i];

            if (choice == 1)
                cout << "Result: " << add(nums) << endl;
            else if (choice == 2)
                cout << "Result: " << subtract(nums) << endl;
            else
                cout << "Result: " << multiply(nums) << endl;
        }

        else if (choice == 4) {
            int n;
            cout << "Enter number: ";
            cin >> n;
            cout << "Factorial: " << factorial(n) << endl;
        }

        else if (choice == 5) {
            double base;
            int exp;
            cout << "Enter base and exponent: ";
            cin >> base >> exp;
            cout << "Result: " << power(base, exp) << endl;
        }

        else if (choice == 6) {
            int n;
            cout << "Enter number: ";
            cin >> n;
            cout << (isPrime(n) ? "Prime Number" : "Not Prime") << endl;
        }

        else if (choice == 7) {
            int n;
            cout << "Enter number: ";
            cin >> n;
            cout << "Digit Sum: " << digitSum(n) << endl;
        }

    } while (choice != 0);

    cout << "Program Ended.\n";

    return 0;
}
