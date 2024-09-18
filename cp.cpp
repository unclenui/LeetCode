#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("input.inp","r",stdin);
    int n;
    long long s;
    cin >> n;
    for (s = 1; n > 0; n--) {
        if (n == 3) cout << s << '\n';
        s *= n;
        if (n == 3) cout << s << '\n';
    }
}