#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> f(10004, INT_MAX);
        f[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < n; j++) {
                if (i-coins[j]>=0) f[i] = min(f[i], f[i-coins[j]]+1);
            }
        }
        return (f[amount] = INT_MAX ? -1 : f[amount]);
    }
};

signed main() {
    Solution hehe;
    vector<int> tmp = {1, 2, 5};
    cout << hehe.coinChange(tmp, 11);
    return 0;
}

