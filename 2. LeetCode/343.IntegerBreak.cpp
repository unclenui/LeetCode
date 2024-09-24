#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1, 1); 
        if (n <= 2) return 1;
        if (n == 3) return 2;
        dp[2] = 2;
        dp[3] = 3;
        for (int i = 4; i <= n; i++) {
            for (int j = 1; j <= 3; j++) {
                dp[i] = max(dp[i], dp[i-j]*j);
            }
        }
        return dp[n];
    }
};