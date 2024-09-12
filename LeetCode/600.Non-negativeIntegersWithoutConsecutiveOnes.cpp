#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    string key = "";
    int dp[31][2][2];
public:
    int magic(int i, bool tight, int pc) {
        if (i == 31) return 1;
        if (dp[i][tight][pc] != -1) return dp[i][tight][pc];
        int ans = 0;
        bool en = tight ? key[i]-'0' : 1;
        for (int d = 0; d <= en; d++) {
            if (pc == 0) {
                ans += magic(i+1, tight & (d==en), d);
            }
            else {
                if (d == 0) {
                    ans += magic(i+1, tight & (d==en), d);
                }
            }
        }
        return dp[i][tight][pc] = ans;
    }
    int findIntegers(int n) {
        bitset<31> bits(n);
        for (int i = 30; i >= 0; i--) {
            key += (bits[i]+'0');
        }
        memset(dp,-1,sizeof(dp));
        return magic(0,1,0);
    }
};
