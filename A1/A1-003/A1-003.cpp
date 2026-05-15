#include <iostream>

int main() {
    int numbers[3];

    for (int i = 0; i < 3; i++) {
        std::cin >> numbers[i];
    }

    int max = numbers[0];

    for (int i = 1; i < 3; ++i) {
        if (numbers[i] > max) {
            max = numbers[i];
        }
    }

    std::cout << max;

    return 0;
}