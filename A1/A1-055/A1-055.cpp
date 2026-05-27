#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    
    int total_price = a * 25 + b * 40 + c * 55;
    int total_items = a + b + c;
    
    int net_price;
    if (total_items >= 3) {
        net_price = (int)(total_price * 0.9);
    } else {
        net_price = total_price;
    }
    
    cout << net_price << endl;
    return 0;
}