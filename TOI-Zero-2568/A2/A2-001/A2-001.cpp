#include <iostream>
#include <vector>


//FUCK STATEMENT


int main() {
    int a, b;

    std::cin >> a >> b;

    std::vector<int> L1(a);
    std::vector<int> L2(b);

    for (int i = 0; i < a; i++) {
        std::cin >> L1[i];
    }

    for (int i = 0; i < b; i++) {
        std::cin >> L2[i];
    }

    int count = 1;

    for (int i = 0; i < a; i++) {
        int j = 0;

        while (j <= b) {
            if ((i + 1) < a && L1[i] < L2[j] && L1[i + 1] > L2[j]) {
                count++;
            }

            j++;
        }            
        std::cout << i << ' ' << count << std::endl;
    }

    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            if (L1[i] == L2[j] && (i / 2 == j / 2)) {
                count++;
            }
        }
    }


    std::cout << count << std::endl;
}