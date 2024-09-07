#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    const int mod = 1e9 + 7;
    int dp[(1<<11)][41];
    int mark[41];
    int nums, n;
public:

    int comprise(vector<vector<int>>& hats) {
        vector<int> b;
        for (auto x : hats) for (auto y : x) b.push_back(y);
        sort(b.begin(), b.end());
        b.erase(unique(b.begin(), b.end()), b.end());
        for (auto &x : hats) for (auto &y : x) {
            y = lower_bound(b.begin(), b.end(), y) - b.begin();
        }
        return b.size();
    }

    int vuive(int mask, int i) {
        if (dp[mask][i] != -1) return dp[mask][i];
        if (!mask) return dp[0][i] = 1;
        if (i == nums) return 0;
        long long ans = vuive(mask, i+1);
        for (int j = 0; j < n; j++) {
            if ((mask & (1<<j)) && (mark[i] & (1<<j))) 
               (ans += vuive(mask ^ (1<<j), i+1)) %= mod;
        }
        return dp[mask][i] = (int)ans%mod;
    }

    int numberWays(vector<vector<int>>& hats) {
        n = hats.size();
        nums = comprise(hats);
        memset(dp,-1,sizeof(dp));
        for (int i = 0; i < n; i++) {
            for (auto x : hats[i]) mark[x] |= (1<<i);
        }
        return vuive((1<<n)-1,0);
    }
};

int n, m;

signed main() {
    Solution hehe;
    freopen("input.inp","r", stdin);
    vector<vector<int>> arr = {{3,4}, {4,5}, {5}};

                            //   {{1,4,5,6,8,9,10,11,12,14,16,17,18,19,20},
                            //    {1,2,7,8,11,14,18},
                            //    {1,4,6,7,8,13,14,15,17,18,19},
                            //    {1,4,5,6,7,8,10,12,14,15,17,18,19,20}};
    cout << hehe.numberWays(arr);
    return 0;
}

