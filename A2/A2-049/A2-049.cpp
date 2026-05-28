#include <iostream>
using namespace std;

int main() {
    int A[3][3], B[3][3], C[3][3];
    const int MOD = 32777; // 2^15 + 9
    
    // Read matrix A (3x3)
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cin >> A[i][j];
        }
    }
    
    // Read matrix B (3x3)
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cin >> B[i][j];
        }
    }
    
    // Matrix multiplication with modulo
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            long long sum = 0;
            for(int k = 0; k < 3; k++) {
                sum += (long long)A[i][k] * B[k][j];
            }
            // Apply modulo with non-negative result
            C[i][j] = ((sum % MOD) + MOD) % MOD;
        }
    }
    
    // Output result matrix (3x3)
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(j > 0) cout << " ";
            cout << C[i][j];
        }
        cout << "\n";
    }
    
    return 0;
}
