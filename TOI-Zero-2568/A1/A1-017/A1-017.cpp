#include <iostream>

int main () {
    int y1, m1, d1;
    int y2, m2, d2;

    std::cin >> y1;
    std::cin >> m1;
    std::cin >> d1;

    std::cin >> y2;
    std::cin >> m2;
    std::cin >> d2;

    if (y1 == y2) {
        if (m1 == m2) {
            if (d1 == d2) {
                std::cout << 0;
            } else if (m1 < m2) {
                std::cout << 1;
            } else {
                std::cout << 2;
            }
        } else if (m1 < m2) {
            std::cout << 1;
        } else {
            std::cout << 2;
        }
    } else if (y1 < y2) {
        std::cout << 1;
    } else {
        std::cout << 2;
    }

    return 0;
}