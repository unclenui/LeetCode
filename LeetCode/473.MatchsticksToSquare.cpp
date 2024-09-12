#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int sum = 0;
    int d[(1<<15)], dp[(1<<15)][4];
public:
    bool magic(int mask, int s, int n) {
        if (s==4) return mask == (1<<n)-1;
        if (dp[mask][s] != -1) return dp[mask][s];
        bool ans = 0;
        int r_mask = (((1<<n)-1)^mask);
        for (int n_mask = r_mask; n_mask > 0; n_mask = (n_mask-1) & r_mask) {
            if (d[n_mask] == sum/4) ans |= magic(mask|n_mask, s+1, n);
        }
        return dp[mask][s] = ans;
    }
    bool makesquare(vector<int>& matchsticks) {
        int n = matchsticks.size();
        memset(dp,-1,sizeof(dp));
        for (auto x : matchsticks) sum += x;
        for (int mask = 0; mask < (1<<n); mask++) {
            for (int i = 0; i < n; i++) {
                if (mask & (1<<i)) d[mask] += matchsticks[i];
            }
        }
        return magic(0, 0, n);
    }
};