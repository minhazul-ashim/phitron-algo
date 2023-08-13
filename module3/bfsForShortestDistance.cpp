#include<bits/stdc++.h>
using namespace std;

void init_code() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif //ONLINE JUDGE
}

const int N = 1e5 + 5;
vector<int> adj[N];
int level[N];
int visited[N];
int parent[N];

void bfs(int s) {
    queue<int> q;
    q.push(s);
    visited[s] = true;
    level[s] = 0;
    parent[s] = -1;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(int v : adj[u]) {
            if(visited[v]) continue;
            q.push(v);
            visited[v] = true;
            level[v] = level[u] + 1;
            parent[v] = u;
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
    int s, d;
    cin >> s >> d;
    bfs(s);
    cout << "Shortest distance from " << s << " to " << d << " is " << level[d] << endl;
    // for (int i = 1; i <= n; i++) {
    //     cout << "Parent of " << i << " is " << parent[i] << endl;
    // }
    vector<int> path;
    int current = d;

    while(parent[current] != -1) {
        path.push_back(current);
        current = parent[current];
    }

    reverse(path.begin(), path.end());
    cout << "Shortest Path from " << s << " to " << d << " is ";
    for(int x : path) {
        cout << x << " ";
    }
    return 0;
}