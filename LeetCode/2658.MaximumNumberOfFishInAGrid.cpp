#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool visited[12][12];
    int dx[4] = {0, 1,-1, 0};
    int dy[4] = {1, 0, 0,-1};
public:
    int bfs(vector<vector<int>>& grid, int i, int j, int n, int m) {
        if (i < 0 || i >= n || j < 0 || j >= m || visited[i][j]) return 0;
        int ans = grid[i][j];
        visited[i][j] = true;
        for (int g = 0; g < 4; g++) {
            ans += bfs(grid, i+dx[g], j+dy[g], n, m);
        }
        return ans;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) visited[i][j] = (!grid[i][j]);
        
        int ans = 0;
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
            if (!visited[i][j]) ans = max(ans, bfs(grid,i,j,n,m));
        }
        return ans;
    }
};
