#include<bits/stdc++.h>
using namespace std;

#define pii pair<int, int>

const int N = 1e3 + 5;
char adjMat[N][N];
bool visited[N][N];
int dis[N][N];
int rows, cols;
vector<pii> childPaths = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void init_code() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}

bool isIndexValid(int i, int j) {
    if (i >= 0 && i < rows && j >= 0 && j < cols) {
        return true;
    } else {
        return false;
    }
}

void bfs (int si, int sj) {
    queue<pii> q;
    q.push({si, sj});
    while(!q.empty()) {
        pii parent = q.front();
        q.pop();
        int pi = parent.first;
        int pj = parent.second;
        for (int i = 0; i < 4; i++) {
            pii child = childPaths[i];
            int ci = pi + child.first;
            int cj = pj + child.second;
            if(isIndexValid(ci, cj) && !visited[ci][cj]) {
                q.push({ci, cj});
                visited[ci][cj] = true;
                dis[ci][cj] = dis[pi][pj] + 1;
            }
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
    int si, sj;
    cin >> si >> sj;

    bfs(si, sj);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << dis[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}