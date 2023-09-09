#include<bits/stdc++.h>
using namespace std;

void init_code() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}


bool subset_sum(int n, int a[], int s) {
    
    if(n == 0) {
        if(s == 0) {
            return true;
        } else {
            return false;
        }
    }

    if(a[n-1] <= s) {
        bool op1 = subset_sum(n-1, a , s-a[n-1]);
        bool op2 = subset_sum(n-1, a, s);
    } else {
        return subset_sum(n-1, a, s);
    }
}

int main () {
    init_code();
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int s;
    cin >> s;
    if(subset_sum(n, a, s)) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}