#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void Detrack(vector<int>& arr, vector<bool>& visited, int status) {
        if (status < 0 || status >= visited.size()) return;
        if (visited[status]) return;
        visited[status] = true;
        Detrack(arr, visited, status + arr[status]);
        Detrack(arr, visited, status - arr[status]);
    }

    bool canReach(vector<int>& arr, int start) {
        vector<bool> visited(arr.size());
        Detrack(arr, visited, start);
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == 0 && visited[i]) return true;
        }
        return false;
    }
};