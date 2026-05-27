#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<long long> X(n), Y(n);
    
    // Groups by (x - y) and (x + y)
    // For diagonal type 1: x-y same => side = |x2-x1|
    // For diagonal type 2: x+y same => side = |x2-x1|
    
    unordered_map<long long, pair<long long,long long>> diff_map; // key=x-y, value=(minX, maxX)
    unordered_map<long long, pair<long long,long long>> sum_map;  // key=x+y, value=(minX, maxX)
    
    long long ans = 0;
    
    for (int i = 0; i < n; i++) {
        cin >> X[i] >> Y[i];
        
        long long d = X[i] - Y[i];
        long long s = X[i] + Y[i];
        
        // Update diff_map
        if (diff_map.find(d) == diff_map.end()) {
            diff_map[d] = {X[i], X[i]};
        } else {
            long long minX = min(diff_map[d].first, X[i]);
            long long maxX = max(diff_map[d].second, X[i]);
            diff_map[d] = {minX, maxX};
            ans = max(ans, maxX - minX);
        }
        
        // Update sum_map
        if (sum_map.find(s) == sum_map.end()) {
            sum_map[s] = {X[i], X[i]};
        } else {
            long long minX = min(sum_map[s].first, X[i]);
            long long maxX = max(sum_map[s].second, X[i]);
            sum_map[s] = {minX, maxX};
            ans = max(ans, maxX - minX);
        }
    }
    
    cout << ans << endl;
    
    return 0;
}