#include<bits/stdc++.h>
using namespace std;

void init_code() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}

const int N = 1e3;
int dp[N][N];

int unbounded_ks(int n, int s, int val[], int w[]) {
    if(n == 0 || s == 0) {
        return 0;
    }
    if(dp[n][s] != -1) {
        return dp[n][s];
    }
    if(w[n-1] <= s) {
        int op1 = val[n - 1] + unbounded_ks(n, s - w[n - 1], val, w);
        int op2 = unbounded_ks(n - 1, s, val, w);
        return dp[n][s] = max(op1, op2);
    } else {
        return dp[n][s] = unbounded_ks(n - 1, s, val, w);
    }
}

int main () {
    init_code();
    int n, s;
    cin >> n >> s;
    int val[n], w[n];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= s; j++) {
            dp[i][j] = -1;
        }       
    }

    for (int i = 0; i < n; i++) {
        cin >> val[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }

    cout << unbounded_ks(n, s, val, w);

    return 0;
}