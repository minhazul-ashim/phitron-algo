#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
int arr[N];

void merge(int l, int mid, int r) {
    int laSize = mid - l + 1;
    int raSize = r - (mid + 1) + 1;

    int L[laSize + 1];
    int R[raSize + 1];

    for (int i = l, j = 0; i <= mid; i++, j++) {
        L[j] = arr[i];
    }

    for (int i = mid + 1, j = 0; i <= r; i++, j++) {
        R[j] = arr[i];
    }

    L[laSize] = INT_MAX;
    R[raSize] = INT_MAX;

    int lp = 0, rp = 0;

    for (int i = l; i <= r; i++) {
        if(L[lp] <= R[rp]) {
            arr[i] = L[lp];
            lp++;
        } else {
            arr[i] = R[rp];
            rp++;
        }
    }
}

void mergeSort(int l, int r)
{
    if(l == r) {
        return;
    }
    int mid = (l + r) / 2;

    mergeSort(l, mid);
    mergeSort(mid + 1, r);

    merge(l, mid, r);
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
    int n;
    inputFile >> n;
    for (int i = 0; i < n; i++) {
        int x;
        inputFile >> x;
        arr[i] = x;
    }
    mergeSort(0, n-1);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}