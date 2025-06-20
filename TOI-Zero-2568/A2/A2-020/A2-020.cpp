#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


int calculateRounds(vector<int>& people, int N) {
    int rounds = 0;
    sort(people.begin(), people.end());

    int left = 0, right = N - 1;

    while (left <= right) {
        if (people[left] + people[right] <= 4) {
            left++;
        }

        right--;
        rounds++;
    }

    return rounds;
}


int main() {
    int N;
    cin >> N;

    vector<int> people(N);
    for (int i = 0; i < N; i++) {
        cin >> people[i];
    }

    cout << calculateRounds(people, N) << endl;

    return 0;
}