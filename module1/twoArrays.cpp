#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
int leftArr[N];
const int M = 1e5 + 7;
int rightArr[M];

int * merge(int lSize, int rSize) {

    int *a = new int(lSize + rSize);

    int lp = 0, rp = 0, mp = 0;

    while(lp < lSize && rp < rSize) {
        if(leftArr[lp] <= rightArr[rp]) {
            a[mp] = rightArr[rp];
            rp++;
        } else {
            a[mp] = leftArr[lp];
            lp++;
        }
        mp++;
    }

    while(lp < lSize) {
        a[mp] = leftArr[lp];
        mp++;
        lp++;
    }

    while(rp < rSize) {
        a[mp] = rightArr[rp];
        mp++;
        rp++;
    }
    return a;
}

int main () {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        leftArr[i] = x;
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        rightArr[i] = x;
    }

    int * a = merge(n, m);

    for (int i = 0; i < (m+n); i++) {
        cout << a[i] << " ";
    }

    return 0;
}