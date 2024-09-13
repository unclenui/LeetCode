#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int preflix[30005] = {};
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        preflix[0] = arr[0];
        for (int i = 1; i < arr.size(); i++) preflix[i] = preflix[i-1]^arr[i];

        vector<int> ans(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            if (queries[i][0] == 0) ans[i] = preflix[queries[i][1]];
            else ans[i] = preflix[queries[i][0]-1]^preflix[queries[i][1]];
        }
        return ans;
    }
};

signed main() {
    Solution hehe;
    freopen("input.inp","r", stdin);
    vector<int> nums = {7,3,16,15,1,13,1,2,14,5,3,10,6,2,7,15};
    return 0;
} 

