#include <iostream>
#include <cctype>
using namespace std;

char getChar(char k, int dist) {
    if (k == '#') return '#';

    int start = k - 'A';
    int pos = start + dist;

    // เพิ่มไปจนถึง Z แล้วถอยกลับ
    if (pos <= 25) {
        return 'A' + pos;
    } else {
        return 'Z' - (pos - 25);
    }
}

int main() {
    int x;
    char k;

    cin >> x >> k;

    k = toupper(k);

    int mid1, mid2;

    // หาตำแหน่งกึ่งกลาง
    if (x % 2 == 1) {
        mid1 = mid2 = x / 2;
    } else {
        mid1 = x / 2 - 1;
        mid2 = x / 2;
    }

    for (int i = 0; i < x; i++) {
        // ระยะจากกึ่งกลาง
        int dist = min(abs(i - mid1), abs(i - mid2));

        int left = dist;
        int right = x - 1 - dist;

        char ch = getChar(k, dist);

        for (int j = 0; j < x; j++) {
            if (j == left || j == right)
                cout << ch;
            else
                cout << '-';
        }

        cout << endl;
    }

    return 0;
}
