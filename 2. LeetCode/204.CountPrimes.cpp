#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int nums = 0;
    int prime[500000] = {};
    bool not_prime[5000005];
    void prime_sieve(int n) {
        not_prime[0] = not_prime[1] = true;
        for(int i = 2; i < n; i++) {
            if (!not_prime[i] && (long long) i*i <= n) {
                for (int j = i*i; j <= n; j += i) {
                    not_prime[j] = true;
                }
            }
            if(!not_prime[i]) prime[nums++] = i;
        }
    }
public:
    int countPrimes(int n) {
        prime_sieve(n);
        return nums;
    }
};