#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    string key;
    int dp[(1<<10)][10][2][2][2];
public:
    int magic(int mask, int i, bool ld, bool tight, bool status) {
        if (i == key.size())  return status;
        if (dp[mask][i][ld][tight][status] != -1) return dp[mask][i][ld][tight][status];            
        int ans = 0;

        int en = tight ? key[i]-'0' : 9;
        for (int d = 0; d <= en; d++) {
            if (ld && d == 0) ans += magic(0, i+1, 1, 0, 0);
            else ans += magic(mask | (1<<d), i+1, 0, tight & (d==en), status | (mask & (1<<d)));
        }
        return dp[mask][i][ld][tight][status] = ans;
    }

    int numDupDigitsAtMostN(int n) {
        key = to_string(n);
        memset(dp,-1,sizeof(dp));
        return magic(0, 0, 1, 1, 0);
    }
};