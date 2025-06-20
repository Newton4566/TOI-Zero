#include <iostream>
#include <vector>
#include <climits>

int main() {
    int N;
    std::cin >> N;

    std::vector<int> height(N);

    height[0] = INT_MAX;

    for (int i = 1; i <= N; i++) {
        std::cin >> height[i];
    }

    height[N] = INT_MAX;

    int count = 0;

    for (int i = 0; i < N; i++) {
        if (i > 0 && i < N - 1) {
            if (height[i] > height[i - 1] && height[i] > height[i + 1]) {
                count++;
            }
        }
    }

    std::cout << count << std::endl;

    return 0;
}