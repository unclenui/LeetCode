#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);
        ans[1].push_back(1);
        for (int row = 2; row <= numRows; row++) {
            ans[row].push_back(1);
            for (int i = 1; i < ans[row-1].size(); i++) 
                ans[row].push_back(ans[row-1][i-1]+ans[row-1][i]);
            ans[row].push_back(1);
        }
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < ans[i].size(); j++) cout << ans[i][j] << ' ';
            cout << '\n';
        }
        return ans;

    }
};

signed main() {
    Solution hehe;
    hehe.generate(6);
    return 0;
}

