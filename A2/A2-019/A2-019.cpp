#include <iostream>
#include <string>
using namespace std;

int main() {
    string input;
    cin >> input;
    
    // Convert to uppercase
    for (char &c : input) {
        c = toupper(c);
    }
    
    int len = input.length();
    
    // Case 1: Check if string contains "BUU"
    for (int i = 0; i < len - 2; i++) {
        if (input[i] == 'B' && input[i + 1] == 'U' && input[i + 2] == 'U') {
            // Count consecutive U's after BUU
            int uCount = 2;  // Start with 2 for the UU in BUU
            for (int j = i + 3; j < len && input[j] == 'U'; j++) {
                uCount++;
            }
            cout << "Yes " << uCount << endl;
            return 0;
        }
    }
    
    // Case 2: If no BUU found, find first B and append U's
    for (int i = 0; i < len; i++) {
        if (input[i] == 'B') {
            string result = input.substr(0, i + 1);  // Include up to and including B
            result += "UU";  // Add minimum UU
            cout << result << endl;
            return 0;
        }
    }
    
    // Case 3: If no B found, create new BUU string
    cout << "BUU" << endl;
    
    return 0;
}