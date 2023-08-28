#include<bits/stdc++.h>
using namespace std;

#define pii pair<int, int>

const int N = 1e3 + 5;
char adjMat[N][N];
bool visited[N][N];
int dis[N][N];
int rows, cols;
vector<pii> childPaths = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};

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
    memset(visited, false, sizeof(visited));
    memset(dis, 0, sizeof(dis));
    queue<pii> q;
    q.push({si, sj});
    while(!q.empty()) {
        pii parent = q.front();
        q.pop();
        int pi = parent.first;
        int pj = parent.second;
        for (int i = 0; i < 8; i++) {
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
    int t;
    cin >> t;
    while(t--) {
        cin >> rows >> cols;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                adjMat[i][j] = '.';
            }
        }
        int si, sj;
        cin >> si >> sj;
        int di, dj;
        cin >> di >> dj;
        bfs(si, sj);
        if (di == si && dj == sj) {
            cout << 0 << endl;
        } else if(dis[di][dj] != 0) {
            cout << dis[di][dj] << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}