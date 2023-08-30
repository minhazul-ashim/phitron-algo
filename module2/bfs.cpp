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
int visited[N];
int parentLevel[N];

void bfs(int s) {
    queue<int> q;
    q.push(s);
    visited[s] = true;
    parentLevel[s] = 0;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        cout << "Visiting Node " << u << endl;
        for(int v : adj[u]) {
            if(visited[v]) continue;
            q.push(v);
            visited[v] = true;
            parentLevel[v] = parentLevel[u] + 1;
        }
    }
}

int main () {
    init_code();
    int n, e;
    cin >> n >> e;
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bfs(1);

    cout << endl;

    for (int i = 1; i <= n; i++) {
        cout << "Level of " << i << " is " << parentLevel[i] << endl;
    }
    return 0;
}