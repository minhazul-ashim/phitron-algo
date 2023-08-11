#include<bits/stdc++.h>
using namespace std;

void init_code() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}

const int N = 1e5 + 5;
vector<int> adj[N];
bool visited[N];
vector<int> ccp[N];

void dfs(int u, int c) {
    visited[u] = true;
    ccp[c].push_back(u);
    for(int v : adj[u]) {
        if(visited[v]) {
            continue;
        }
        dfs(v, c);
    }
}

int main () {
    init_code();
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int cc = 0;
    for (int i = 0; i < N; i++) {
        if(visited[i]) continue;
        cc++;
        dfs(i, cc);
    }
    vector<int> count;
    for (int i = 0; i < N; i++) {
        if(ccp[i].size() > 1) {
            count.push_back(ccp[i].size());
        }
    }
    sort(count.begin(), count.end());
    for(int v : count) {
        cout << v << " ";
    }
    return 0;
}