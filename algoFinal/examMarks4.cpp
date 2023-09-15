#include<bits/stdc++.h>
using namespace std;

void init_code() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}

const int N = 1e9 + 7;

int main () {
    init_code();
    int t;
    cin >> t;
    while(t--) {
        int n, a;
        cin >> n >> a;
        int s = 1000 - a;
        int w[n];
        for (int i = 0; i < n; i++) {
            cin >> w[i];
        }
        int dp[n + 1][s + 1];
        dp[0][0] = 1;
        for (int i = 1; i <= s; i++) {
            dp[0][i] = 0;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= s; j++) {
                if(w[i-1] <= j) {
                    dp[i][j] = (dp[i][j - w[i - 1]] + dp[i - 1][j]) % N;
                } else {
                    dp[i][j] = dp[i - 1][j] % N;
                }
            }
        }
        cout << dp[n][s] << endl;
    }
    return 0;
}