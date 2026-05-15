#include <iostream>
#include <string>
#include <vector>


int main() {
    int M, N;

    std::cin >> N >> M;

    std::vector<std::string> matrix1(N);
    std::vector<std::string> matrix2(N);

    for (int i = 0; i < N; i++) {
        std::cin >> matrix1[i];
    }

    for (int i = 0; i < N; i++) {
        std::cin >> matrix2[i];
    }

    
    std::vector<std::vector<char>> chars1;
    std::vector<std::vector<char>> chars2;

    for (const std::string& str : matrix1) {
        chars1.push_back(std::vector<char>(str.begin(), str.end()));
    }

    for (const std::string& str : matrix2) {
        chars2.push_back(std::vector<char>(str.begin(), str.end()));
    }

    // processing...

    std::vector<std::vector<char>> result(N, std::vector<char>(M));

    for (int i = 0; i < N; i++) {
        for (int y = 0; y < M; y++) {
            char first = chars1[i][y];
            char second = chars2[i][y];

            if (first == second) {
                result[i][y] = '-';
            } else if ((first == '-' && second == '+') || first == '+' && second == '-') {
                result[i][y] = '+';
            } else if (first == '-' && second == 'x' || first == 'x' && second == '-'   ) {
                result[i][y] = 'x';
            } else {
                result[i][y] = '*'; 
            }
        }
    }

    //printing

    for (int i = 0; i < N; i++) {
        for (int y = 0; y < M; y++) {
            if (y < M - 1) {
                std::cout << result[i][y];
            } else {
                std::cout << result[i][y] << std::endl;
            }
        }
    }

    return 0;
}