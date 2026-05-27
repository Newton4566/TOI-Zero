#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<string> grid(N);
    for (int i = 0; i < N; i++) {
        cin >> grid[i];
    }

    // dp[i][j] = true if starting at (i,j) can reach bottom-right (N-1, N-1)
    // moving only DOWN or RIGHT
    // We compute this backwards from the goal.
    vector<vector<bool>> dp(N, vector<bool>(N, false));

    // Goal: bottom-right corner (always empty)
    dp[N-1][N-1] = true;

    // Fill last row (can only move right)
    for (int j = N-2; j >= 0; j--) {
        if (grid[N-1][j] != 'X') {
            dp[N-1][j] = dp[N-1][j+1];
        }
    }

    // Fill last column (can only move down)
    for (int i = N-2; i >= 0; i--) {
        if (grid[i][N-1] != 'X') {
            dp[i][N-1] = dp[i+1][N-1];
        }
    }

    // Fill rest of the grid bottom-up, right-to-left
    for (int i = N-2; i >= 0; i--) {
        for (int j = N-2; j >= 0; j--) {
            if (grid[i][j] != 'X') {
                // Can reach goal if going down or going right can reach goal
                dp[i][j] = dp[i+1][j] || dp[i][j+1];
            }
        }
    }

    // Count all valid starting positions
    int count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (dp[i][j]) {
                count++;
            }
        }
    }

    cout << count << "\n";

    return 0;
}