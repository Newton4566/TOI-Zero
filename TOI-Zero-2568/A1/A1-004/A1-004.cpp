#include <iostream>

int main() {
    int fs[3] = {10, 40, 50};
    int numbers[3];

    for (int i = 0; i < 3; i++) {
        std::cin >> numbers[i];
    }

    if (numbers[0] >= fs[0] / 2 && numbers[1] >= fs[1] / 2 && numbers[2] >= fs[2] / 2) {
        std::cout << "pass";
    } else {
        std::cout << "fail";
    }

    return 0;
}