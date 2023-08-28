#include<bits/stdc++.h>
using namespace std;

#define pii pair<int, int>

const int N = 1e3 + 5;
char adjMat[N][N];
bool visited[N][N];
int rows, cols;
vector<pii> childPaths = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};


bool isIndexValid(int i, int j) {
    if (i >= 0 && i < rows && j >= 0 && j < cols) {
        return true;
    } else {
        return false;
    }
}

bool bfs (int si, int sj, int di, int dj) {
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
            int code = adjMat[ci][cj];

            if(code == 45) continue;

            if(ci == di && cj == dj) return true;
            
            if(isIndexValid(ci, cj) && !visited[ci][cj]) {
                q.push({ci, cj});
                visited[ci][cj] = true;
            }
        }
    }
    return false;
}

int main () {
    cin >> rows >> cols;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> adjMat[i][j];
        }
    }
    int si, sj;
    cin >> si >> sj;
    int di, dj;
    cin >> di >> dj;
    bool flag = bfs(si, sj, di, dj);
    if(flag) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}