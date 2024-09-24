#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int sum = 0;
    int a[15], b[15];
    int d1[(1<<15)]; 
    pair<int,int> d2[(1<<15)];
public:
    bool splitArraySameAverage(vector<int>& nums) {
        for (auto x : nums) sum += x;
        int n = nums.size()/2;
        int m = nums.size()-n;
        for (int i = 0; i < nums.size(); i++) {
            if (i < n) a[i] = nums[i];
            else b[i-n] = nums[i];
        }

        for (int mask = 0; mask < (1<<n); mask++) for (int i = 0; i < n; i++) if (mask & (1<<i)) d1[mask] +=a[i];
        for (int mask = 0; mask < (1<<m); mask++) {
            d2[mask].second = mask;
            for (int i = 0; i < m; i++) if (mask & (1<<i)) d2[mask].first +=b[i];
        }
        sort(d2, d2+(1<<m));
        for (int sz = 1; sz < nums.size()-1; sz++) {
            if ((sum*sz)%(n+m) != 0) {
                continue;
            }
            int sum1 = (sum*sz)/(n+m);
            for (int mask = 0; mask < (1<<n); mask++) {
                    int l = lower_bound(d2, d2+(1<<m), make_pair(sum1-d1[mask], 0)) - d2;
                    int r = upper_bound(d2, d2+(1<<m), make_pair(sum1-d1[mask], INT_MAX)) - d2 - 1;
                    
                    for (int n_mask = l; n_mask <= r; n_mask++) {
                        if (__builtin_popcount(d2[n_mask].second) + __builtin_popcount(mask) == sz) {
                            return true;
                        }
                    }
            }
        }
        return false;
    }
};