#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    int sum = 0;
    int even_count = 0;
    int odd_count = 0;
    
    for (int i = 0; i < n; i++) {
        int stock;
        cin >> stock;
        sum += stock;
        
        if (stock % 2 == 0) {
            even_count++;
        } else {
            odd_count++;
        }
    }
    
    cout << "SUM " << sum << endl;
    cout << "EVEN " << even_count << endl;
    cout << "ODD " << odd_count << endl;
    
    return 0;
}