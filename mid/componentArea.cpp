#include<bits/stdc++.h>
using namespace std;

#define pii pair<int, int>

const int N = 1000;
char adjMat[N][N];
bool visited[N][N];
int rows, cols;
vector<pii> childPaths = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void init_code() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}

bool isValid(int ci, int cj) {
    return ci >= 0 && ci < rows && cj >= 0 && cj < cols;
}

int cnt;

void dfs(int si, int sj) {
    visited[si][sj] = true;
    cnt++;
    for (int i = 0; i < 4; i++) {
        pii parent = childPaths[i];
        int ci = si + parent.first;
        int cj = sj + parent.second;
        if(isValid(ci, cj) && !visited[ci][cj] && adjMat[ci][cj] == '.') {
            dfs(ci, cj);
        }
    }
}

int main () {
    init_code();
    cin >> rows >> cols;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> adjMat[i][j];
        }
    }
    int minmm = INT_MAX;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if(!visited[i][j] && adjMat[i][j] == '.') {
                cnt = 0;
                dfs(i, j);
                minmm = min(cnt, minmm);
            }
        }
    }
    if(minmm == INT_MAX) {
        cout << -1;
    } else {
        cout << minmm;
    }
    return 0;
}
