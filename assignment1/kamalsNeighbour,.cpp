#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj[N];
bool visited[N];
int parentLevel[N];

void init_code() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}

void bfs(int s) {
    queue<int> q;
    q.push(s);
    visited[s] = true;
    parentLevel[s] = 0;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(auto v : adj[u]) {
            if(visited[v]) continue;
            q.push(v);
            parentLevel[v] = parentLevel[u] + 1;
            visited[v] = true;
        }
    }
}

int main () {
    init_code();
    int n, e;
    cin >> n >> e;
    for(int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int k;
    cin >> k;
    cout << adj[k].size();
    return 0;
}