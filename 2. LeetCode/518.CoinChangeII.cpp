#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int dp[5005] = {1};
        for (int i = 0; i < coins.size(); i++) 
            for (int j = 0; j <= amount; j++)
                if (dp[j] && j+coins[i] <= amount) dp[j+coins[i]]+= dp[j];
        return dp[amount];
    }
};