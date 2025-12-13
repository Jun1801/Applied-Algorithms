#include <bits/stdc++.h>
using namespace std;
#define HNT  ios_base::sync_with_stdio(false);    cin.tie(0);
const int MOD = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    unsigned long long a[n];
    for (unsigned long long &i : a) cin >> i;
    unsigned long long ans = a[0];
    for (int i = 1; i < n; i++){
        ans = ((ans%MOD)*(a[i]%MOD))%MOD;
    }
    cout << ans << "\n";
}
