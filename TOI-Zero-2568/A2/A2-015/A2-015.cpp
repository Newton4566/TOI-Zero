#include <iostream>


int main() {
    int a, b, c, d;

    std::cin >> a >> b >> c;
    std::cin >> d;

    int aroundpicture = 2 * (a + b);

    int length = aroundpicture * c;

    std::cout << length << std::endl;
    std::cout << length * d << std::endl;

    return 0;
}