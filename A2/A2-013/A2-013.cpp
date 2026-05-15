#include <iostream>


int main() {
    char a;
    int b;

    char c;
    int d, e;

    std::cin >> a >> b;
    std::cin >> c >> d >> e;

    int result = 0;

    if (a == 'H') {
        result += b * 5;
    } else if (a == 'O') {
        result += b * 3;
    } else {
        result += b * 2;
    }

    if (c == 'R') {
        switch (d) {
            case 1:
                result += 12 * e;
                break;
            case 2:
                result += 18 * e;
                break;
            case 3:
                result += 25 * e;
                break;    
        }
    } else if (c == 'T') {
        switch (d) {
            case 1:
                result += 15 * e;
                break;
            case 2:
                result += 20 * e;
                break;
            case 3:
                result += 30 * e;
                break;    
        }
    } else {
        switch (d) {
            case 1:
                result += 10 * e;
                break;
            case 2:
                result += 15 * e;
                break;
            case 3:
                result += 20 * e;
                break;    
        }
    }

    std::cout << result;

    return 0;
}