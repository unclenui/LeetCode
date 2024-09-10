#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    long long p[200005], size[200005];
    void init(int n) {
        for (int i = 0; i <= n; i++) p[i] = i;
    }
    int get(int a) {
        return p[a] = (p[a] == a ? a : get(p[a]));
    }
    bool link(int a, int b) {
        if ((a=get(a)) == (b=get(b))) return true;
        if (size[a] < size[b]) swap(a, b);
        p[b] = a;
        size[a] += b;
        return false;
    }
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        init(n);
        for (auto x : edges) link(x[0], x[1]);
        return link(source,destination);
    }
};
