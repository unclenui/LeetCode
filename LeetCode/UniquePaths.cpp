#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> a(m, vector<int>(n));
        a[0][0] = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i+1 < m) a[i+1][j] += a[i][j];
                if (j+1 < n) a[i][j+1] += a[i][j];
            }
        }
        return a[m-1][n-1];
    }
};