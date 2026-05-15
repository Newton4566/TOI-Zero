#include <iostream>


int main() {
    int n;

    std::cin >> n;

    std::cout << '0' << std::endl;

    if (n >= 2) std::cout << "0 0\n";

    for (int i = 3; i < n; i++) {
        std::cout << "0 ";

        for (int y = 0; y < i - 2; y++) {
            std::cout << "1 ";
        }
        std::cout << '0' << std::endl;
    }

    if (n > 2) {
        for (int i = 0; i < n; i++) std::cout << "0 ";
    }

    return 0;
}