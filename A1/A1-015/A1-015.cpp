#include <iostream>


int main() {
    std::string FirstName, LastName;
    int age;
    
    std::cin >> FirstName;
    std::cin >> LastName;
    std::cin >> age;
    
    if (FirstName.length() > 5 && LastName.length() > 5) {
        int number;
        while (age >= 10) {
            age = age % 10;
            number = age;
        }

        std::cout << FirstName.substr(0, 2) << LastName.substr(LastName.length() - 1, 1) << number << std::endl;
    } else {
        std::cout << FirstName.substr(0, 1) << age << LastName.substr(LastName.length() - 1, 1) << std::endl;
    }

    return 0;
}