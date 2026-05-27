#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long n;
    cin >> n;
    
    if (n == 1) {
        cout << 0 << endl;
        return 0;
    }
    
    // Find row r and column col (1-indexed from left) of room n
    // Row r: rooms r^2 (leftmost) down to (r-1)^2+1 (rightmost)
    long long r = (long long)ceil(sqrt((double)n));
    while (r * r < n) r++;
    long long col = r * r - n + 1; // 1 = leftmost in the row
    
    // BFS on (row, col) grid
    // Row r has 2r-1 columns
    // Adjacency:
    //   Same row:  (r, col±1)
    //   Row above: (r-1, col-1), (r-1, col)    [row r-1 has 2r-3 cols]
    //   Row below: (r+1, col),   (r+1, col+1)  [row r+1 has 2r+1 cols]
    
    map<pair<long long,long long>, long long> dist;
    queue<pair<long long,long long>> bfsq;
    
    dist[{r, col}] = 0;
    bfsq.push({r, col});
    
    while (!bfsq.empty()) {
        auto [cr, cc] = bfsq.front();
        bfsq.pop();
        long long d = dist[{cr, cc}];
        
        if (cr == 1 && cc == 1) {
            cout << d << endl;
            return 0;
        }
        
        vector<pair<long long,long long>> neighbors = {
            {cr,     cc - 1},  // left in same row
            {cr,     cc + 1},  // right in same row
            {cr - 1, cc - 1},  // upper-left
            {cr - 1, cc    },  // upper-right
            {cr + 1, cc    },  // lower-left
            {cr + 1, cc + 1}   // lower-right
        };
        
        for (auto [nr, nc] : neighbors) {
            if (nr < 1 || nc < 1 || nc > 2 * nr - 1) continue;
            if (!dist.count({nr, nc})) {
                dist[{nr, nc}] = d + 1;
                bfsq.push({nr, nc});
            }
        }
    }
    
    return 0;
}