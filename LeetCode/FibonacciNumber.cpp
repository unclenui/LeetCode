#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int fib(int n) {
        int a[31] = {0, 1};
        for (int i = 2; i <= n; i++) a[i] = a[i-1] + a[i-2];
        return a[n];
    }
};