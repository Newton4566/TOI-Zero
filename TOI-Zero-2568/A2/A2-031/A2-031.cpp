#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>

int main() {
    int amount;

    std::cin >> amount;

    std::vector<char> DNA1(amount);
    std::vector<char> DNA2(amount);

    for (int i = 0; i < amount; i++) {
        std::cin >> DNA1[i];
    }

    for (int i = 0; i < amount; i++) {
        std::cin >> DNA2[i];
    }

    int amountOfChanges;

    std::cin >> amountOfChanges;

    for (int i = 0; i < amountOfChanges; i++) {
        int whichDNA;
        int index;
        char newChar;

        std::cin >> whichDNA >> index >> newChar;

        if (whichDNA == 1) {
            DNA1[index] = newChar;
        } else {
            DNA2[index] = newChar;
        }
    }

    for (int i = 0; i < amount; i++) {
        std::cout << DNA1[i] << ' ';
    }

    std::cout << std::endl;

    for (int i = 0; i < amount; i++) {
        std::cout << DNA2[i] << ' ';
    }

    std::cout << std::endl;

    int count = 0;

    for (int i = 0; i < amount; i++) {
        if ((DNA1[i] == 'A' && DNA2[i] == 'T') || (DNA1[i] == 'C' && DNA2[i] == 'G') || (DNA1[i] == 'T' && DNA2[i] == 'A') || (DNA1[i] == 'G' && DNA2[i] == 'C')) {
            continue;
        } else {
            count++;
        }    
    }

    std::cout << count;

    return 0;
}