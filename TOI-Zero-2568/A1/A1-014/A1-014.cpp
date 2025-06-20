#include <iostream>


int main() {
    int a, b, c;

    std::cin >> a;
    std::cin >> b;
    std::cin >> c;

    int min = a;
    if (b < min) min = b;
    if (c < min) min = c;

    std::cout << min << std::endl;
    return 0;
}