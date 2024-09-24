#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        if (x == 0) return 0;
        long long tmp = 0;
        bool negative = (x < 0);
        x = abs(x);
        while (x > 0) {
            tmp = tmp*10 + x%10;
            x/=10;
        }        
        if (negative) tmp *= -1;
        while (tmp%10 == 0) tmp/=10;
        return ((tmp > INT_MAX || tmp < INT_MIN)) ? 0 : (int)tmp;
    }
};