#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj[N];
bool visited[N];
int level[N];

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
    level[s] = 0;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(auto v : adj[u]) {
            if(visited[v]) continue;
            q.push(v);
            level[v] = level[u] + 1;
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
    bfs(0);
    int l;
    cin >> l;
    if(l == 0) {
        cout << 0 << endl;
        return 0;
    }
    vector<int> v;
    for (int i = 0; i < N; i++) {
        if(level[i] == l) {
            v.push_back(i);
        }
    }
    sort(v.begin(), v.end());
    if(v.size() == 0) {
        cout << -1;
        return 0;
    }
    for(int k : v) {
        cout << k << " ";
    }
    return 0;
}