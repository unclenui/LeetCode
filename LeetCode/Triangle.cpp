#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int MagicBacktrack(vector<vector<int>>& triangle, vector<vector<int>>& dp, vector<vector<bool>>& visited, int i, int j) {
        if (visited[i][j]) return dp[i][j];
        visited[i][j] = true;
        if (i == triangle.size()-1) return dp[i][j] = triangle[i][j];
        return dp[i][j] = triangle[i][j] + min(MagicBacktrack(triangle, dp, visited, i+1,j), MagicBacktrack(triangle, dp, visited, i+1, j+1));
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp = triangle;
        vector<vector<bool>> visited(triangle.size());
        for (int i = 0; i < triangle.size(); i++) {
            for (int j = 0; j <= i; j++) visited[i].push_back(0);
        }

        for (auto &x : dp) 
            for (auto &y : x) y = -1;
        return MagicBacktrack(triangle, dp, visited, 0, 0);
    }
};