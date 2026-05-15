#include <iostream>
#include <vector>
#include <string>

int main() {
    int n;

    std::cin >> n;

    std::string a, b;

    std::cin >> a;
    std::cin >> b;

    bool yes = true;

    int howMany = 0;

    for (int i = 0; i < n; ++i) {
        if (a[i] - '0' + b[i] - '0' == 9) {
                continue;
        } else {
            yes = false;
            howMany++;
        }
    }

    if (yes == true) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << ' ' << howMany << std::endl;

    }

    return 0;
}
