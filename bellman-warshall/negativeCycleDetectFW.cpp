#include<bits/stdc++.h>
using namespace std;

const int INF = 1e7;

void init_code() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}

int main () {
    init_code();

    int n, e;
    cin >> n >> e;

    int dis[n + 1][n + 1];

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dis[i][j] = INF;
            if(i == j) {
                dis[i][j] = 0;
            }
        }
    }

    while(e--) {
        int a, b, w;
        cin >> a >> b >> w;
        dis[a][b] = w;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if(dis[i][j] == INF) {
                cout << "INF" << " ";
            } else {
                cout << dis[i][j] << " ";;
            }
        }
        cout << endl;
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if(dis[i][k] + dis[k][j] < dis[i][j]) {
                    dis[i][j] = dis[i][k] + dis[k][j];
                }
            }
        }
    }

    cout << "Updated the Matrix" << endl;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if(dis[i][j] == INF) {
                cout << "INF" << " ";
            } else {
                cout << dis[i][j] << " ";
            }
        }
        cout << endl;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if(i == j && dis[i][j] < 0) {
                cout << "Negative Cycle Detected.";
            }
        }
    }

    return 0;
}