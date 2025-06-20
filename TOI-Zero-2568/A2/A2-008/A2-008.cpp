#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> cars(N);

    for (int i = 0; i < N; ++i) {
        cin >> cars[i].first >> cars[i].second; // P, V
    }

    int max_eff = -1;
    int unsellable = 0;

    for (int i = N - 1; i >= 0; --i) {
        int V = cars[i].second;
        if (V <= max_eff) {
            ++unsellable;
        } else {
            max_eff = V;
        }
    }

    cout << unsellable << endl;
    
    return 0;
}