#include <iostream>
#include <vector>

int main() {
    int L;
    double N;
    
    std::cin >> L >> N;

    std::vector<int> pyramid(L);
    
    for (int i = 0; i < L; i++) {
        pyramid[i] = (i + 1) * (i + 1);
    }

    double remains = N;

    int layersRemains;

    for (int i = 0; i < L; i++) {
        remains -= pyramid[i];
        layersRemains = i;
        if (remains >= 0) {
            continue;
        } else {
            break;
        }
    }

    std::cout << L - layersRemains<< std::endl;
    
    return 0;
}