#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj[N];
bool visited[N];
int parentLevel[N] = {-1};

void bfs(int s) {
    memset(visited, false, sizeof(visited));
    memset(parentLevel, -1, sizeof(parentLevel));
    queue<int> q;
    q.push(s);
    visited[s] = true;
    parentLevel[s] = 0;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(int v : adj[u]) {
            if(visited[v])
                continue;
            q.push(v);
            visited[v] = true;
            parentLevel[v] = parentLevel[u] + 1;
        }
    }
}

int main () {
    // init_code();
    int n, e;
    cin >> n >> e;
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int query;
    cin >> query;
    while(query--) {
        int s, d;
        cin >> s >> d;
        bfs(s);
        if(s != d && parentLevel[d] == 0) {
            cout << -1 << endl;
        } else {
            cout << parentLevel[d] << endl;
        }
    }
    return 0;
}