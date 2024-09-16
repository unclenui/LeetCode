#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int return_left(string s) {
        int HH = (s[0]-'0')*10+(s[1]-'0');
        int MM = (s[3]-'0')*10+(s[4]-'0');
        return HH*60 + MM;
    }

    int return_right(string s) {
        int HH = (s[0]-'0')*10+(s[1]-'0');
        int MM = (s[3]-'0')*10+(s[4]-'0');
        return MM ? (24-HH-1)*60+(60-MM) : (24-HH)*60;
    }

    int return_mid(string s1, string s2) {
        return return_left(s2)-return_left(s1);
    }
public:
    int findMinDifference(vector<string>& timePoints) {
        sort(timePoints.begin(), timePoints.end());
        int n = timePoints.size();
        int ans = return_left(timePoints[0])+ return_right(timePoints[n-1]);
        for (int i = 1; i < timePoints.size(); i++) {
            ans = min(ans, return_mid(timePoints[i-1], timePoints[i]));
        }
        return ans;
    }
};