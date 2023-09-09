#include<bits/stdc++.h>
using namespace std;

void init_code() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}

const int N = 1e7 + 5;
bool dp[N];

int main () {
    init_code();
    int t;
    cin >> t;
    while (t--) {
        memset(dp, false, sizeof(dp));
        int d;
        cin >> d;
        dp[1] = true;
        for (int i = 1; i <= d; i++) {
            if (dp[i]) {
                if (i + 3 <= d) {
                    dp[i + 3] = true;
                }
                if (i * 2 <= d) {
                    dp[i * 2] = true;
                }
            }
        }
        if (dp[d]) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
