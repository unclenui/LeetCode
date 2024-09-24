#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int dp[(1<<15)][15];
public:
    int magic(int mask, int cnt, int n) {
        if (mask == (1<<n)-1) return 1;
        if (dp[mask][cnt] != -1) return dp[mask][cnt];
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (!(mask & (1<<i)) && (max(cnt,i)+1)%(min(cnt,i)+1)==0) ans += magic(mask|(1<<i), cnt+1, n); 
        }
        return dp[mask][cnt] = ans;
    }
    int countArrangement(int n) {
        memset(dp,-1,sizeof(dp));
        return magic(0, 0, n);
    }
};
