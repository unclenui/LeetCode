#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);
        ans[0].push_back(1);
        for (int row = 1; row < numRows; row++) {
            ans[row].push_back(1);
            for (int i = 1; i < ans[row-1].size(); i++) 
                ans[row].push_back(ans[row-1][i-1]+ans[row-1][i]);
            ans[row].push_back(1);
        }
        return ans;

    }
};