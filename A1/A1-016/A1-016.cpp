#include <iostream>


int main() {
    std::string input;

    std::cin >> input;

    if (input[2] == '1' && input[3] == '6') {
        std::cout << "yes" << std::endl;
    } else {
        std::cout << "no" << std::endl;
    }

    return 0;
}