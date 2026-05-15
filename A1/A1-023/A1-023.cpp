#include <iostream>

using namespace std;

int main() {
    int temp;
    char unit;

    cin >> temp;
    cin >> unit;

    if (unit == 'C' || unit == 'c') {
    } else {
        temp = (temp - 32) * 5 / 9;
    }

    if (temp < 0) {
        cout << "solid";
    } else if (temp >= 0 && temp < 100) {
        cout << "liquid";
    } else {
        cout << "gas";
    }
}