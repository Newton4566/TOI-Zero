#include <iostream>
#include <string>

using namespace std;

int main() {
    string FirstName, LastName;

    cin >> FirstName >> LastName;

    cout << "Hello " << FirstName << " " << LastName << endl;
    cout << FirstName.substr(0, 2) << LastName.substr(0, 2) << endl;
    
    return 0;
}