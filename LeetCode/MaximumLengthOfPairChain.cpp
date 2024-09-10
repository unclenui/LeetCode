#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int dp[1001] = {0};
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        sort(pairs.begin(), pairs.end());
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (pairs[j][1] < pairs[i][0]) {
                    dp[i] = max(dp[i], dp[j]+1);
                    ans = max(ans, dp[i]);
                }
            }
        }
        return ans+1;
    }
};