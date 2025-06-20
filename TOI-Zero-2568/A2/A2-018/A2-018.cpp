#include <iostream>
#include <vector>


int main() {
    std::vector<std::string> colors = {"Red", "Green", "Blue"};
    char I_color;
    int I_amount;
    
    int color;

    std::cin >> I_color >> I_amount;

    if (I_color == 'R') {
        color = 0;
    } else if (I_color == 'G') {
        color = 1;
    } else {
        color = 2;
    }   

    int y = color;

    for (int i = 0; i < I_amount; i++) {
        

        if (i != I_amount) {
            std::cout << colors[y] << ' ';
        } else {
            std::cout << colors[y];
        }

        y++;

        if (y > 2) {
            y = 0;
        }
    }

    return 0;
}