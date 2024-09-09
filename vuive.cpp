#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    string key;
    int dp[10][2][10];
public:
    

    int magic(int i, bool tight, int cnt) {
        if (i == key.size()) return cnt;
        if (dp[i][tight][cnt] != -1) return dp[i][tight][cnt];
        int ans = 0;
        int en = tight ? key[i]-'0' : 9; 
        for (int digit = 0; digit <= en; digit++) {
            ans += magic(i+1, tight & (digit == en), cnt+(digit==1));
        }
        return dp[i][tight][cnt] = ans;
    }

    int brute(int n) {
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            int tmp = i;
            while (tmp) {
                ans += (tmp%10==1);
                tmp/=10;
            }
        }
        return ans;
    } 

    int countDigitOne(int n) {
        key = to_string(n);
        memset(dp,-1,sizeof(dp));
        return magic(0, 1, 0);
    }

    void debug() {
        for (int i = 1; i <= 1000; i++) {
            if (brute(i) != countDigitOne(i)) {
                cout << brute(i) << " != " << countDigitOne(i) << " -> " <<  i << "\n";
                break;
            }
            if (i==1000) cout << "correct\n";
        }
    }
};

signed main() {
    Solution hehe;
    freopen("input.inp","r", stdin);
    int n; cin >> n;
    hehe.debug();
    return 0;
}

