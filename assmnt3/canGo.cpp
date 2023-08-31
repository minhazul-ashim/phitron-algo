#include<bits/stdc++.h>
using namespace std;

class Edge {
    public:
    int u;
    int v;
    int w;
    Edge(int u, int v, int w) {
        this->u = u;
        this->v = v;
        this->w = w;    
    }
};

const int INF = 1e9;
const int N = 1e5 + 5;
vector<Edge> edges;
long long int dis[N];
int n, e;

void init_code() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}

void bellmanFord(int s) {
    for (int i = 1; i <= n; i++) {
        dis[i] = INF;
    }
    dis[s] = 0;
    for (int i = 1; i < n; i++) {
        for(Edge e : edges) {
            int u = e.u;
            int v = e.v;
            int w = e.w;
            if(dis[u] + w < dis[v]) {
                dis[v] = dis[u] + w;
            }
        }
    }
}

int main () {
    init_code();
    cin >> n >> e;
    while(e--) {
        int u, v, w;
        cin >> u >> v >> w;
        Edge edge(u, v, w);
        edges.push_back(edge);
    }
    int s;
    cin >> s;
    bellmanFord(s);
    for(Edge e : edges) {
        int u = e.u;
        int v = e.v;
        int w = e.w;
        if(dis[u] + w < dis[v]) {
            cout << "Negative Cycle Detected" << endl;
            return 0;
        }
    }
    int t;
    cin >> t;
    while(t--) {
        int d;
        cin >> d;
        if(dis[d] >= INF - 1000) {
            cout << "Not Possible" << endl;
        } else {
            cout << dis[d] << endl;
        }
    }
    return 0;
}