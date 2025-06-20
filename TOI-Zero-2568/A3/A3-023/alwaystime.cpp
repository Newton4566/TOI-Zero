#include <iostream>
#include <chrono>

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int start, end;
    std::cin >> start >> end;
    long long count = 0;

    auto startTime = std::chrono::high_resolution_clock::now();

    for (int x = start; x <= end; x++) {
        for (int y = x; y <= end; y++) {
            for (int z = y; z <= end; z++) {
                if (x == y && y == z) continue;
                if (isPrime(x + y + z)) {
                    count++;
                }
            }
        }
        auto endtime = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(endtime - startTime);
        std::cout << "Current count: " << count << ", Elapsed time: " << duration.count() << " milliseconds\r";
    }
    

    auto endTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);

    std::cout << "\rTotal count: " << count << std::endl;
    std::cout << "\rTotal elapsed time: " << duration.count() << " milliseconds" << std::endl;

    return 0;
}