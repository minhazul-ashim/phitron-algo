#include<bits/stdc++.h>
using namespace std;

void init_code() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}

const int N = 1e5 + 5;
vector<pair<int, int>> v[N];
bool visited[N]; // This is optional for more scopes of optimizing.
int dis[N];

void dijkstra(int s) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
    pq.push({0, s});
    dis[s] = 0;
    while(!pq.empty()) {
        pair<int, int> parent = pq.top();
        pq.pop();
        int parentNode = parent.second;
        // Optional for more optimization. It isn't necessary.
        // From here,
        // if(visited[parentNode]) {
        //     continue;
        // }
        // visited[parentNode] = true;
        // Until this.
        int parentCost = parent.first;
        for (int i = 0; i < v[parentNode].size(); i++) {
            pair<int, int> child = v[parentNode][i];
            int childNode = child.first;
            int childCost = child.second;
            if(parentCost + childCost < dis[childNode]) {
                dis[childNode] = parentCost + childCost;
                pq.push({dis[childNode], childNode});
            }
        }
    }
}

int main () {
    init_code();
    int n, e;
    cin >> n >> e;
    while(e--) {
        int a, b, w;
        cin >> a >> b >> w;
        v[a].push_back({b, w});
        v[b].push_back({a, w});
    }
    for (int i = 1; i <= n; i++) {
        dis[i] = INT_MAX;
    }

    dijkstra(1);

    for (int i = 1; i <= n; i++) {
        cout << "Node " << i << " : " << dis[i] << endl;
    }
     return 0;
}