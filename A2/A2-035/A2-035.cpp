#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n;
vector<string> a;
vector<string> current;
bool used[7];
int count_perm = 0;

void permute(int depth) {
    if (depth == n) {
        for (int i = 0; i < n; i++) {
            if (i > 0) cout << " ";
            cout << current[i];
        }
        cout << "\n";
        count_perm++;
        return;
    }

    // Try each element in original input order (DFS)
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            used[i] = true;
            current.push_back(a[i]);
            permute(depth + 1);
            current.pop_back();
            used[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    fill(used, used + n, false);
    permute(0);
    cout << count_perm << "\n";

    return 0;
}