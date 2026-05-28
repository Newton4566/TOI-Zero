#include <iostream>
#include <string>
#include <cstdlib>

int main() {
    std::string s;
    if (!(std::cin >> s)) {
        return 0;
    }

    int x = 0;
    int y = 0;
    for (char c : s) {
        switch (c) {
            case 'N': y += 1; break;
            case 'S': y -= 1; break;
            case 'E': x += 1; break;
            case 'W': x -= 1; break;
            default: break;
        }
    }

    int d = std::abs(x) + std::abs(y);
    std::cout << x << " " << y << " " << d;
    return 0;
}
