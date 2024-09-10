#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool visited[301][301];
    int dx[4] = {0, 1,-1, 0};
    int dy[4] = {1, 0, 0,-1};
public:
    void bfs(vector<vector<char>>& grid, int i, int j, int n, int m) {
        if (i < 0 || i >= n || j < 0 || j >= m || visited[i][j]) return;
        visited[i][j] = true;
        for (int g = 0; g < 4; g++) {
            bfs(grid, i+dx[g], j + dy[g], n, m);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i < n; i++)        
            for (int j = 0; j < m; j++)  if (grid[i][j] =='0') visited[i][j] = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j]) {
                    ans++;
                    bfs(grid,i,j,n,m);
                }
            }
        }
        return ans;
    }
};