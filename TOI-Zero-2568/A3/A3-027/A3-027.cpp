#include <iostream>
#include <vector>

int main() {
    int n, m;

    std::cin >> n >> m;

    std::vector<std::vector<char>> preMatrix(n, std::vector<char>(m));

    for (int i = 0; i < n; i++) {
        for (int y = 0; y < m; y++) {
            std::cin >> preMatrix[i][y];
        }
    }

    std::vector<std::vector<char>> postMatrix(n, std::vector<char>(m));

    postMatrix = preMatrix;

    for (int i = 0; i < n; i++) {
        for (int y = 0; y < m; y++) {
            if (preMatrix[i][y] == '*') {
                if (i + 1 < n) {
                    postMatrix[i + 1][y] = '*';
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int y = 0; y < m; y++) 
            std::cout << postMatrix[i][y] << ' ';
        std::cout << std::endl;
    }

    return 0;
}