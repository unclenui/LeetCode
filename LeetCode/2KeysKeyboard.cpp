
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSteps(int n) {
        vector<int> f(n+1, INT_MAX-1);
        f[1] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j+=i) {
                
                f[j] = min(f[i]+j/i, f[j]);
            }
        }
        return f[n];
    }
};