#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> a(n); a[0] = cost[0], a[1] = cost[1];
        for (int i = 2; i < n; i++) a[i] = min(a[i-1], a[i-2]) + cost[i];
        return min(a[n-2], a[n-1]);
    }
};