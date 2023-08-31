#include<bits/stdc++.h>
using namespace std;

void init_code() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}

class Edge {
    public:
        int a;
        int b;
        int w;
        Edge(int a, int b, int w)
        {
            this->a = a;
            this->b = b;
            this->w = w;
    }
};

int main () {
    init_code();
    int n, e;
    cin >> n >> e;
    vector<Edge> edList;
    int dis[n+1];
    for (int i = 1; i <= n; i++) {
        dis[i] = (i == 1) ? 0 : INT_MAX;
    }
    while (e--)
    {
        int a, b, w;
        cin >> a >> b >> w;
        Edge ed(a, b, w);
        edList.push_back(ed);
    }
    for(int i = 1; i <= n - 1; i++) {
        for (int j = 0; j < edList.size(); j++) {
            Edge ed = edList[j];
            int a = ed.a;
            int b = ed.b;
            int w = ed.w; 
            if(dis[a] + w < dis[b]) {
                dis[b] = dis[a] + w;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << "Node " << i << " Relaxed distance is " << dis[i] << endl;
    }
    return 0;
}