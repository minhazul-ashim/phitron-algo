#include<bits/stdc++.h>
using namespace std;

void init_code() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}

int main () {
    init_code();
    priority_queue <pair<int, int>, vector <pair<int, int>>, greater<pair<int, int>>> pq;
    int n;
    cin >> n;
    while(n--) {
        int a, b;
        cin >> a >> b;
        pq.push({a,b});
    }
    while(!pq.empty()) {
        pair<int, int> parent = pq.top();
        pq.pop();
        cout << parent.first << " " << parent.second << endl;
    }
    return 0;
}