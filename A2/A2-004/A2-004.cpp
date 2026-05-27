#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    // Count frequency of each bowl size
    // Bowl sizes are in range [1, 300]
    map<int, int> freq;
    for (int i = 0; i < n; i++) {
        int size;
        cin >> size;
        freq[size]++;
    }

    // The minimum number of stacks needed equals the maximum frequency
    // of any single bowl size, because:
    // - Bowls with the same size cannot be placed in the same stack
    //   (each bowl on top must be strictly smaller than the one below)
    // - All other bowls can always be arranged optimally using greedy stacking
    int ans = 0;
    for (auto& [size, count] : freq) {
        ans = max(ans, count);
    }

    cout << ans << "\n";
    return 0;
}