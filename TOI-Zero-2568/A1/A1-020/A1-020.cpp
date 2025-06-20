#include <iostream>


int main() {
    int a, b, c;

    std::cin >> a;
    std::cin >> b;
    std::cin >> c;

    if (a < b && b < c) {
        std::cout << "increasing";
    } else if (a > b && b > c) {
        std::cout << "decreasing";
    } else {
        std::cout << "neither";
    }
    
    return 0;
}