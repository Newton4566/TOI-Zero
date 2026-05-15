#include <iostream>

using namespace std;

int main() {
    int CashAmount;

    cin >> CashAmount;

    cout << "10 = " << CashAmount / 10 << endl;
    cout << "5 = " << (CashAmount % 10) / 5 << endl;
    cout << "2 = " << ((CashAmount % 10) % 5) / 2<< endl;
    cout << "1 = " << (((CashAmount % 10) % 5) % 2) / 1 << endl; 

    return 0;
}