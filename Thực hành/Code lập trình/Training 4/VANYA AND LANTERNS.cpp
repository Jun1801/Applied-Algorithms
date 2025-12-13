#include<bits/stdc++.h>
using namespace std;
#define HNT ios_base::sync_with_stdio(false);    cin.tie(0); cout.tie(0);
const int N = 3e5 + 5;

typedef long long ll;
ll n, m, k;
ll a[N];
int f[N];
int cnt[N];

void solve(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a + n);
    ll res = 0;
    for(int i = 1; i < n; i++){
        res = max(res, a[i] - a[i - 1]);
    }
    res = max(res, a[0] * 2);
    res = max(res, (m - a[n - 1]) * 2);
    cout << 1.0 * res / 2 << '\n';
}

int main(){
    HNT
    cout << fixed << setprecision(10);
    //    freopen("input.txt", "r", stdin);
    //    freopen("output.txt", "w", stdout);
    int query = 1;
    //  cin >> query;
    //int start = 1000 * clock() / CLOCKS_PER_SEC;
    while(query--) solve();
    //cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC  - start << "ms\n";
}
