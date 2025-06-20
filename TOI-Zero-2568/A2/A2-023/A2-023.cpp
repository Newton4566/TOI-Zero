#include <iostream>
#include <string>
#include <cctype>

int main() {
    std::string s;
    std::cin >> s;

    for (char& c : s) c = std::toupper(c);

    bool onlyIT = true;

    for (char c : s) {
        if (c != 'I' && c != 'T') {
            onlyIT = false;
            break;
        }
    }

    if (onlyIT) {
        std::cout << "unknown " << s.length() << std::endl;
        return 0;
    }

    int maxA = 0, curA = 0;

    for (size_t i = 0; i < s.length(); ++i) {
        char c = s[i];


        if (c != 'R' && c != 'A' && c != 'B' && c != 'I' && c != 'T') {
            std::cout << "no " << i << std::endl;
            return 0;
        }

        if (c == 'A') {
            if (i == 0 || (s[i - 1] != 'R' && s[i - 1] != 'A')) {
                std::cout << "no " << i << std::endl;
                return 0;
            }
            curA++;
            if (curA > maxA) maxA = curA;
        } else {
            curA = 0;
        }

        if (c == 'B') {
            if (i + 1 >= s.length() || (s[i + 1] != 'I' && s[i + 1] != 'T')) {
                std::cout << "no " << i << std::endl;
                return 0;
            }
        }
    }

    std::cout << "yes " << maxA << std::endl;
    return 0;
}
