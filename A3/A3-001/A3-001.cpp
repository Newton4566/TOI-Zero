#include <bits/stdc++.h>
using namespace std;

// Use fractions to avoid floating point precision issues
struct Frac {
    long long num, den;
    Frac(long long n = 0, long long d = 1) {
        long long g = __gcd(abs(n), abs(d));
        num = n / g;
        den = d / g;
    }
    Frac operator+(const Frac& o) const { return Frac(num * o.den + o.num * den, den * o.den); }
    Frac operator-(const Frac& o) const { return Frac(num * o.den - o.num * den, den * o.den); }
    Frac operator*(long long k)   const { return Frac(num * k, den); }
    bool operator<(const Frac& o) const { return num * o.den < o.num * den; }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> A(N+1), L(N+1), B(N+1), R(N+1);
    for (int i = 1; i <= N; i++)
        cin >> A[i] >> L[i] >> B[i] >> R[i];

    // Process bottom-up (N down to 1); children always have higher indices
    vector<Frac> min_total(N+1), total_added(N+1);

    for (int i = N; i >= 1; i--) {
        Frac left_w, left_added, right_w, right_added;

        if (A[i] == 1) {
            left_w = Frac(L[i]);
            left_added = Frac(0);
        } else {
            left_w     = min_total[L[i]];
            left_added = total_added[L[i]];
        }

        if (B[i] == 1) {
            right_w = Frac(R[i]);
            right_added = Frac(0);
        } else {
            right_w     = min_total[R[i]];
            right_added = total_added[R[i]];
        }

        Frac target = (left_w < right_w) ? right_w : left_w;
        Frac added_here = (target - left_w) + (target - right_w);

        min_total[i]   = target * 2;
        total_added[i] = left_added + right_added + added_here;
    }

    // Answer is guaranteed to be a whole number
    cout << total_added[1].num / total_added[1].den << "\n";
    return 0;
}