#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& a, int target) {
        map<int,int> mp;
        int n = a.size();
        vector<vector<int>> ans;
        for (auto x : a) mp[x]++;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                for (int k = 0; k < j; k++) {
                    int val = target-a[i]-a[j]-a[k];
                    int tmp = mp[val];
                    if (a[i] == val) tmp--;
                    if (a[j] == val) tmp--;
                    if (a[k] == val) tmp--;
                    if (tmp > 0) ans.push_back({a[i], a[j], a[k], val});
                }
            }
        }
        return ans;
    }
};

signed main() {
    Solution hehe;
    return 0;
}

