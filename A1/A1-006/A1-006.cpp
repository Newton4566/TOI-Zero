#include <iostream>

int main() {
    int a, b;

    std::cin >> a;
    std::cin >> b;

    switch (a % b){
    case 0:
        std::cout << "yes";
        break;
    default:
        std::cout << "no";
        break;
    }

    return 0;
}