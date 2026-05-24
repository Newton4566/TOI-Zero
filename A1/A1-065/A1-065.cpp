#include <iostream>
#include <vector>

int main() {
    std::vector<int> nums(5);
    for (int i = 0; i < 5; ++i) {
        if (!(std::cin >> nums[i])) {
            return 0;
        }
    }

    for (int n : nums) {
        if (n == 0) {
            std::cout << '-';
            continue;
        }

        int thousands = (n / 1000) % 10;
        int hundreds  = (n / 100) % 10;
        int tens      = (n / 10) % 10;
        int ones      = n % 10;

        if (thousands > 0) std::cout << '#';
        if (hundreds  > 0) std::cout << '/';
        if (tens      > 0) std::cout << '+';
        if (ones      > 0) std::cout << '*';
    }

    return 0;
}