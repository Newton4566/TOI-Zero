#include <iostream>
#include <string>

using namespace std;

int main() {
    int age;
    string day;
    int price;

    cin >> age >> day;
    
    if (age < 5) {
        price = 0;
    } else if (age <= 18) {
        price = 100;
    } else {
        price = 150;
    }

    if (day == "Wed") {
        price /= 2;
    }

    cout << price << endl;

    return 0;
}