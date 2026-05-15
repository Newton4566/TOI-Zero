#include <iostream>

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

    for (int x = start; x <= end; x++) {
        for (int y = x; y <= end; y++) {
            for (int z = y; z <= end; z++) {
                if (x == y && y == z) continue;
                if (isPrime(x + y + z)) {
                    count++;
                }
            }
        }
    }
    std::cout << count << std::endl;

    return 0;
}