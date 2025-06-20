#include <iostream>
#include <vector>


int main() {
    std::pair<char, std::string> a;
    std::pair<char, std::string> b;

    std::cin >> a.first >> a.second;
    std::cin >> b.first >> b.second;

    if (b.first == a.first) {
        if (b.second == a.second) {
            std::cout << "1000000" << std::endl;
            return 0;
        } else if (b.second.substr(4 - 2, 3) == a.second.substr(4 - 2, 3)) {
            std::cout << "2000" << std::endl;
            return 0;
        } else if (b.second.substr(4 - 1, 2) == a.second.substr(4 - 1, 2)) {
            std::cout << "1000" << std::endl;
            return 0;
        } else {
            std::cout << "20" << std::endl;
            return 0;
        }
    } else{
        if (b.second == a.second) {
            std::cout << "100000" << std::endl;
            return 0;
        } else if (b.second.substr(4 - 2, 3) == a.second.substr(4 - 2, 3)) {
            std::cout << "200" << std::endl;
            return 0;
        } else if (b.second.substr(4 - 1, 2) == a.second.substr(4 - 1, 2)) {
            std::cout << "100" << std::endl;
            return 0;
        } else {
            std::cout << "0" << std::endl;
            return 0;
        }
    }

    return 0;
}