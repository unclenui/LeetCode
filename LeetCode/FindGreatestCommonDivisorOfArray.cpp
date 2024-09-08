#include<bits/stdc++.h>
using namespace std;


class Solution {
private:
    int GCD(int a, int b) {
        return b ? GCD(b, a%b) : a;
    }
public:
    int findGCD(vector<int>& nums) {
        int l = INT_MAX, r = INT_MIN;
        for (auto x : nums) {
            l = min(l, x);
            r = max(r, x);
        }        
        return GCD(l,r);
    }
};