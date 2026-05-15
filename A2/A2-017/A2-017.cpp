#include <iostream>


int main() {
    char a, b, c;
    int d;

    std::cin >> a >> b;
    std::cin >> c;

    if (c != 'N') {
        std::cin >> d;
    }

    int price = 0;

    if (a == 'S') {
        if (b == 'R') {
            price += 60;
        } else {
            price += 80;
        }
    } else if (a == 'M') {
        if (b == 'R') {
            price += 80;
        } else {
            price += 100;
        }
    } else {
        if (b == 'R') {
            price += 100;
        } else {
            price += 120;
        }
    }

    if (c == 'N') {
    } else if (c == 'P') {
        price += d * 15;
    } else {
        price += d * 10;
    }

    std::cout << price << std::endl;

    return 0;
}