#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
    int a1;
    std::cin >> a1;

    std::vector<std::string> name(a1);
    std::vector<int> weight(a1);

    for (int i = 0; i < a1; i++) {
        std::cin >> name[i] >> weight[i];
    }

    int a2 = 0;
    for (int i = 0; i < a1; i++) {
        if (weight[i] > 15) {
            a2++;
        }
    }

    std::cout << a2 << std::endl;

    auto fattest = std::max_element(weight.begin(), weight.end());
    int index = std::distance(weight.begin(), fattest);

    std::cout << name[index] << " " << weight[index] << std::endl;

    return 0;
}
