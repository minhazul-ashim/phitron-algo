#include<bits/stdc++.h>
using namespace std;

#define pii pair<int, int>

const int N = 1e5 + 7;
vector<pii> adjList[N];
bool visited[N];

void init_code() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}

class Edge {
    public:
        int u, v, w;
        Edge(int a, int b, int w) {
            this->u = a;
            this->v = b;
            this->w = w;
        }
};

class cmp {
    public:
    bool operator()(Edge a, Edge b) {
            return a.w > b.w;
    }
};

void prims(int s) {

    priority_queue<Edge, vector<Edge>, cmp> pq;

    vector<Edge> edgeList;

    pq.push(Edge(s, s, 0));

    while(!pq.empty()) {
            Edge parent = pq.top();
            pq.pop();

            int u = parent.u;
            int v = parent.v;
            int w = parent.w;

            if(visited[v]) continue;

            visited[v] = true;
            edgeList.push_back(parent);

            for (int i = 0; i < adjList[v].size(); i++) {
                pii child = adjList[v][i];
                int node = child.first;
                int cost = child.second;
                
                if(!visited[node]) {
                    pq.push(Edge(v, node, cost));
                }
            }
    }
    for(Edge val : edgeList) {
                cout << val.u << " " << val.v << " " << val.w << endl;
    }
}

int main () {
    init_code();
    int n, e;
    cin >> n >> e;
    for (int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adjList[u].push_back({v, w});
        adjList[v].push_back({u, w});
    }
    prims(1);
    return 0;
}