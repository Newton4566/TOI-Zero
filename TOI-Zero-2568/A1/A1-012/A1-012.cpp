#include <iostream>
#include <string>
#include <cmath>


int Reverse(int n) {
    int first = n / 10;
    int second = n % 10;

    return std::stoi(std::to_string(second) + std::to_string(first));
}


int main() {
    int a;
    char b;
    std::cin >> a;
    std::cin >> b;

    if (b == '+') {
        std::cout << std::to_string(a) << " + " << std::to_string(Reverse(a)) << " = ";
        std::cout << a + Reverse(a) << std::endl;
    } else {
        std::cout << std::to_string(a) << " * " << std::to_string(Reverse(a)) << " = ";
        std::cout << a * Reverse(a) << std::endl;
    }

    return 0;
}