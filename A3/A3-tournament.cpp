#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, C;
    cin >> N >> C;
    
    // Read the tournament table (1-indexed)
    vector<vector<int>> table(N+1, vector<int>(N+1));
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> table[i][j];
        }
    }
    
    // Start with N teams in the bracket
    vector<int> bracket(N);
    for (int i = 0; i < N; i++) {
        bracket[i] = i + 1;  // Teams 1 to N
    }
    
    bool cardUsed = false;
    
    // Run tournament rounds
    while (bracket.size() > 1) {
        vector<int> nextRound;
        
        // Pair up adjacent teams and determine winners
        for (int i = 0; i < bracket.size(); i += 2) {
            int team1 = bracket[i];
            int team2 = bracket[i+1];
            
            int winner = table[team1][team2];
            
            // Check if the loser is team C and hasn't used the card yet
            int loser = (winner == team1) ? team2 : team1;
            if (loser == C && !cardUsed) {
                // Use the special card to reverse the result
                winner = loser;
                cardUsed = true;
            }
            
            nextRound.push_back(winner);
        }
        
        bracket = nextRound;
    }
    
    cout << bracket[0] << endl;
    
    return 0;
}
