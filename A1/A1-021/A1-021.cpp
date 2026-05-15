#include <iostream>

using namespace std;

int main() {
    int year;
    cin >> year;
    if (year >= 1582) {
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
            cout << "yes";
        } else {
            cout << "no";
        }
    } else {
        if (year % 4 == 0) {
            cout << "yes";
        } else {
            cout << "no";
        }
    }

    return 0;
}