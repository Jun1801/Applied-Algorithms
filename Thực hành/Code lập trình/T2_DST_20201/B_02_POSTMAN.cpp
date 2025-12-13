#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const int maxN = 1e3 + 7;
int n ;
ll k , ans = 0;
ii a[maxN];
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin >> n;
    cin >> k;
    for(int i = 1 ; i <= n ; i++) cin >> a[i].first >> a[i].second;
    sort(a + 1 , a + n + 1);

    while(a[n].first > 0)
    {
        if(a[n].second < 0)
        {
            if(a[n-1].first > 0) a[n-1].second += a[n].second;
            n-- ;
            continue;
        }
        ll T = a[n].second / k;
        ll buff = 0;
        if(T * k != a[n].second)
        {
            ++T;
            buff = k - a[n].second % k;
        }
        T = T * 2 * a[n].first;
        ans+= T;
        if(a[n-1].first > 0) {a[n-1].second -= buff; }
        n--;
    }
    int pos = 1;
    while(a[pos].first < 0)
    {
        if(a[pos].second < 0)
        {
            if(a[pos + 1].first < 0) a[pos + 1].second += a[pos].second;
            pos++;
            continue;
        }
        ll T = a[pos].second / k;
        ll buff = 0;
        if(T * k != a[pos].second)
        {
            ++T;
            buff = k - a[pos].second % k;
        }
        T = T * 2 * abs(a[pos].first);
        ans+= T;
        if(a[pos + 1].first < 0)
        {
            a[pos + 1].second -=buff;
        }
        pos++;
    }
    cout << ans;
    return 0;
}
