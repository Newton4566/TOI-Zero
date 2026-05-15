#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


vector<int> filterUniqueNumbers(const vector<int>& numbers) {
    vector<int> uniqueNumbers;

    for (int num : numbers) {
        if (find(uniqueNumbers.begin(), uniqueNumbers.end(), num) == uniqueNumbers.end()) {
            uniqueNumbers.push_back(num);
        }
    }
    return uniqueNumbers;
}

int main() {
    vector<int> inputNumbers(10);

    for (int i = 0; i < 10; i++) {
        cin >> inputNumbers[i];
    }

    vector<int> result = filterUniqueNumbers(inputNumbers);

    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}