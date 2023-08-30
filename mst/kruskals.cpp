#include<bits/stdc++.h>
using namespace std;

void init_code() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}

const int N = 1e5 + 5;
int parent[N];
int parentSize[N];

void set_dsu(int n) {
    for (int i = 1; i <= n; i++) {
        parent[i] = -1;
        parentSize[i]= 1;
    }
}

int dsu_find(int node) {
    while(parent[node] != -1) {
        node = parent[node];
    }
    return node;
}

void unionBySize(int a, int b) {
    int leaderA = dsu_find(a);
    int leaderB = dsu_find(b);

    if(leaderA != leaderB) {
        if(parentSize[leaderA] > parentSize[leaderB]) {
            parent[leaderB] = leaderA;
            parentSize[leaderA]+= parentSize[leaderB];
        } else {
            parent[leaderA] = leaderB;
            parentSize[leaderB]+= parentSize[leaderA];
        }
    }
}

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

bool cmp (Edge a, Edge b) {
    return a.w < b.w;
}

int main () {
    init_code();

    int n, e;
    cin >> n >> e;
    set_dsu(n);

    vector<Edge> edgeList;
    vector<Edge> resultEdges;

    while(e--) {
        int u, v, w;
        cin >> u >> v >> w;
        edgeList.push_back(Edge(u, v, w));
    }

    sort(edgeList.begin(), edgeList.end(), cmp);

    for(Edge edge : edgeList) {
        int u = edge.u;
        int v = edge.v;
        int w = edge.w;

        int leaderA = dsu_find(u);
        int leaderB = dsu_find(v);

        if(leaderA == leaderB) {
            cout << "Cycle Found between " << u << " and " << v << " so can't take this edge" << endl;
            continue;
        }
        resultEdges.push_back(edge);
        unionBySize(u, v);
    }

    cout << endl << endl;
    cout << "Now the Connected Edges of MST is below" << endl << endl;

    for(Edge val : resultEdges) {
        cout << val.u << " and " << val.v << " with cost " << val.w << endl;
    }
    return 0;
}