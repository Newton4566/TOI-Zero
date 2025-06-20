#include <iostream>

int main() {
    int month, day;

    std::cin >> month;
    std::cin >> day;

    if (month % 3 == 0 && day >= 21) {
        switch (month) {
            case 3:
                std::cout << "spring";
                break;
            case 6:
                std::cout << "summer";
                break;
            case 9:
                std::cout << "fall";
                break;
            case 12:
                std::cout << "winter";
                break;
        }
    } else if (month % 3 == 0 && day < 21) {
        switch (month) {
            case 3:
                std::cout << "winter";
                break;
            case 6:
                std::cout << "spring";
                break;
            case 9:
                std::cout << "summer";
                break;
            case 12:
                std::cout << "fall";
                break;
        }
    } else {
        switch (month) {
            case 1:
            case 2:
                std::cout << "winter";
                break;
            case 4:
            case 5:
                std::cout << "spring";
                break;
            case 7:
            case 8:
                std::cout << "summer";
                break;
            case 10:
            case 11:
                std::cout << "fall";
                break;
        }
    }
}