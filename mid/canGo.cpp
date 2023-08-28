#include<bits/stdc++.h>
using namespace std;

#define pll pair<long long int, long long int>

void init_code() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}

const long long int N = 1e3 + 5;
vector<pair<long long int, long long int>> v[N];
bool visited[N];
long long int dis[N];

void dijkstra(int s) {
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({0, s});
    dis[s] = 0;
    while(!pq.empty()) {
        pll parent = pq.top();
        pq.pop();
        long long int parentNode = parent.second;
        if(visited[parentNode]) {
            continue;
        }
        visited[parentNode] = true;
        long long int parentCost = parent.first;
        for (long long int i = 0; i < v[parentNode].size(); i++) {
            pll child = v[parentNode][i];
            long long int childNode = child.first;
            long long int childCost = child.second;
            if(parentCost + childCost < dis[childNode]) {
                dis[childNode] = parentCost + childCost;
                pq.push({dis[childNode], childNode});
            }
        }
    }
}

int main () {
    init_code();
    long long int n, e;
    cin >> n >> e;
    while(e--) {
        int a, b, w;
        cin >> a >> b >> w;
        v[a].push_back({b, w});
        // v[b].push_back({a, w});
    }
    for (long long int i = 1; i <= n; i++) {
        dis[i] = INT_MAX;
    }
    long long int s;
    cin >> s;
    dijkstra(s);

    long long int t;
    cin >> t;

    while(t--) {
        long long int d, dw;
        cin >> d >> dw;
        if(dw >= dis[d]) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}