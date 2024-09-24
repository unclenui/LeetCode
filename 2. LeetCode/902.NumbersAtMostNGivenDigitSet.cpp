#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    string key;
    int dp[10][2][2];
public:
    int magic(vector<string>& digits, int i, bool ld, bool tight) {
        if (i == key.size()) return 1;
        if (dp[i][ld][tight] != -1) return dp[i][ld][tight];
        int ans = ld ? magic(digits, i+1, 1, 0) : 0;
        int en = tight ? key[i]-'0' : 9;
        for (auto x : digits) {
            if (x[0]-'0' > en) break;
            ans += magic(digits, i+1, 0, tight & ((x[0]-'0')==en));
        }
        return dp[i][ld][tight] = ans;
    }
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        key = to_string(n);
        memset(dp,-1,sizeof(dp));
        return magic(digits, 0, 1, 1)-1;
    }
};  