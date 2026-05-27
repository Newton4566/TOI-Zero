#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long W, H, M, N;
    cin >> W >> H >> M >> N;

    // Read vertical blade positions
    vector<long long> X(M);
    for (int i = 0; i < M; i++) cin >> X[i];

    // Read horizontal blade positions
    vector<long long> Y(N);
    for (int i = 0; i < N; i++) cin >> Y[i];

    // Compute widths of vertical segments (gaps between cuts)
    // Boundaries: 0, X1, X2, ..., XM, W  =>  M+1 segments
    vector<long long> widths;
    long long prev = 0;
    for (int i = 0; i < M; i++) {
        widths.push_back(X[i] - prev);
        prev = X[i];
    }
    widths.push_back(W - prev);

    // Compute heights of horizontal segments (gaps between cuts)
    // Boundaries: 0, Y1, Y2, ..., YN, H  =>  N+1 segments
    vector<long long> heights;
    prev = 0;
    for (int i = 0; i < N; i++) {
        heights.push_back(Y[i] - prev);
        prev = Y[i];
    }
    heights.push_back(H - prev);

    // Sort descending to quickly find top-2
    sort(widths.begin(), widths.end(), greater<long long>());
    sort(heights.begin(), heights.end(), greater<long long>());

    // The largest piece area = max_width * max_height
    long long area1 = widths[0] * heights[0];

    // The second largest piece is the maximum of:
    //   (2nd largest width) * (largest height)   OR
    //   (largest width)     * (2nd largest height)
    long long area2;
    long long candidate1 = (widths.size() > 1) ? widths[1] * heights[0] : 0;
    long long candidate2 = (heights.size() > 1) ? widths[0] * heights[1] : 0;
    area2 = max(candidate1, candidate2);

    cout << area1 << " " << area2 << "\n";

    return 0;
}