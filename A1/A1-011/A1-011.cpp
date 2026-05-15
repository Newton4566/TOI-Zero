#include <iostream>
#include <string>


int main() {
    std::string input;
    std::string output = "";

    std::cin >> input;

    int i = 0;
    while (i < input.length()) {
        char currentChar = input[i];
        int count = 1;

        while (i + 1 < input.length() && input[i] == input[i + 1]) {
            count++;
            i++;
        }

        output += std::to_string(count) + currentChar;
        i++;
    }   

    std::cout << output << std::endl;

    return 0;
}
