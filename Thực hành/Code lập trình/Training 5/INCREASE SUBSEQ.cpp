#include <bits/stdc++.h>
using namespace std;
#define HNT  ios_base::sync_with_stdio(false);    cin.tie(0);

int lis( int arr[], int n){
    int lis[n];
    lis[0] = 1;

    for (int i = 1; i < n; i++){
    lis[i] = 1;
        for (int j = 0; j < i; j++ )
            if ( arr[i] > arr[j] && lis[i] < lis[j] + 1)
                lis[i] = lis[j] + 1;
    }

    return *max_element(lis, lis + n);
}

int main() {
    HNT;
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    cout << lis(a, n);
    return 0;
}
