#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj[N];
bool visited[N];

void dfs(int u) {
    // section 1
    // actions just after entering a node;
    visited[u] = true;
    cout << "Visiting Node " << u << endl;
    for(int v : adj[u]) {
        // section 2;
        //  actions before entering a new child or neighbour;
        if(visited[v]) {
            continue;
        }
        dfs(v);
        // section 3;
        // actions after exiting the child or neighbour;
    }
    // section 4;
    // actions before exiting node u;
}

int main () {
    fstream inputFile;
    fstream outputFile;
    inputFile.open("input.txt", ios::in);
    outputFile.open("output.txt", ios::out);
    if(!inputFile) {
        cout << "No Input File Found"<<endl;
        return 0;
    }
    int n, e;
    inputFile >> n >> e;
    for (int i = 0; i <= e; i++) {
        int u, v;
        inputFile >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // for (int i = 1; i <= n; i++) {
    //     outputFile << "List "<< i << " : ";
    //     for(int x : adj[i]) {
    //         outputFile << x << " ";
    //     }
    //     outputFile << endl;
    // }
    dfs(1);
    return 0;
}