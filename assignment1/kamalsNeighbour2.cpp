#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj[N];
bool visited[N];
int parentLevel[N];
int sum = 0;

void init_code() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}

void dfs(int u) {
    visited[u] = true;
    for(auto v : adj[u]) {
        if(visited[v]) continue;
        sum++;
        dfs(v);
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
    }
    int k;
    cin >> k;
    dfs(k);
    cout << sum;
    return 0;
}