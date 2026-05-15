#include <iostream>


int main() {
    int a, b ,c;

    std::cin >> a;
    std::cin >> b;
    std::cin >> c;

    if (a == b && b == c) {
        std::cout << "all the same";
    } else {
        if (a != b && b != c && a != c) {
            std::cout << "all different";
        } else {
            std::cout << "neither";
        }
    }

    return 0;
}