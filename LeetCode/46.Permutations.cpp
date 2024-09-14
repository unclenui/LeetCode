#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int vuive(int n) {
        int ans = 1;
        while (n--) ans *= n;
        return ans;
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans(vuive(nums.size()));
        int n = 0;
        
        do {
            ans.push_back(nums);
        } while (next_permutation(nums.begin(), nums.end()));
        return ans;
    }
};
