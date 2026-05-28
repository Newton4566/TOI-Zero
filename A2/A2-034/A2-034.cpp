#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

bool isPrime(int n) {
    if (n < 2) return false;
    for (int p = 2; p <= (int)sqrt((double)n); p++) {
        if (n % p == 0) return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;

    if (isPrime(n)) {
        cout << "Yes" << endl;
        // List all primes from 2 to n
        bool first = true;
        for (int i = 2; i <= n; i++) {
            if (isPrime(i)) {
                if (!first) cout << " ";
                cout << i;
                first = false;
            }
        }
        cout << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}