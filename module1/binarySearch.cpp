#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
int arr[N];

void binarySearch(int l, int r, int x) {
    int left = l;
    int right = r;
    while(left <= right) {
        int mid = (left + right) / 2;
        if(left == right && arr[mid] != x) {
            cout << "Not Found" << endl;
            break;
        } else if (arr[mid] == x)
        {
            cout << mid << endl;
            break;
        }
        else if (arr[mid] < x)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
}

int main () {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr[i] = x;
    }
    int x;
    cin >> x;

    binarySearch(0, n-1, x);

    return 0;
}