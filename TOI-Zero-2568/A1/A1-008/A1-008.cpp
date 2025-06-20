#include <iostream>

int main() {
    std::string input;

    std::cin >> input;

    if (input.length() == 13) {
        std::cout << "yes";
    } else {
        std::cout << "no";
    }

    return 0;
}