#include <bits/stdc++.h>
using namespace std;
#define HNT  ios_base::sync_with_stdio(false);    cin.tie(0);

int MaxSub (int arr[], int n) {
    int smax = arr[0];
    int ei = arr[0];
    int imax = 0;

    for(int i = 1; i < n; i++) {
        ei = max(arr[i], arr[i] + ei);
        smax = max(smax, ei);
    }

    return smax;
}

int main() {
    HNT;
    int n;
    cin >> n;
    int a[n];

    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    cout << MaxSub(a, n);
    return 0;
}
