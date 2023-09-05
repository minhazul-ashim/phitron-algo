#include<bits/stdc++.h>
using namespace std;

void init_code() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}

const int N = 1e3 + 10;
int dp[N][N];

int main () {
    init_code();
    int n;
    cin >> n;
    int v[n];
    int w[n];

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }

    int s;
    cin >> s;

    for (int i = 0; i < n; i++) {
        if(i != 0) {
            continue;
        }
        for (int j = 0; j < s; j++) {
            if(i == 0 || j == 0) {
                dp[i][j] = 0;
            }
        }
    }

    int maximum = 0;

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < s; j++) {
            if(w[i-1] <= j) {
                int op1 = dp[i - 1][j - w[i - 1]] + v[i - 1];
                int op2 = dp[i - 1][j];
                dp[i][j] = max(op1, op2);
                if(maximum < dp[i][j]) {
                    maximum = dp[i][j];
                }
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    cout << maximum;

    return 0;
}