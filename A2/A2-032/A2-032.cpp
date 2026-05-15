#include <iostream>
#include <vector>

int main() {
    int n, m;
    int amountOfPokemon;

    std::cin >> n >> m;
    std::cin >> amountOfPokemon;

    std::vector<std::pair<int, int>> whereIsPokemon(amountOfPokemon);

    for (int i = 0; i < amountOfPokemon; ++i) {
        int x, y;
        std::cin >> x >> y;
        whereIsPokemon[i] = {x, y};
    }

    std::vector<std::vector<unsigned short int>> matrix(n, std::vector<unsigned short int>(m, 0));

    for (int i = 0; i < amountOfPokemon; ++i) {
        int x = whereIsPokemon[i].first;
        int y = whereIsPokemon[i].second;
        matrix[x][y] += 1;
    }

    std::vector<std::pair<int, int>> whereToCheck;
    whereToCheck.reserve((n * m) - amountOfPokemon);

    for (int X = 0; X < n; ++X) {
        for (int Y = 0; Y < m; ++Y) {
            if (!matrix[X][Y]) {
                whereToCheck.push_back({X, Y});
            }
        }
    }

    int best = 0;

    for (int X = 0; X < n; ++X) {
        for (int Y = 0; Y < m; ++Y) {
            int count = 0;

            if (X > 0 && Y > 0 && matrix[X - 1][Y - 1]) count += matrix[X - 1][Y - 1];
            if (X > 0 && matrix[X - 1][Y]) count += matrix[X - 1][Y];
            if (X > 0 && Y < m - 1 && matrix[X - 1][Y + 1]) count += matrix[X - 1][Y + 1];
            if (Y > 0 && matrix[X][Y - 1]) count += matrix[X][Y - 1];
            if (Y < m - 1 && matrix[X][Y + 1]) count += matrix[X][Y + 1];
            if (X < n - 1 && Y > 0 && matrix[X + 1][Y - 1]) count += matrix[X + 1][Y - 1];
            if (X < n - 1 && matrix[X + 1][Y]) count += matrix[X + 1][Y];
            if (X < n - 1 && Y < m - 1 && matrix[X + 1][Y + 1]) count += matrix[X + 1][Y + 1];

            if (count > best) best = count;
        }
    }

    std::cout << best << std::endl;

    return 0;
}