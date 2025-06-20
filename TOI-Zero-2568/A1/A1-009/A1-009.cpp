#include <iostream>

int main() {
    int a, b;

    std::cin >> a;
    std::cin >> b;

    std::cout << (a + b) << std::endl;

    if (a + b >= 50) {
        std::cout << "pass";
    } else {
        std::cout << "fail";
    }


    return 0;
}