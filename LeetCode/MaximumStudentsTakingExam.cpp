#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool GoAwayCheater(int mask1, int mask2) { // | <-- 1  2 -->|
        for (int i = 0; i < 8 ; i++) {
            if (mask1 & (1<<i)) if (mask2 & (1<<i) || mask2 & (1<<(i+1))) return false;
            if (mask2 & (1<<i)) if (mask1 & (1<<i) || mask1 & (1<<(i+1))) return false;
        }
        return true;
    }

    int DynamicDestroyer(vector<vector<int>> &dp, vector<int> &rows, int sz, int mask, int i) {
        if (i==sz) return dp[mask][i] = 0;
        if (dp[mask][i] != -1) return dp[mask][i];
        int ans = DynamicDestroyer(dp, rows, sz, 0, i+1);
        for (int n_mask = rows[i]; n_mask > 0; n_mask = (n_mask-1) & rows[i]) {
            if (GoAwayCheater(mask, n_mask)) {
                ans = max(ans, DynamicDestroyer(dp, rows, sz, n_mask, i+1) + __builtin_popcount(n_mask));
            }
        }

        return dp[mask][i] = ans;
    }

    int maxStudents(vector<vector<char>>& seats) {
        int n = seats.size();
        int m = seats[0].size();
        vector<int> rows(m+2);
        vector<vector<int>> dp((1<<10), vector<int>(10, -1));
        for (int j = 0; j < m; j++) 
            for (int i = n-1; i >= 0; i--)
                if (seats[i][j] != '#') rows[j+1] |= (1<<i);  
        return DynamicDestroyer(dp, rows, rows.size()-1, 0, 1);
    }
};