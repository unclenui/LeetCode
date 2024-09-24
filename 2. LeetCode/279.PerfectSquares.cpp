#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, 0x3f3f3f); dp[0] = 0;
        for (int j = 0; j <= 100; j++) {
            for (int i = 1; i <= n; i++) {
                if (j*j > i) continue;
                dp[i] = min(dp[i-j*j]+1, dp[i]);
            }
        }
        for (int i = 1; i <= n; i++) cout << dp[i] << " ";
        return dp[n];
    }
};