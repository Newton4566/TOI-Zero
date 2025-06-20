#include <iostream>
#include <string>
#include <vector>


int main() {
    std::vector<std::vector<bool>> matrix(5, std::vector<bool>(5, 0));

    for (short int i = 0; i < 5; i++) {
        short int temp1;
        short int temp2;
        short int temp3;
        short int temp4;
        short int temp5;

        std::cin >> temp1 >> temp2 >> temp3 >> temp4 >> temp5;

        matrix[i][0] = temp1;
        matrix[i][1] = temp2;
        matrix[i][2] = temp3;
        matrix[i][3] = temp4;
        matrix[i][4] = temp5;
    }

    std::vector<short int> abnormalPos = {0, 0};

    std::vector<short int> sumX = {0, 0, 0, 0, 0};
    std::vector<short int> sumY = {0, 0, 0, 0, 0};
    
    for (short int X = 0; X < 5; X++) {
        for (short int Y = 0; Y < 5; Y++) {
            sumX[X] += matrix[X][Y];
        }
    }

    for (short int Y = 0; Y < 5; Y++) {
        for (short int X = 0; X < 5; X++) {
            sumY[Y] += matrix[X][Y];
        }
    }

    for (short int i = 0; i < 5; i++) {
        if (abnormalPos[0] && abnormalPos[1]) {
            break;
        }

        if (!abnormalPos[0] && sumX[i] % 2 != 0) {
            abnormalPos[0] = i;
        }

        if (!abnormalPos[1] && sumY[i] % 2 != 0) {
            abnormalPos[1] = i;
        }
    }

    if (abnormalPos[0] == 0 && abnormalPos[1] == 0) {
        std::cout << -1 << ' ' << -1;
        return 1;
    }

    std::cout << abnormalPos[0] << ' ' << abnormalPos[1];

    return 0;
}