#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Event {
    int position;
    int type;
};

int maxBridgesOverlap(int L, int N, vector<pair<int, int>> &bridges) {
    vector<Event> events;

    for (const auto &bridge : bridges) {
        events.push_back({bridge.first, 1});
        events.push_back({bridge.second, -1});
    }

    sort(events.begin(), events.end(), [](const Event &a, const Event &b) {
        if (a.position == b.position) {
            return a.type < b.type;
        }
        return a.position < b.position;
    });

    int maxOverlap = 0;
    int currentOverlap = 0;

    for (const auto &event : events) {
        currentOverlap += event.type;
        maxOverlap = max(maxOverlap, currentOverlap);
    }

    return maxOverlap;
}

int main() {
    int L, N;
    cin >> L >> N;

    vector<pair<int, int>> bridges(N);

    for (int i = 0; i < N; i++) {
        cin >> bridges[i].first >> bridges[i].second;
    }

    int result = maxBridgesOverlap(L, N, bridges);
    cout << result << endl;

    return 0;
}