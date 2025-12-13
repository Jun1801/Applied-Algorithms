#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    ll a[n];
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ll r = INT_MAX;
    ll ans = 0;
    ll mid;
    ll l = 0;
    while(l <= r){
        mid = (l + r)>>1;
        ll sum = 0;
        for(int i = 0; i < n; i++){
            if(a[i] > mid) sum += a[i] - mid;
        }
        if(sum >= m){
            l = mid + 1;
            ans = mid;
        }
        else{
            r = mid - 1;
        }
    }
    cout << ans << "\n";
}
