#include <iostream>


int main() {
    char a;
    int b;

    std::cin >> a;
    std::cin >> b;

    if (a == 'H' || b == 4567) {
        if (a != 'H') {
            std::cout << "safe locked - change char" << std::endl;
        } else if (b != 4567) {
            std::cout << "safe locked - change digit" << std::endl;
        } else {
            std::cout << "safe unlocked" << std::endl;
        }
    } else {
        std::cout << "safe locked" << std::endl;
    }

    return 0;
}