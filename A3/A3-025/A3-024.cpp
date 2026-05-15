#include <iostream>
#include <vector>
#include <algorithm>


int main() {
    int N, L;

    std::cin >> N >> L;

    std::vector<std::pair<int, int>> range(N);

    for (int i = 0; i < N; i++) {
        std::cin >> range[i].first >> range[i].second;
    }

    std::sort(range.begin(), range.end(), [](auto &a, auto &b) {
        return a.second < b.second;
    });

    int checkpoints = 0;
    int last_checkpoint = -1;

    for (int i = 0; i < N; i++) {
        if (range[i].first > last_checkpoint) {
            last_checkpoint = range[i].second;
            checkpoints++;
        }
    }

    std::cout << checkpoints;
}