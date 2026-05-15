#include <iostream>

using namespace std;

int main() {
    char input;
    char vowels[5] = {'a', 'e', 'i', 'o', 'u'};

    cin >> input;

    if (input == vowels[0] || input == vowels[1] || input == vowels[2] || input == vowels[3] || input == vowels[4]) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }

    return 0;
}