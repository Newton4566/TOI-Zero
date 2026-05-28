#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int base, bonus, days;
    if (!(cin >> base)) return 0;
    cin >> bonus >> days;

    int sum = base + bonus;
    int total = (days > 3) ? (sum * 3 / 2) : sum;

    int rank;
    if (total >= 1500) rank = 5;
    else if (total >= 1000) rank = 4;
    else if (total >= 500) rank = 3;
    else if (total >= 200) rank = 2;
    else rank = 1;

    int status;
    if (rank == 5 && days >= 7) status = 99;
    else if (rank == 4 && bonus > 300) status = 88;
    else status = 0;

    cout << total << '\n' << rank << '\n' << status << '\n';
    return 0;
}