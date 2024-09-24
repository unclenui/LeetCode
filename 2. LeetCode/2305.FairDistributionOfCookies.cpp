#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int dp[(1<<8)][8][(1<<8)]; 
    int d[(1<<8)] = {};
public:
    int magic(int k, int mask, int i, int track) {
        if (i == k) {
            if (mask == 0) return d[track];
            return INT_MAX;
        }    
        if (dp[mask][i][track] != -1) return dp[mask][i][track]; 
        int ans = INT_MAX;
        for (int n_mask = mask; n_mask > 0; n_mask = (n_mask-1) & mask) {
            ans = min(ans, magic(k, mask - n_mask, i+1, d[n_mask]>d[track] ? n_mask : track));
        }
        return dp[mask][i][track] = ans;
    }
    int distributeCookies(vector<int>& cookies, int k) {
        for (int mask = 0; mask < (1<<cookies.size()); mask++) {
            for (int i = 0; i < cookies.size(); i++) {
                if (mask & (1<<i)) d[mask] += cookies[i];
            }
        }
        memset(dp,-1,sizeof(dp));
        return magic(k, (1<<cookies.size())-1, 0, 0);
    }
};