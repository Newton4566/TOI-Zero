#include <iostream>

int main() {
    int age;
    char status;

    std::cin >> age;
    std::cin >> status;

    if (age <= 18 || status == 's' || status == 'S') {
        std::cout << "20" << std::endl;
    } else {
        std::cout << "50" << std::endl;
    }

    return 0;
}